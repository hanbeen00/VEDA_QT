#ifndef CHATWINDOW2_H
#define CHATWINDOW2_H

#include <QWidget>
#include <QTcpSocket>
#include <QStringList>
#include <QFrame>
#include <QRegularExpression>

namespace Ui {
class ChatWindow2;
}

class ChatWindow2 : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWindow2(QString id, int channel, QWidget *parent = nullptr);
    ~ChatWindow2();
    void connectToServer(const QString &host, quint16 port);                    // 채팅방과 서버 연결
    void sendMessage(const QString &message);                                   // 채팅방에서 서버로 메세지 전송

private slots:
    void readServerData();   // 서버에서 송신한 메세지 수신하기
    void on_sendButton_clicked();
    void on_exitButton_clicked();
    void on_channelBox_valueChanged(int arg1);
    void on_soundSlider_sliderMoved(int position);
    void on_tvonButton_clicked();
    void on_tvoffButton_clicked();


private:
    Ui::ChatWindow2 *ui;
    QTcpSocket *socket;                     // 채팅창 소켓
    QString id;                             // 채팅방 사용자 아이디
    int channel;                            // 채팅방 채널(1,2,3)
    bool tvState;                            // 에어컨이 상태로 시작
    QStringList platformList = {"Netflix", "Youtube", "Tiving", "TikTok", "Coupang"};

    void tv_On();
    void tv_Off();
    void tv_Control(QString &content, QString control);

};

#endif // CHATWINDOW2_H
