//TV 관리 채팅방

#include "chatwindow2.h"
#include "ui_chatwindow2.h"

ChatWindow2::ChatWindow2(QString id, int channel, QWidget *parent):
        QWidget(parent),
        ui(new Ui::ChatWindow2), socket(new QTcpSocket(this)), id(id), channel(channel)
{
    ui->setupUi(this);
    connectToServer("127.0.0.1", 12345); // 채팅방과 서버 연결
    connect(socket, &QTcpSocket::readyRead, this, &ChatWindow2::readServerData); // 소켓을 이용해 서버로부터 메세지 수신
    tv_Off();

    // 입장 시 메시지 전송
    QString enterMessage = "<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : " + QString::number(channel) + " : User has entered the chat.";
    sendMessage(enterMessage);  // 서버로 입장 메시지 전송
}

ChatWindow2::~ChatWindow2()
{
    delete ui;
}

void ChatWindow2::on_sendButton_clicked()
{
    if (ui->messageInput->text().isEmpty()) {                           // 메시지가 비어 있는지 확인
        qDebug() << "Message input is empty. Not sending.";         // 로그 출력
        return;                                                     // 비어 있을 경우 전송 x
    }
    sendMessage("<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : " + QString::number(channel) + " : "  + ui->messageInput->text());
    ui->messageInput->clear();                                          // 메세지 입력창 초기화
}

void ChatWindow2::connectToServer(const QString &host, quint16 port) {    // 호스트(서버) ip와 포트 번호 이용해서 서버에 접속
    socket->connectToHost(host, port);                                   // 채팅방 소켓 이용해서 서버에 접속하기
    if (socket->waitForConnected()) {                                    // 접속 로그 출력
        qDebug() << "ChatWindow connected to server!";
    }
    else {
        qDebug() << "ChatWindow failed to connect to server!";
    }
}

void ChatWindow2::sendMessage(const QString &message) {                  // 채팅방에서 서버로 채팅 메세지 전송
    if (socket->state() == QAbstractSocket::ConnectedState) {           // 소켓이 서버에 연결된 상태라면
        socket->write(message.toUtf8());                                // string 변환해서 서버로 전송
        qDebug() << "ChatWindow sent message:" << message;              // 전송 로그 출력
    }
    else {
        qDebug() << "ChatWindow not connected to server!";
    }
}

void ChatWindow2::readServerData() {                                     // 서버로부터 메세지 수신
    QByteArray data = socket->readAll();                                // 소켓 통해서 서버에서 보낸 데이터 읽기
    qDebug() << "ChatWindow received from server:" << data;             // 수신 완료 로그
    QString message = QString::fromUtf8(data);
    message.remove(QRegularExpression("<[^>]*>"));
    qDebug() << message;
    QStringList messageParts = message.split(":");        // 수신 데이터를 QString으로 변환

    if (messageParts.size() == 3) {                                     // 메시지 형식이 올바른지 확인
        QString senderId = messageParts[0];                             // 발신자 ID
        QString receivedChannel = messageParts[1];                  // 송신한 채널 번호
        QString content = messageParts[2];                              // 송신한 메시지 내용

        if (receivedChannel.toInt() == channel) {
            QString formattedMessage = "<span style='font-weight:bold;color:rgb(0,0,255);'>" + senderId + "</span> : " + content;
            ui->messageDisplay->append(formattedMessage);  // UI에 메시지 추가

            if (content.contains("ON!")) {
                tv_On();
            }
            else if (content.contains("OFF!")) {
                tv_Off();
            }
            else if (content.contains("Platform -> ")) {
                tv_Control(content, "Platform");
            }
            else if (content.contains("Sound Level -> ")) {
                tv_Control(content, "Sound");
            }
        }
    }

    if (messageParts.size() == 10) {
        QString tvOn = messageParts[3];
        QString tvChannel = messageParts[4];
        QString tvSound = messageParts[5];
        if (tvOn.contains("ON")) {
            tv_On();
        }
        else if (tvOn.contains("OFF")) {
            tv_Off();
        }
        ui->channelBox->blockSignals(true);  // 신호 차단
        ui->channelBox->setPrefix(platformList[tvChannel.toInt()] + " ");
        ui->channelBox->setValue(tvChannel.toInt());
        ui->channelBox->blockSignals(false);  // 신호 재활성화

        ui->soundSlider->blockSignals(true);  // 신호 차단
        ui->soundSlider->setSliderPosition(tvSound.toInt());
        ui->soundSlider->blockSignals(false);  // 신호 재활성화
    }
}

void ChatWindow2::tv_On(){
    tvState=true; // tv 켜짐
    ui->tvDisplay->setStyleSheet("background-color: transparent; border:none;");
    ui->channelBox->setEnabled(true);
    ui->soundSlider->setEnabled(true);
    ui->tvonButton->setStyleSheet("background-color: rgb(255, 170, 127); color: black;");
    ui->tvoffButton->setStyleSheet("");  // OFF 버튼 색상 초기화
}

void ChatWindow2::tv_Off(){
    tvState=false; // tv 켜짐
    ui->tvDisplay->setStyleSheet("background-color: rgba(120, 120, 120,0.5);border:none;");
    ui->channelBox->setEnabled(false); // 채널조작 불가능하게 설정
    ui->soundSlider->setEnabled(false); //사운드 조절 불가능하게 설정
    ui->tvoffButton->setStyleSheet("background-color: rgb(216, 213, 255); color: black;");
    ui->tvonButton->setStyleSheet("");  // ON 버튼 색상 초기화
}

void ChatWindow2::tv_Control(QString &content, QString control){
    QRegularExpression regex("\\d+");
    QRegularExpressionMatch match = regex.match(content);
    if (match.hasMatch()) {
        QString controlValue = match.captured(0); // 지역 변수 이름 변경
        if(control == "Platform"){
            ui->channelBox->blockSignals(true);  // 신호 차단
            ui->channelBox->setPrefix(platformList[controlValue.toInt()] + " ");
            ui->channelBox->setValue(controlValue.toInt());
            ui->channelBox->blockSignals(false);  // 신호 재활성화
        }
        else{
            ui->soundSlider->blockSignals(true);  // 신호 차단
            ui->soundSlider->setSliderPosition(controlValue.toInt());
            ui->soundSlider->blockSignals(false);  // 신호 재활성화
        }
    }
}

void ChatWindow2::on_exitButton_clicked()
{
    QString exitMessage = "<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : " + QString::number(channel) + " : User has left the chat.";
    sendMessage(exitMessage);   // 서버로 퇴장 메시지 전송
    this->close();
}

void ChatWindow2::on_channelBox_valueChanged(int value)
{

    // 값이 범위 내에 있는지 확인
    if (value >= 0 && value < platformList.size())
    {
        // SpinBox의 값을 플랫폼 이름으로 변경
        ui->channelBox->setPrefix(platformList[value] + " ");  // 플랫폼 이름을 SpinBox에 표시
        ui->channelBox->setValue(value);
        qDebug() << "Platform changed to:" << platformList[value];
        QString platformMessage= "<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : "+ QString::number(channel) + " : Platform -> " + QString(platformList[value] + " " + QString::number(value) );
        sendMessage(platformMessage);
    }
}

void ChatWindow2::on_soundSlider_sliderMoved(int position)
{
    qDebug() << "Sound changed!! : " <<position;
    QString soundMessage = "<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : "+ QString::number(channel) + " : Sound Level -> " + QString::number(position);
    sendMessage(soundMessage);  // 서버로 상태 전송
}

void ChatWindow2::on_tvonButton_clicked()
{
    QString tvStateMessage = "<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : "+QString::number(channel) + " : Tv ON!";
    sendMessage(tvStateMessage);  // 서버로 다이얼 값 전송
    tv_On();

}

void ChatWindow2::on_tvoffButton_clicked()
{
    QString tvStateMessage = "<span style='font-weight:bold;color:rgb(0,0,255);'>" + id + "</span> : "+QString::number(channel) + " : Tv OFF!";
    sendMessage(tvStateMessage);  // 서버로 다이얼 값 전송
    tv_Off();
}

