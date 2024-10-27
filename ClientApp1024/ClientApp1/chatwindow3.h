//창문 관리 채팅방

#ifndef CHATWINDOW3_H
#define CHATWINDOW3_H

#include <QWidget>
#include <QTcpSocket>
#include <QRegularExpression>

namespace Ui {
class ChatWindow3;
}

class ChatWindow3 : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWindow3(QString id, int channel, QWidget *parent = nullptr);
    ~ChatWindow3();
    void connectToServer(const QString &host, quint16 port);                    // 채팅방과 서버 연결
    void sendMessage(const QString &message);                                   // 채팅방에서 서버로 메세지 전송

private slots:
    void readServerData();   // 서버에서 송신한 메세지 수신하기
    void on_sendButton_clicked();
    void on_exitButton_clicked();
    void on_windowOpenButton_clicked();
    void on_windowCloseButton_clicked();
    void on_room1Slider_sliderMoved(int position);
    void on_room2Slider_sliderMoved(int position);
    void on_room3Slider_sliderMoved(int position);

private:
    Ui::ChatWindow3 *ui;
    QTcpSocket *socket;                     // 채팅창 소켓
    QString id;                             // 채팅방 사용자 아이디
    int channel;                            // 채팅방 채널(1,2,3)
    bool windowState;  // 창문이 모두 닫힌 상태로 시작

    void window_On();
    void window_Off();
    void window_Control(QString &content, QString control);
};

#endif // CHATWINDOW3_H
