#include "facture.h"
#include "ui_facture.h"
#include <QPixmap>

Facture::Facture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Facture)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Abdelaziz/Desktop/Qt_Projects/ClickMarket/facture.png") ;

    ui->facture_icon->setPixmap(pix.scaled(60,70,Qt::KeepAspectRatio)) ;
}

Facture::~Facture()
{
    delete ui;
}
