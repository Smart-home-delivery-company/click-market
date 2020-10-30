#ifndef LOGIN_H
#define LOGIN_H
#include "associerclient.h"
#include <QMainWindow>

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pcportable_next_clicked();

    void on_pcportable_next_2_clicked();

    void on_navbar_Elect_clicked();

    void on_navbar_Accueil_clicked();



    void on_item_1_clicked();

    void on_navbar_Sant_2_clicked();

    void on_button_deconnecter_clicked();

    void on_navbar_Sant_3_clicked();



    void on_pushButton_16_clicked();

    void on_pushButton_24_clicked();

private:
    Ui::login *ui;

    bool client_associe  ;

};

#endif // LOGIN_H
