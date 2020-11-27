#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QPushButton>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    connection c ;
    bool test=c.createconnect() ;

    if (test)
    {

        QMessageBox::critical(nullptr,QObject::tr("database is open"),QObject::tr("connection successful.\n"),QMessageBox::Cancel) ;
    } else
    {

        QMessageBox::critical(nullptr,QObject::tr("database is not open"),QObject::tr("connection unx²successful.\n"),QMessageBox::Cancel) ;
    }
    QCoreApplication::setApplicationName("ClickMarket") ;

     w.show();
    return a.exec();

}
