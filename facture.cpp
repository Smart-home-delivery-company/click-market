#include "facture.h"
#include "ui_facture.h"
#include <QPixmap>
#include <QPrinter>
#include <QPrintDialog>

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



void Facture::on_boutton_imprimer_clicked()
{
    QPrinter printer  ;
    printer.setPrinterName("Impression Facture") ;
    QPrintDialog dialog(&printer,this) ;
    if (dialog.exec()== QDialog::Rejected) return ;
    ui->textEdit->print(&printer) ;
}
