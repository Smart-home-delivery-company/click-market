#include "associerclient.h"
#include "ui_associerclient.h"

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
void AssocierClient::on_pushButton_clicked()
{
    QString email = ui->lineEdit->text() ;
    QString password = ui->lineEdit_2->text() ;

    if ((email=="client")&&(password=="client"))
    {
        association_faite=true ;
        Association_Retour(association_faite) ;
        close() ;
    } else {
        ui->label_3->setText("Compte Client Introuvable ! Réessayer.") ;
    }
}


