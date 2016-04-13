#include "gameclient.h"

GameClient::GameClient(QString ip, quint16 port, QString Login, QObject *parent = 0) :
    QObject(parent)
{
    ServerSocket = new QTcpSocket();
    connect(ServerSocket, SIGNAL(readyRead()), SLOT(on_readyReadFromServer()));
    ServerSocket->connectToHost(ip,port);//add check of connection
    loginToServer(Login);//add login check
}

void GameClient::sendToServer(QString message)
{
    qint32 code;
    if ((code = checkUserMessage(message)) == 0)
    {
        QByteArray pack = serializeMessage(message);
        writePackToServer(pack);
    }
    else
    {
        QString error_message = getErrorMessage(code);
        emit sendToUI(error_message);
    }
}

void GameClient::on_readyReadFromServer()
{
    QByteArray pack = readPackFromServer();//add reading check
    QString message = deserializePack(pack);//add check
    emit sendToUI(message);
}

qint32 GameClient::loginToServer(QString Login)
{
    //if successful return 0 else return error key
    return 0;
}

QByteArray GameClient::readPackFromServer()
{

}

QString GameClient::deserializePack(QByteArray pack)
{

}

QByteArray GameClient::serializeMessage(QString message)
{

}

qint32 GameClient::checkUserMessage(QString message)
{

}

void GameClient::writePackToServer(QByteArray pack)
{

}

QString GameClient::getErrorMessage(qint32 code)
{

}
