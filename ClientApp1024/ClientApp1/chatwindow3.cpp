//창문 관리 채팅방

#include "chatwindow3.h"
#include "ui_chatwindow3.h"

ChatWindow3::ChatWindow3(QString id, int channel, QWidget *parent):
    QWidget(parent),
    ui(new Ui::ChatWindow3), socket(new QTcpSocket(this)), id(id), channel(channel)
{
    ui->setupUi(this);
    connectToServer("127.0.0.1", 12345); // 채팅방과 서버 연결
    connect(socket, &QTcpSocket::readyRead, this, &ChatWindow3::readServerData); // 소켓을 이용해 서버로부터 메세지 수신
    window_Off();

    // 입장 시 메시지 전송
    QString enterMessage = "<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : " + QString::number(channel) + " : User has entered the chat.";
    sendMessage(enterMessage);  // 서버로 입장 메시지 전송
}

ChatWindow3::~ChatWindow3()
{
    delete ui;
}
void ChatWindow3::on_sendButton_clicked()
{
    if (ui->messageInput->text().isEmpty()) {                           // 메시지가 비어 있는지 확인
        qDebug() << "Message input is empty. Not sending.";         // 로그 출력
        return;                                                     // 비어 있을 경우 전송 x
    }
    sendMessage("<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : " + QString::number(channel) + " : "  + ui->messageInput->text());
    ui->messageInput->clear();                                          // 메세지 입력창 초기화
}

void ChatWindow3::connectToServer(const QString &host, quint16 port) {    // 호스트(서버) ip와 포트 번호 이용해서 서버에 접속
    socket->connectToHost(host, port);                                   // 채팅방 소켓 이용해서 서버에 접속하기
    if (socket->waitForConnected()) {                                    // 접속 로그 출력
        qDebug() << "ChatWindow connected to server!";
    }
    else {
        qDebug() << "ChatWindow failed to connect to server!";
    }
}

void ChatWindow3::sendMessage(const QString &message) {                  // 채팅방에서 서버로 채팅 메세지 전송
    if (socket->state() == QAbstractSocket::ConnectedState) {           // 소켓이 서버에 연결된 상태라면
        socket->write(message.toUtf8());                                // string 변환해서 서버로 전송
        qDebug() << "ChatWindow sent message:" << message;              // 전송 로그 출력
    }
    else {
        qDebug() << "ChatWindow not connected to server!";
    }
}

void ChatWindow3::readServerData() {                                     // 서버로부터 메세지 수신
    QByteArray data = socket->readAll();                                // 소켓 통해서 서버에서 보낸 데이터 읽기
    qDebug() << "ChatWindow received from server:" << data;             // 수신 완료 로그
    QString message = QString::fromUtf8(data);                          // 수신 데이터를 QString으로 변환
    message.remove(QRegularExpression("<[^>]*>"));
    qDebug() << message;
    QStringList messageParts = message.split(":");                    // 메시지를 ":"로 분리하여 채널 정보 확인


    if (messageParts.size() == 3) {                                     // 메시지 형식이 올바른지 확인
        QString senderId = messageParts[0];                             // 발신자 ID
        QString receivedChannel = messageParts[1];                  // 송신한 채널 번호
        QString content = messageParts[2];                              // 송신한 메시지 내용

        if (receivedChannel.toInt() == channel) {                                   // 송신자 채널과 수신자 채널이 같은 경우에만 출력
            QString formattedMessage = "<span style='font-weight:bold;color:rgb(0,0,255);'>" + senderId + "</span> : " + content;
            ui->messageDisplay->append(formattedMessage);  // UI에 메시지 추가

            if (content.contains("OPEN")) {
                window_On();
            }
            else if (content.contains("CLOSE")) {
                window_Off();
            }
            else if (content.contains("'LivingRoom' window -> ")) {
                window_Control(content, "LivingRoom");
            }
            else if (content.contains("'BedRoom' window -> ")) {
                window_Control(content, "BedRoom");
            }
            else if (content.contains("'BathRoom' window -> ")){
                window_Control(content, "BathRoom");
            }
        }
    }

    if (messageParts.size() == 10) {
        QString windowOpenOrClose = messageParts[6];
        QString window1Slide = messageParts[7];
        QString window2Slide = messageParts[8];
        QString window3Slide = messageParts[9];

        if (windowOpenOrClose.contains("ON")) {
            window_On();
        }
        else if (windowOpenOrClose.contains("OFF")) {
            window_Off();
        }
        ui->room1Slider->blockSignals(true);  // 신호 차단
        ui->room1Slider->setValue(window1Slide.toInt());
        ui->room1Slider->blockSignals(false);  // 신호 재활성화

        ui->room2Slider->blockSignals(true);  // 신호 차단
        ui->room2Slider->setValue(window2Slide.toInt());
        ui->room2Slider->blockSignals(false);  // 신호 재활성화

        ui->room3Slider->blockSignals(true);  // 신호 차단
        ui->room3Slider->setValue(window3Slide.toInt());
        ui->room3Slider->blockSignals(false);  // 신호 재활성화
    }
}

void ChatWindow3::window_On(){
    windowState = true;
    ui->windowOpenButton->setStyleSheet("background-color: rgb(255, 170, 127); color: black;");
    ui->windowCloseButton->setStyleSheet("");
    ui->room1Slider->setValue(100);
    ui->room2Slider->setValue(100);
    ui->room3Slider->setValue(100);
}
void ChatWindow3::window_Off(){
    windowState = false;
    ui->windowCloseButton->setStyleSheet("background-color: rgb(216, 213, 255); color: black;");
    ui->windowOpenButton->setStyleSheet("");
    ui->room1Slider->setValue(0);
    ui->room2Slider->setValue(0);
    ui->room3Slider->setValue(0);
}
void ChatWindow3::window_Control(QString &content, QString control){
    QRegularExpression regex("\\d+");
    QRegularExpressionMatch match = regex.match(content);

    if (match.hasMatch()) {
        QString slide = match.captured(0);
        if(control == "LivingRoom"){
            ui->room1Slider->blockSignals(true);  // 신호 차단
            ui->room1Slider->setValue(slide.toInt());
            ui->room1Slider->blockSignals(false);  // 신호 재활성화
        }
        else if(control == "BedRoom"){
            ui->room2Slider->blockSignals(true);  // 신호 차단
            ui->room2Slider->setValue(slide.toInt());
            ui->room2Slider->blockSignals(false);  // 신호 재활성화
        }
        else{
            ui->room3Slider->blockSignals(true);  // 신호 차단
            ui->room3Slider->setValue(slide.toInt());
            ui->room3Slider->blockSignals(false);  // 신호 재활성화s
        }
    }
}

void ChatWindow3::on_exitButton_clicked()
{
    QString exitMessage = "<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : " + QString::number(channel) + " : User has left the chat.";
    sendMessage(exitMessage);   // 서버로 퇴장 메시지 전송
    this->close();
}

void ChatWindow3::on_windowOpenButton_clicked()
{

    QString windowStateMessage = "<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : "+QString::number(channel) + " : Window ALL OPEN!";
    sendMessage(windowStateMessage);
    window_On();
}


void ChatWindow3::on_windowCloseButton_clicked()
{
    QString windowStateMessage ="<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : "+QString::number(channel) + " : Window ALL CLOSE!";
    sendMessage(windowStateMessage);
    window_Off();
}

void ChatWindow3::on_room1Slider_sliderMoved(int position)
{
    QString windowStateMessage= "<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : "+ QString::number(channel) + " : 'LivingRoom' window -> " + QString::number(position)+"% open";
    sendMessage(windowStateMessage);
}

void ChatWindow3::on_room2Slider_sliderMoved(int position)
{
    QString windowStateMessage= "<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : " + QString::number(channel) + " : 'BedRoom' window -> " + QString::number(position)+"% open";
    sendMessage(windowStateMessage);
}

void ChatWindow3::on_room3Slider_sliderMoved(int position)
{
    QString windowStateMessage= "<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : " + QString::number(channel) + " : 'BathRoom' window -> " + QString::number(position)+"% open";
    sendMessage(windowStateMessage);
}

