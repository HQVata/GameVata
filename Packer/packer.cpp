#include "packer.h"


Packer::Packer()
{
}

QByteArray Packer::packingData(char cmd, QByteArray data)
{
    // to do clear all fild
    CMD.push_back(cmd);
    DATA = data;
    setCMD();
    setCRC();
    stuffByte();
    return RDATA;
}

bool Packer::readPack(QIODevice *socket)
{
    findSB(socket);
    readCMD(socket);
    readDL(socket);
    readDATA(socket);
    readCRC(socket);
    checkCRC();
    //if (AllOk)
    return true;
}

char Packer::getCMD()
{
    return CMD.at(0);
}

QByteArray Packer::getDATA()
{
    return DATA;
}

QByteArray Packer::getRDATA()
{
    return RDATA;
}

bool Packer::readHeader(QIODevice *socket)
{

}

