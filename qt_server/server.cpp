#include "Server.h"

// ClientHandler 클래스 생성자
// 소켓 디스크립터를 사용하여 클라이언트와의 통신을 관리하는 QTcpSocket을 생성하고,
// readyRead와 disconnected 시그널을 처리할 슬롯을 연결
ClientHandler::ClientHandler(qintptr socketDescriptor, QObject *parent)
    : QThread(parent) {
    qDebug()<<"connected2";
    socket = new QTcpSocket();                                                   // 새로운 QTcpSocket 객체 생성
    socket->setSocketDescriptor(socketDescriptor);                               // 전달받은 소켓 디스크립터로 소켓 초기화
    connect(socket, &QTcpSocket::readyRead, this, &ClientHandler::readMessage);  // 데이터를 읽을 준비가 되면 readMessage 호출
    connect(socket, &QTcpSocket::disconnected, this, &ClientHandler::handleDisconnected); // disconnected 시그널에 슬롯 연결
}

// 소켓이 끊어졌을 때 호출되는 슬롯
void ClientHandler::handleDisconnected() {
    emit clientDisconnected(); // 연결 종료 시그널 발행
    this->deleteLater(); // 핸들러 삭제
}

// run 메서드: 스레드를 실행시키기 위한 메서드, exec() 호출하여 이벤트 루프 실행
void ClientHandler::run() {
    exec(); // 스레드 실행, 이벤트 루프 대기
}

void ClientHandler::readMessage() {                     // 클라이언트로부터 받은 메시지를 처리
    QByteArray data = socket->readAll();                // 클라이언트로부터 들어온 모든 데이터를 읽음
    QString message = QString::fromUtf8(data);          // 데이터를 문자열로 변환

    QString plainMessage = message;
    //plainMessage.remove(QRegExp("<[^>]*>"));          // **** 시현님 버전 ***** //
    plainMessage.remove(QRegularExpression("<[^>]*>")); // **** 제 버전에서는 이 함수로 작동돼요 ***** //
    qDebug() << "Received message:" << plainMessage;    // 받은 메시지 로그 출력


    emit messageReceived(message);                      // messageReceived 시그널을 발생시켜 서버에 메시지 전달 (브로드 캐스트 시그널임)
}

void ClientHandler::sendMessage(const QString &message) {   // 클라이언트에게 메시지를 전송하는 함수
    if (socket) {                                           // 소켓이 유효할 경우
        socket->write(message.toUtf8());                    // 메시지를 UTF-8 형식으로 변환하여 소켓에 쓰기
    }
}


Server::Server(QObject *parent) : QTcpServer(parent) { // Server 클래스 생성자
    initDatabase();                                    // 데이터베이스 초기화
}

void Server::incomingConnection(qintptr socketDescriptor) { // 새로운 클라이언트의 접속 요청을 처리 (소켓 연결 수락)
    qDebug() << "connected1";

    ClientHandler *clientHandler = new ClientHandler(socketDescriptor);    // 클라이언트의 소켓 디스크립터를 사용하여 ClientHandler(스레드) 생성
    clients.append(clientHandler);                          // 생성된 클라이언트 핸들러를 clients 리스트에 추가
    qDebug() << clients;

    // 클라이언트에게 현재 home 상태 메시지 전송
    clientHandler->sendMessage(homeState());

    // 클라이언트로부터 메시지를 받으면 이를 다른 모든 클라이언트에게 브로드캐스트
    connect(clientHandler, &ClientHandler::messageReceived, [this](const QString &message) {
        saveMessageToDatabase(message);             // 받은 메시지를 데이터베이스에 저장
        for (ClientHandler *client : clients) {     // 모든 클라이언트에 대해 반복하면서, 각 클라이언트로 메시지를 전송
            client->sendMessage(message);           // 클라이언트에게 메시지 전송
        }
    });

    // 클라이언트 연결 종료 시 해당 클라이언트를 clients 리스트에서 제거
    connect(clientHandler, &ClientHandler::clientDisconnected, [this, clientHandler]() {
        clients.removeOne(clientHandler);
        clientHandler->quit(); // 스레드 종료
        clientHandler->wait(); // 스레드가 종료될 때까지 대기
        qDebug() << "Client disconnected and removed from clients list.";
    });

    clientHandler->start(); // 클라이언트 핸들러 스레드를 시작
}

QString Server::homeState(){                                                // smarthome 전체 상태 저장 메소드

    QString state="";                                                       // 상태 저장할 state 변수
    ///////////////////////////         채팅방 1           /////////////////////////////////////////
    if(airconState == true){                                                // 에어컨 ON 상태일 경우
        state= state + "ON:";
    }
    else{                                                                   // 에어컨 OFF 상태일 경우
        state= state + "OFF:";
    }
    state= state + QString::number(airconTemperature) + ":";                // 에어컨 온도
    state= state + QString::number(airWindLevel+1) + ":";                   // 에어컨 바람세기
    ////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////         채팅방 2           /////////////////////////////////////////
    if(tvState == true){                                                    // TV ON 상태일 경우
        state= state + "ON:";
    }
    else{                                                                   // TV OFF 상태일 경우
        state= state + "OFF:";
    }
    state= state + QString::number(tvChannel) + ":";                        // TV 채널
    state= state + QString::number(tvSound) + ":";                          // TV 사운드
    ////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////         채팅방 3           /////////////////////////////////////////
    if(windowState == true){
        state= state + "ON:";
    }
    else{
        state= state + "OFF:";
    }
    state= state + QString::number(livingroomSlide) + ":";
    state= state + QString::number(bedroomSlide) + ":";
    state= state + QString::number(bathroomSlide);
    ////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///
    return state;    // 상태 결과 모습 -- > ex) ON:20:2:ON:2:10:OFF:20:0:10
}

void Server::initDatabase() {                               // 데이터베이스 초기화
    db = QSqlDatabase::addDatabase("QSQLITE");              // SQLite 데이터베이스 사용
    db.setDatabaseName("project.db");                       // 데이터베이스 파일 이름 설정 (build 폴더에 저장되어 있음)

    if (!db.open()) {
        qDebug() << "Error: Unable to open database." << db.lastError().text();
        return;                                             // 데이터베이스가 열리지 않으면 종료
    }

    else {
        QSqlQuery login;                                                // 로그인 테이블 처리할 쿼리
        QSqlQuery message;                                              // 메세지 테이블 처리할 쿼리
        if (!login.exec("CREATE TABLE IF NOT EXISTS logins ("           // 로그인 정보를 저장하기 위한 테이블 생성
                        "id TEXT NOT NULL,"                             // 테이블 정보 ( id, pw )
                        "pw TEXT NOT NULL,"
                        "time TEXT NOT NULL"
                        ")")) {
            qDebug() << "Error creating logins table:" << login.lastError().text();
        }

        if (!message.exec("CREATE TABLE IF NOT EXISTS messages ("       // 메시지 저장을 위한 테이블 생성
                        "id TEXT NOT NULL,"                             // 테이블 정보 ( id, channel, chat )
                        "channel TEXT NOT NULL,"
                        "chat TEXT NOT NULL,"
                        "time TEXT NOT NULL"
                        ")")) {
            qDebug() << "Error creating messages table:" << message.lastError().text();
        }
        qDebug() << "Database initialized successfully.";
    }
}

void Server::saveMessageToDatabase(const QString &message) {
    QString plainMessage = removeHtmlTags(message);

    if (plainMessage.startsWith("login : ")) {
        processLoginMessage(plainMessage);
    }
    else {
        processControlMessage(plainMessage);
    }
}

QString Server::removeHtmlTags(const QString &message) {
    QString plainMessage = message;
    plainMessage.remove(QRegularExpression("<[^>]*>"));
    return plainMessage;
}

void Server::processLoginMessage(const QString &message) {
    QStringList parts = message.split('/');
    if (parts.size() == 2) {
        QString id = parts[0].split("=").last().trimmed();
        QString pw = parts[1].split("=").last().trimmed();
        QDateTime time = QDateTime::currentDateTime();

        if (!saveToDatabase("logins", { {":id", id}, {":pw", pw}, {":time", time}})) {
            qDebug() << "Error: Unable to save login message to database.";
        } else {
            qDebug() << "Saved login data to logins table";
        }
    }
}

void Server::processControlMessage(const QString &message) {
    QStringList parts = message.split(':');
    QString id = parts[0].trimmed();
    QString channel = parts[1].trimmed();
    QString msg = parts[2].trimmed();
    QDateTime time = QDateTime::currentDateTime();

    //qDebug() << id << channel << msg;

    QRegularExpression regex("\\d+");
    QRegularExpressionMatch match = regex.match(msg);

    if (channel == "1") {
        updateAirConditionerState(msg, match);
    } else if (channel == "2") {
        updateTVState(msg, match);
    } else if (channel == "3") {
        updateWindowState(msg, match);
    }

    if (!saveToDatabase("messages", { {":id", id}, {":channel", channel}, {":chat", msg}, {":time", time}})) {
        qDebug() << "Error: Unable to save message to database.";
    } else {
        qDebug() << "Saved message to messages table";
    }
}

void Server::updateAirConditionerState(const QString &msg, const QRegularExpressionMatch &match) {
    if (msg.startsWith("Temperature changed -> ") && match.hasMatch()) {
        airconTemperature = match.captured(0).toInt();
    } else if (msg.startsWith("Wind Speed -> ") && match.hasMatch()) {
        airWindLevel = match.captured(0).toInt();
    } else if (msg == "Airconditioning ON!") {
        airconState = true;
    } else if (msg == "Airconditioning OFF!") {
        airconState = false;
    }
}

void Server::updateTVState(const QString &msg, const QRegularExpressionMatch &match) {
    if (msg.contains("Platform -> ") && match.hasMatch()) {
        tvChannel = match.captured(0).toInt();
    } else if (msg.contains("Sound Level -> ") && match.hasMatch()) {
        tvSound = match.captured(0).toInt();
    } else if (msg.contains("ON!")) {
        tvState = true;
    } else if (msg.contains("OFF!")) {
        tvState = false;
    }
}

void Server::updateWindowState(const QString &msg, const QRegularExpressionMatch &match) {
    if (msg.contains("LivingRoom' window -> ") && match.hasMatch()) {
        livingroomSlide = match.captured(0).toInt();
    } else if (msg.contains("BedRoom' window -> ") && match.hasMatch()) {
        bedroomSlide = match.captured(0).toInt();
    } else if (msg.contains("BathRoom' window -> ") && match.hasMatch()) {
        bathroomSlide = match.captured(0).toInt();
    } else if (msg.contains("OPEN!")) {
        windowState = true;
        livingroomSlide = 100;
        bedroomSlide = 100;
        bathroomSlide = 100;
    } else if (msg.contains("CLOSE!")) {
        windowState = false;
        livingroomSlide = 0;
        bedroomSlide = 0;
        bathroomSlide = 0;
    }
}

bool Server::saveToDatabase(const QString &tableName, const QMap<QString, QVariant> &data) {
    QSqlQuery query;
    QString fields = data.keys().join(", ").replace(":", "");
    QString placeholders = data.keys().join(", ");
    query.prepare(QString("INSERT INTO %1 (%2) VALUES (%3)").arg(tableName, fields, placeholders));

    for (auto it = data.cbegin(); it != data.cend(); ++it) {
        query.bindValue(it.key(), it.value());
    }

    return query.exec();
}
