#ifndef GAME_H
#define GAME_H
//#include<QByteArray>
#include<QVector>

typedef struct{
    QByteArray Message;
    QVector<int> Addressee;
} Parcel;

class Game
{
private:
    QByteArray PlayingField;
//    QVector<QString> PlaersName;
    int NumPlaers;
    QByteArray PlaersSymbols;
    int PlayerTurn;
    int Winner;

    int deserializePack(QByteArray data);
    QByteArray serializeGameStatus();
    QByteArray serializeErrDescription(int key);
    int setMove(int key);
    void changeTurn();

public:
    Game();

    Parcel makeMove(QByteArray data);
    Parcel startNewGame(QByteArray data);

};

#endif // GAME_H
