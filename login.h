#ifndef LOGIN_H
#define LOGIN_H
#include "associerclient.h"
#include <QMainWindow>
#include <QLabel>
#include <QtSql/QSqlDatabase>
#include "ajouterproduit.h"
#include <QListWidget>
#include "produit.h"
#include <QMap>
#include <QList>
#include "facture.h"
namespace Ui {
class login;

}



class login : public QMainWindow
{
    Q_OBJECT


public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    //QVector<produit> tab_produits ;
    //void ajouterproduit(produit P) ;

    QMap<int , QListWidgetItem *> tab_elec ;

    QList<produit> tab_produits ;
    QList<produit> tab_panier ;

    void afficher_item(QListWidgetItem *item, produit P) ;
    int chercher_produit(QListWidgetItem *item) ;
    void update_produit(int produit_id, int prix , QString nom , QString image) ;
    void calcul_prix(int remise) ;

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


    void on_pushButton_17_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_produit_modification_clicked();

    void on_produit_suppression_clicked();

    void on_pushButton_3_clicked();



    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();



    void on_pushButton_clicked();



    void on_boutton_convertir_points_clicked();



    void on_supprimer_compte_associe_clicked();





    void on_signup_boutton_clicked();

    void on_navbar_Sant_4_clicked();

    void on_boutton_chargerclients_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_boutton_supprimerclient_clicked();

    void on_boutton_modifierclient_clicked();

    void on_boutton_rechercher_clicked();


    void on_boutton_trier_clicked();

   //void on_boutton_ajouter_clicked();

    void on_boutton_ajouter_clicked();

private:
    Ui::login *ui;

    bool client_associe  ;
    int converti ;


} ;













#endif // LOGIN_H
