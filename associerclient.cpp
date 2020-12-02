#include "associerclient.h"
#include "ui_associerclient.h"
#include "clientclass.h"

AssocierClient::AssocierClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AssocierClient)
{
    ui->setupUi(this);
}


AssocierClient::~AssocierClient()
{
    delete ui;
}

void AssocierClient::on_pushButton_2_clicked()
{
    close() ;
}
bool Association_Retour(bool x)
{
return x ;
}

QString  Email_Associer (QString x)
{
    return x ;
}

void AssocierClient::trouver_client()
{
    QSqlQuery query  ;
    query.prepare("select * from CLIENT where ID = '"+email_asc+"'") ;
    if (query.exec())
    {
        while (query.next())
        {
            id_asc= query.value(0).toInt() ;
            nom_asc = query.value(1).toString() ;
            prenom_asc = (query.value(2).toString()) ;
            cin_asc = (query.value(3).toInt()) ;


            tel_asc = (query.value(6).toInt()) ;
            points_asc = (query.value(7).toInt()) ;
        }

    }
}
void AssocierClient::on_pushButton_clicked()
{
    QString email = ui->lineEdit->text() ;
    QString password = ui->lineEdit_2->text() ;
    clientclass C(0,"","",0,email,password,0,0) ;
    bool test = C.test_login() ;
    if (test==true)
    {
        association_faite=true ;
        Association_Retour(association_faite) ;
        email_asc = email ;
        trouver_client() ;
        close() ;
    } else
    {
        ui->label_3->setText("Compte Client Introuvable ! Réessayer.") ;
    }

}




