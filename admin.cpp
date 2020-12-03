#include "admin.h"

admin::admin()
{

}

admin::admin(QString email , QString password)
{
    this->email = email ;
    this->password = password ;
}

bool admin::admin_testlogin()
{
    QSqlQuery query ;
    if (query.exec("select *from ADMIN where EMAIL='"+email+"' and PASSWORD='"+password+"' "))
    {
        int count =0 ;
        while (query.next())
        {
            count++ ;
        }
        if (count ==1)
        {
            return true ;
        }
    }
    return false ;

}
