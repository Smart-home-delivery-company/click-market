#include "connection.h"

connection::connection()
{


}

bool connection::createconnect()
{
    bool test = false ;
    QSqlDatabase db= QSqlDatabase::addDatabase("QODBC") ;
    db.setDatabaseName("Source_Projet2A") ;
    db.setUserName("system") ;
    db.setPassword("azertyyt123") ;
    if (db.open())
    {
        test=true ;

    }
return test ;
}
