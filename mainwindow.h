#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "login.h"
#include <QMainWindow>
#include "livreur.h"
#include "client.h"
#include "admingui.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_navbar_login_clicked();
    void on_navbar_Accueil_clicked();

    void on_pushButton_clicked();

    void on_navbar_signup_clicked();

    void openLoggedPage();
    void openLivreur() ;
    void openClient() ;
    void openAdmin() ;

    void on_signup_boutton_clicked();

private:
       login *logged;
       livreur *livPage ;
       client *clientPage ;
       adminGUI *AdminPage ;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
