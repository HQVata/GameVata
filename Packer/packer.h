#ifndef PACKER_H
#define PACKER_H
#include<QByteArray>
#include<QIODevice>

class Packer
{

public:
    Packer();

//    QByteArray packingData();
    QByteArray packingData(char cmd, QByteArray data); //static?

    bool readPack(QByteArray row_data);
    bool readPack(QIODevice *socket);

    char getCMD();
    QByteArray getDATA();
    QByteArray getRDATA();

private:

    QByteArray RDATA;
    QByteArray CMD;
    QByteArray DATA;

    quint16 CRC;
    quint16 DL;

    void setCMD();
    void setCRC();
    void stuffByte();

//    bool findSB(QByteArray row_data);
    bool findSB(QIODevice *socket);
    bool readCMD(QIODevice *socket);
    bool readDL(QIODevice *socket);
    bool readDATA(QIODevice *socket);
    bool readCRC(QIODevice *socket);
    bool checkCRC();

};

#endif // PACKER_H
