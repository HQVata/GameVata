#ifndef STDINREADER_H
#define STDINREADER_H
/* stdInReader.h
  under [GNU GPL v.2] from Denjs
  Простой класс-обертка для работы с потоками STDIN|STDOUT|STDERR.
  ver.2009.09.14 (естественно альфа, но работает и это главное)

  UTF-8 russian encoded file

*/
#include <QtCore>
#include <QThread>
#include <QFile>


class stdInReader : public QThread
{
    Q_OBJECT
public:
    explicit stdInReader(QObject *parent = 0);
    int init();//opend threads and became ready to work.
    /*
          return
        1 if some errors was happened
        0 of all ok
        -1 if can`t oopen stdIn
        -2 if can`t oopen stdOut
        -3 if can`t oopen stdErr
    */
    void run();
signals:
    void received_StdIn(const QString &data);
public slots:
    int send_StdOut(const QByteArray &_data);
    int send_StdErr(const QByteArray &_data);
private:
   QFile stdIn;
   QFile stdOut;
   QFile stdErr;
   QByteArray data;
   bool inited;
};

#endif // STDINREADER_H
