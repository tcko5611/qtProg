#include <QTimer>
#include "mytcpsocket.h"

MyTcpSocket::MyTcpSocket(QObject *parent) :
    QObject(parent)
{
}

void MyTcpSocket::doConnect()
{
    connect(&socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(&socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(&socket, SIGNAL(error(QAbstractSocket::SocketError)), this,
	    SLOT(handleError(QAbstractSocket::SocketError)));

    qDebug() << "Try to connect host";
    socket.connectToHost("tcko-PC", 1234);
    qDebug() << "end of connect host";
    QTimer::singleShot(1000, this, SLOT(waitForConnect()));
    /*
    if(socket->waitForConnected(5000))
    {
        qDebug() << "Connected!";

        // send
        socket->write("Hello server\r\n\r\n");
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        
        qDebug() << "Reading: " << socket->bytesAvailable();

        // get the data
        qDebug() << socket->readAll();
        
        // close the connection
        socket->close();
    }
    else
    {
        qDebug() << "Not connected!";
    }
    */
}

void MyTcpSocket::connected()
{
  socket.write("Hello server\r\n\r\n");
}

void MyTcpSocket::readyRead()
{
  qDebug() << "Reading: " << socket.bytesAvailable();
  qDebug() << socket.readAll();
  emit finished();
}

void  MyTcpSocket::handleError(QAbstractSocket::SocketError socketError)
{
  qDebug() << socketError;
  emit finished();
}

void MyTcpSocket::waitForConnect()
{
  if (socket.state() != QAbstractSocket::ConnectedState)
    emit finished();
}
