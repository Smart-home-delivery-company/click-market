#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "login.h"
#include "livreur.h"
#include <QMainWindow>
#include "connection.h"
#include <QPushButton>
#include "agent.h"
#include "clientclass.h"
#include "livreurclass.h"

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

void MainWindow::openAdmin()
{
    AdminPage = new adminGUI();

    AdminPage->show();

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

    agent A(0,"","",0,email,pass,0 ) ;
    bool test = A.test_login() ;
    if (test==true)
    {
        ui->stackedWidget->setCurrentIndex(0) ;
        ui->lineEdit_email->setText("") ;
        ui->lineEdit_password->setText("") ;
        openLoggedPage() ;
        close() ;
    } else
    {
        ui->label_introuvable->setText("Utilisateur Introuvable, Réssayer !") ;
    }

    if ((email=="admin")&&(pass=="admin"))
        {
            ui->stackedWidget->setCurrentIndex(0) ;
            ui->lineEdit_email->setText("") ;
            ui->lineEdit_password->setText("") ;
            openAdmin() ;
            close() ;



        }


    /* if ((email=="agent")&&(pass=="agent"))
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
    } */

}

void MainWindow::on_navbar_signup_clicked()
{
    ui->stackedWidget->setCurrentIndex(2) ;
}

void MainWindow::on_signup_boutton_clicked()
{
    QString nom = ui->nom_insc->text() ;
    QString prenom = ui->pren_insc->text() ;
    QString email = ui->email_insc->text() ;
    int CIN = ui->cin_insc->text().toInt() ;
    int num_tel = ui->tel_insc->text().toInt() ;

    QString mdp    ;
    if ((ui->mdp_insc->text()==ui->mdp2_insc->text())&&(ui->mdp_insc->text()!=""))
    {
        mdp = ui->mdp_insc->text() ;
    }
    //int ui->tel_insc->text().toInt() ;
    int id = 5 ;



    if (ui->check_agent->isChecked())       // =============== Agent check
    {
        agent A(id,nom,prenom,CIN,email,mdp,num_tel ) ;
        bool test  = A.ajouter() ;
        if (test==true)
        {
            ui->stackedWidget->setCurrentIndex(0) ;
            ui->lineEdit_email->setText("") ;
            ui->lineEdit_password->setText("") ;
            openLoggedPage() ;
            close() ;
        } else
        {
            ui->label_probleme->setText("Erreur d'inscription ! Réessayez.") ;
        }




    } else if (ui->check_client->isChecked())   // =========== client check
    {
        clientclass C(id,nom,prenom,CIN,email,mdp,num_tel,0 ) ;
        bool test  = C.ajouter() ;
        if (test==true)
        {
            ui->stackedWidget->setCurrentIndex(0) ;
            ui->lineEdit_email->setText("") ;
            ui->lineEdit_password->setText("") ;
            openClient() ;
            close() ;
        } else
        {
            ui->label_probleme->setText("Erreur d'inscription ! Réessayez.") ;
        }


    } else if (ui->check_livreur->isChecked())  // ===================== livreur check
    {

        livreurclass L(id,nom,prenom,CIN,email,mdp,num_tel ) ;
        bool test  = L.ajouter() ;
        if (test==true)
        {
            ui->stackedWidget->setCurrentIndex(0) ;
            ui->lineEdit_email->setText("") ;
            ui->lineEdit_password->setText("") ;
            openLivreur() ;
            close() ;
        } else
        {
            ui->label_probleme->setText("Erreur d'inscription ! Réessayez.") ;
        }

    } else
    {
         ui->label_probleme->setText("Erreur d'inscription ! Réessayez.") ;
    }
}
