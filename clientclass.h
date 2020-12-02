#ifndef CLIENTCLASS_H
#define CLIENTCLASS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "agent.h"

class clientclass : public agent
{
private:
    int points_fid ;
public :
    int get_pointsfid(){return points_fid ; } ;
    clientclass();
    clientclass(int id, QString nom, QString prenom,int CIN, QString email, QString mdp, int num_tel, int points_fid) ;
    bool ajouter() ;
    bool modifer(int id, QString nom, QString prenom,int CIN, QString email, QString mdp, int num_tel, int points_fid) ;
    bool supprimer(int id) ;

    bool charger_clients(QTableView *tableView) ;
    void table_click_client(QString val, QLineEdit *id, QLineEdit *nom, QLineEdit *prenom, QLineEdit *cin, QLineEdit *email, QLineEdit *mdp, QLineEdit *tel, QLineEdit *points ) ;
    void rechercher_client(QString val , QComboBox *comboBox , QTableView *tableView) ;
    void trier_client(QComboBox *comboBox , QTableView *tableView , QLabel *text_result) ;
    bool test_login() ;
};

#endif // CLIENTCLASS_H
