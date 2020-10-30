#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "login.h"
#include "livreur.h"
#include <QMainWindow>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QPixmap pix("C:/Users/Abdelaziz/Desktop/Qt_Projects/clickmarketlogo.png") ;
    QPixmap pix1("C:/Users/Abdelaziz/Desktop/Qt_Projects/cardicon.png") ;
    ui->logopic1->setPixmap(pix.scaled(300,300,Qt::KeepAspectRatio)) ;
    ui->navbar_card->setPixmap(pix1.scaled(65,65,Qt::KeepAspectRatio)) ;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openLoggedPage()
{
    logged = new login();

    logged->show();

}

void MainWindow::openLivreur()
{
    livPage = new livreur();

    livPage->show();

}

void MainWindow::openClient()
{
    clientPage = new client();

    clientPage->show();

}






void MainWindow::on_navbar_login_clicked()
{
    ui->stackedWidget->setCurrentIndex(1) ;
}


void MainWindow::on_navbar_Accueil_clicked()
{
    ui->stackedWidget->setCurrentIndex(0) ;
}

void MainWindow::on_pushButton_clicked()
{
    QString email = ui->lineEdit_email->text() ;
    QString pass = ui->lineEdit_password->text() ;

    if ((email=="agent")&&(pass=="agent"))
    {
        ui->stackedWidget->setCurrentIndex(0) ;
        ui->lineEdit_email->setText("") ;
        ui->lineEdit_password->setText("") ;
        openLoggedPage() ;
        close() ;



    } else if ((email=="livreur")&&(pass=="livreur"))
    {
        ui->stackedWidget->setCurrentIndex(0) ;
        ui->lineEdit_email->setText("") ;
        ui->lineEdit_password->setText("") ;
        openLivreur() ;
        close() ;
    } else if ((email=="client")&&(pass=="client"))
    {
        ui->stackedWidget->setCurrentIndex(0) ;
        ui->lineEdit_email->setText("") ;
        ui->lineEdit_password->setText("") ;
        openClient() ;
        close() ;
    }else {
        ui->label_introuvable->setText("Utilisateur Introuvable, Réssayer !") ;
    }

}

void MainWindow::on_navbar_signup_clicked()
{
    ui->stackedWidget->setCurrentIndex(2) ;
}
