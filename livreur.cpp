#include "livreur.h"
#include "ui_livreur.h"
#include <QPixmap>

livreur::livreur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::livreur)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Abdelaziz/Desktop/Qt_Projects/clickmarketlogo.png") ;
    QPixmap pix1("C:/Users/Abdelaziz/Desktop/Qt_Projects/cardicon.png") ;
    ui->logopic1->setPixmap(pix.scaled(300,300,Qt::KeepAspectRatio)) ;
    ui->navbar_card->setPixmap(pix1.scaled(65,65,Qt::KeepAspectRatio)) ;
}

livreur::~livreur()
{
    delete ui;
}

void livreur::on_button_deconnecter_clicked()
{
    close() ;
}
