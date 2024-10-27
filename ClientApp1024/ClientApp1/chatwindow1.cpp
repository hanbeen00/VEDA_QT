//에어컨 관리 채팅방

#include "chatwindow1.h"
#include "ui_chatwindow1.h"

ChatWindow1::ChatWindow1(QString id, int channel, QWidget *parent):
    QWidget(parent),
    ui(new Ui::ChatWindow1), socket(new QTcpSocket(this)), id(id), channel(channel)
{
    ui->setupUi(this);
    setWindowTitle("Channel " + QString::number(channel));  // 채널 번호를 창 제목으로 설정
    connectToServer("127.0.0.1", 12345); // 채팅방과 서버 연결
    connect(socket, &QTcpSocket::readyRead, this, &ChatWindow1::readServerData); // 소켓을 이용해 서버로부터 메세지 수신

    airconditioner_Off();

    // 입장 시 메시지 전송
    QString enterMessage = "<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : " + QString::number(channel) + " : User has entered the chat.";
    sendMessage(enterMessage);  // 서버로 입장 메시지 전송
}

ChatWindow1::~ChatWindow1()
{
    delete ui;
}

void ChatWindow1::connectToServer(const QString &host, quint16 port) {    // 호스트(서버) ip와 포트 번호 이용해서 서버에 접속
    socket->connectToHost(host, port);                                   // 채팅방 소켓 이용해서 서버에 접속하기
    if (socket->waitForConnected()) {                                    // 접속 로그 출력
        qDebug() << "ChatWindow connected to server!";
    }
    else {
        qDebug() << "ChatWindow failed to connect to server!";
    }
}

void ChatWindow1::sendMessage(const QString &message) {                  // 채팅방에서 서버로 채팅 메세지 전송
    if (socket->state() == QAbstractSocket::ConnectedState) {           // 소켓이 서버에 연결된 상태라면
        socket->write(message.toUtf8());                                // string 변환해서 서버로 전송
        //qDebug() << "ChatWindow sent message:" << message;              // 전송 로그 출력
    }
    else {
        //qDebug() << "ChatWindow not connected to server!";
    }
}

void ChatWindow1::readServerData() {
    QByteArray data = socket->readAll();
    QString message = QString::fromUtf8(data);
    message.remove(QRegularExpression("<[^>]*>"));
    qDebug() << message;
    QStringList messageParts = message.split(":");

    if (messageParts.size() == 3) {
        QString senderId = messageParts[0];
        QString receivedChannel = messageParts[1];
        QString content = messageParts[2];

        if (receivedChannel.toInt() == channel) {
            QString formattedMessage = "<span style='font-weight:bold;color:rgb(0,0,255);'>" + senderId + "</span> : " + content;
            ui->messageDisplay->append(formattedMessage);  // UI에 메시지 추가

            if (content.contains("Airconditioning ON!")) {
                airconditioner_On();
            }
            else if (content.contains("Airconditioning OFF!")) {
                airconditioner_Off();
            }
            else if (content.contains("Temperature changed -> ")) {
                airconditioner_Control(content, "Temperature");
            }
            else if (content.contains("Wind Speed -> ")) {
                airconditioner_Control(content, "Wind");
            }
        }
    }
     if (messageParts.size() == 10) {                               // 채팅방에 입장하는 경우(서버에서 클라이언트로 상태 정보 보내줌)
                                                                    // ON:20:2:ON:2:10:OFF:20:0:10 이 형식으로
        QString airconditionerOn = messageParts[0];                 // 각각 파싱해서 ui 상태 초기화 시킴
        QString temperature = messageParts[1];
        QString windSpeed = messageParts[2];
        qDebug() << windSpeed;

        if (airconditionerOn.contains("ON")) {
            airconditioner_On();
        }
        else if (airconditionerOn.contains("OFF")) {
            airconditioner_Off();
        }

        ui->dial->blockSignals(true);       // 신호 차단 --> 차단 안하면 ui 바뀔때 메세지 전송도 같이 이루어짐
        ui->dial->setValue(temperature.toInt());
        ui->dial->blockSignals(false);      // 신호 재활성화

        ui->windBox->blockSignals(true);    // 신호 차단
        ui->windBox->setCurrentIndex(windSpeed.toInt()-2);
        ui->windBox->blockSignals(false);   // 신호 재활성화
    }
}

void ChatWindow1::airconditioner_On(){
    ui->dial->setEnabled(true);
    ui->airconON->setStyleSheet("background-color: rgb(255, 170, 127); color: black;");
    ui->airconOFF->setStyleSheet("");
    airconState = true;
    ui->windBox->setEnabled(true);
}

void ChatWindow1::airconditioner_Off(){
    ui->dial->setEnabled(false);
    ui->airconOFF->setStyleSheet("background-color: rgb(216, 213, 255); color: black;");
    ui->airconON->setStyleSheet("");
    airconState = false;
    ui->windBox->setEnabled(false);
}

void ChatWindow1::airconditioner_Control(QString &content, QString controlType) {
    QRegularExpression regex("\\d+");
    QRegularExpressionMatch match = regex.match(content);

    if (match.hasMatch()) {
        QString controlValue = match.captured(0); // 지역 변수 이름 변경
        if (controlType == "Temperature") {  // controlType으로 변경
            ui->dial->blockSignals(true);  // 신호 차단
            ui->dial->setValue(controlValue.toInt());
            ui->dial->blockSignals(false);  // 신호 재활성화
        } else {
            ui->windBox->blockSignals(true);  // 신호 차단
            ui->windBox->setCurrentIndex(controlValue.toInt()-1);
            ui->windBox->blockSignals(false);  // 신호 재활성화
        }
    }
}

void ChatWindow1::on_airconON_clicked()
{
    QString airconStateMessage = "<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : "+QString::number(channel) + " : Airconditioning ON!";
    sendMessage(airconStateMessage);  // 서버로 다이얼 값 전송
    airconditioner_On();
}


void ChatWindow1::on_airconOFF_clicked()
{
    QString airconStateMessage = "<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : "+QString::number(channel) + " : Airconditioning OFF!";
    sendMessage(airconStateMessage);  // 서버로 상태 전송
    airconditioner_Off();
}

void ChatWindow1::on_windBox_currentIndexChanged(int index)
{
    qDebug() << "SpinBox!";             // 수신 완료 로그
    QString airconWindMessage ="<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : "  + QString::number(channel) + " : Wind Speed -> " + QString::number(index+1)+ " level";
    sendMessage(airconWindMessage);  // 서버로 상태 전송
}

//에어컨 온도 조절 다이얼
void ChatWindow1::on_dial_valueChanged(int value)
{
    if (!airconState) {  // 에어컨이 꺼진 상태라면
        qDebug() << "Airconditioning is OFF. Dial cannot be changed.";
        return;
    }
    // 다이얼 값이 변경되면 서버로 메시지 전송
    QString dialMessage = "<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : "  + QString::number(channel) + " : Temperature changed -> " + QString::number(value)+ "℃";
    sendMessage(dialMessage);  // 서버로 다이얼 값 전송
}

//메시지 전송 버튼이 눌러지면
void ChatWindow1::on_sendButton_clicked()
{
    if (ui->messageInput->text().isEmpty()) {                           // 메시지가 비어 있는지 확인
        qDebug() << "Message input is empty. Not sending.";         // 로그 출력
        return;                                                     // 비어 있을 경우 전송 x
    }
    sendMessage("<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : " + QString::number(channel) + " : "  + ui->messageInput->text());
    ui->messageInput->clear();                                          // 메세지 입력창 초기화
}

void ChatWindow1::on_exitButton_clicked()
{
    QString exitMessage = "<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : " + QString::number(channel) + " : User has left the chat.";
    sendMessage(exitMessage);   // 서버로 퇴장 메시지 전송
    this->close();
}
