#include "game.h"


Game::Game()
{
    //init
}

Parcel Game::makeMove(QByteArray data)
{
//    QVector<Parcel> parcel;
    Parcel parcel;
    int move = deserializePack(data);
    if (move < 0)
    {
        parcel.Addressee.push_back(PlayerTurn);
        parcel.Message = serializeErrDescription(move);
        return parcel;
    }
    move = setMove(move);
    if (move < 0)
    {
        parcel.Addressee.push_back(PlayerTurn);
        parcel.Message = serializeErrDescription(move);
        return parcel;
    }
    changeTurn();
    for (int i =0; i < NumPlaers; i++)
        parcel.Addressee.push_back(i);
    parcel.Message = serializeGameStatus();
    return parcel;
}

