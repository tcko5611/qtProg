// main.cpp

#include <QCoreApplication> 
#include "mytcpsocket.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
    
  MyTcpSocket s;
  QObject::connect(&s, SIGNAL(finished()), &a, SLOT(quit()));
  s.doConnect();
            
  return a.exec();
  //return 0;
}
