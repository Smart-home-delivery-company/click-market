#include "login.h"
#include "ui_login.h"
#include <QPixmap>


login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Abdelaziz/Desktop/Qt_Projects/clickmarketlogo.png") ;
    QPixmap pix1("C:/Users/Abdelaziz/Desktop/Qt_Projects//ClickMarket/shoppingbag_icon.png") ;
    QPixmap pix2("C:/Users/Abdelaziz/Desktop/Qt_Projects/ClickMarket/shoppingcart_icon.png") ;
    ui->logopic1->setPixmap(pix.scaled(300,300,Qt::KeepAspectRatio)) ;
    ui->navbar_card->setPixmap(pix1.scaled(65,65,Qt::KeepAspectRatio)) ;
    ui->label_shopcarticon->setPixmap(pix2.scaled(55,55,Qt::KeepAspectRatio)) ;
    ui->stackedWidget->setCurrentIndex(2) ;
    client_associe=false ;


}

login::~login()
{
    delete ui;
}






void login::on_pcportable_next_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1) ;
}

void login::on_pcportable_next_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0) ;
}

void login::on_navbar_Elect_clicked()
{
    ui->stackedWidget->setCurrentIndex(0) ;
    ui->stackedWidget_2->setCurrentIndex(0) ;
}

void login::on_navbar_Accueil_clicked()
{
    ui->stackedWidget->setCurrentIndex(2) ;
}

void login::on_item_1_clicked()
{
    int x = (ui->prix_item1->text()).toInt()  ;
    int total = (ui->total_panier->text()).toInt() ;
    total = total +x ;
    QString t = QString::number(total) ;
    ui->total_panier->setText(t)   ;
    ui->label_61->setText(ui->total_panier->text()) ;
    ui->label_73->setText(ui->total_panier->text()) ;
}

void login::on_navbar_Sant_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1) ;
}

void login::on_button_deconnecter_clicked()
{
    close() ;
}

void login::on_navbar_Sant_3_clicked()
{
    if (client_associe==true)
    {
        ui->stackedWidget->setCurrentIndex(4) ;
    } else
    {
        ui->stackedWidget->setCurrentIndex(3) ;
    }

}



void login::on_pushButton_16_clicked()
{
    AssocierClient A ;
    A.exec() ;
    if (A.association_faite==true)
    {
        client_associe=true ;
        ui->stackedWidget->setCurrentIndex(4) ;
    }
}



void login::on_pushButton_24_clicked()
{
    client_associe=false ;
    ui->stackedWidget->setCurrentIndex(3) ;
}
