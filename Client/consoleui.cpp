#include "consoleui.h"
#include "stdinreader.h"
#include "gameclient.h"

ConsoleUI::ConsoleUI(QObject *parent) :
    QObject(parent)
{
    stdInReader *in = new stdInReader(this);
    QTextStream(stdout) << in->init() << endl;
    GameClient *gClient = new GameClient("same ip", 9876, "SameLogin", this);
    connect(in, SIGNAL(received_StdIn(QString)), gClient, SLOT(sendToServer(QString)));
    connect(gClient, SIGNAL(sendToUI(QString)), SLOT(on_Draw_Message(QString)));
    in->run();
}

void ConsoleUI::on_Draw_Message(QString message)
{

}
