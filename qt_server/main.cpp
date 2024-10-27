#include <QCoreApplication>
#include "Server.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Server server;                                              // 서버 객체 생성
    if (server.listen(QHostAddress::Any, 12345)) {              // 서버의 12345 포트로 접속하는 클라이언트 listen
        qDebug() << "Server is listening on port 12345.";
    }
    else {
        qDebug() << "Server failed to start.";
        return -1;
    }

    return a.exec();
}
