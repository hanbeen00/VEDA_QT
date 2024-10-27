#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>
#include <QVector>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMutex>
#include <QRegularExpression>
#include <QDateTime>

// ClientHandler 클래스: 클라이언트와의 연결을 처리하기 위한 스레드
class ClientHandler : public QThread {
    Q_OBJECT

public:
    ClientHandler(qintptr socketDescriptor, QObject *parent = nullptr);
    void run() override;                        // 스레드 실행 메서드
    void sendMessage(const QString &message);   // 클라이언트에게 메시지를 전송하는 메서드

signals:
    void messageReceived(const QString &message);   // 클라이언트로부터 메시지 수신 시그널 정의
    void clientDisconnected();

private slots:
    void readMessage();     // 클라이언트로부터 메시지를 수신 후 처리
    void handleDisconnected();

private:
    QTcpSocket *socket;     // 클라이언트와의 연결을 위한 소켓
};


// Server 클래스: 클라이언트 연결을 관리하는 TCP 서버
class Server : public QTcpServer {
    Q_OBJECT

public:
    explicit Server(QObject *parent = nullptr);

protected:
    void incomingConnection(qintptr socketDescriptor) override;     // 새로운 클라이언트의 연결 요청을 처리하는 메서드

private:
    QVector<ClientHandler*> clients;   // 클라이언트 핸들러 객체(스레드)를 저장
    ClientHandler *clientHandler;      // 클라이언트 핸들러(스레드)
    QSqlDatabase db;  // 데이터베이스 객체s

    QSqlQuery login_Query;                                                // 로그인 테이블 처리할 쿼리
    QSqlQuery message_Query;                                              // 메세지 테이블 처리할 쿼리

    void initDatabase();  // 데이터베이스 초기화 메서드
    void saveMessageToDatabase(const QString &message);  // 메시지를 데이터베이스에 저장하는 메서드
    QString homeState();


    QString removeHtmlTags(const QString &message);

    // 메시지 타입별 처리 함수
    void processLoginMessage(const QString &message);
    void processControlMessage(const QString &message);

    // 장치 상태 업데이트 함수
    void updateAirConditionerState(const QString &msg, const QRegularExpressionMatch &match);
    void updateTVState(const QString &msg, const QRegularExpressionMatch &match);
    void updateWindowState(const QString &msg, const QRegularExpressionMatch &match);

    // 데이터베이스 저장 함수
    bool saveToDatabase(const QString &tableName, const QMap<QString, QVariant> &data);


    bool airconState = false;
    int airconTemperature = 18;
    int airWindLevel = 0;

    bool tvState = false;
    int tvChannel = 0;
    int tvSound = 0;

    bool windowState = false;
    int livingroomSlide = 0;
    int bedroomSlide = 0;
    int bathroomSlide = 0;
};

#endif // SERVER_H
