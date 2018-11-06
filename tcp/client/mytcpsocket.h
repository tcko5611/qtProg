#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class MyTcpSocket : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpSocket(QObject *parent = 0);
    
    void doConnect();

signals:
  void finished();
public slots:
  void handleError(QAbstractSocket::SocketError socketError);
  void connected();
  void readyRead();
  void waitForConnect();
private:
    QTcpSocket socket;
    
};

#endif // MYTCPSOCKET_H
