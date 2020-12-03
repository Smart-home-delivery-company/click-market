#ifndef ADMIN_H
#define ADMIN_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class admin
{
public:
    QString email ;
    QString password ;

    admin();
    admin(QString email , QString password ) ;

    bool admin_testlogin() ;
};

#endif // ADMIN_H
