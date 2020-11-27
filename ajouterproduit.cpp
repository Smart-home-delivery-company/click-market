#include "ajouterproduit.h"
#include "ui_ajouterproduit.h"
#include "login.h"
#include <QFileDialog>

AjouterProduit::AjouterProduit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterProduit)
{
    ui->setupUi(this);

}

AjouterProduit::~AjouterProduit()
{
    delete ui;
}

void AjouterProduit::on_pushButton_2_clicked()
{
    close() ;
}

void AjouterProduit::on_pushButton_3_clicked()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
    ui->input_image->setText(fichier) ;
}

void AjouterProduit::on_pushButton_clicked()
{
    if ((ui->prix_produit->text()!="")&&(ui->input_image->text()!=""))
    {
        QString image = ui->input_image->text() ;
        int prixproduit = (ui->input_prix->text()).toInt() ;
        QPushButton  boutonAjout(image)  ;


    }
}
