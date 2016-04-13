#ifndef GAMECLIENT_H
#define GAMECLIENT_H

#include <QObject>
#include <QTcpSocket>

class GameClient : public QObject
{
    Q_OBJECT
protected:
    QTcpSocket *ServerSocket;

public:
    explicit GameClient(QString ip, quint16 port, QString Login, QObject *parent);

signals:
    void sendToUI(QString message);

public slots:
    void sendToServer(QString message);//message sent by the user
private slots:
    void on_readyReadFromServer();

private:
    qint32 loginToServer(QString Login);
    QByteArray readPackFromServer();//read pack from socket
    QString deserializePack(QByteArray pack);//deserialization package and the formation of messages for user
    QByteArray serializeMessage(QString message);
    qint32 checkUserMessage(QString message);//check syntax
    void writePackToServer(QByteArray pack);
    QString getErrorMessage(qint32 code);
};

#endif // GAMECLIENT_H
