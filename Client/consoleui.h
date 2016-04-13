#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <QObject>
#include <QTextStream>


class ConsoleUI : public QObject
{
    Q_OBJECT
public:
    explicit ConsoleUI(QObject *parent = 0);

signals:

public slots:
    void on_Draw_Message(QString message);
private:
};

#endif // CONSOLEUI_H
