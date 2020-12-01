#ifndef LIVREURCLASS_H
#define LIVREURCLASS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "agent.h"
#include <QTableView>
class livreurclass : public agent
{
public:
    livreurclass();
    livreurclass(int id, QString nom, QString prenom,int CIN, QString email, QString mdp, int num_tel) ;

    bool ajouter() ;
    bool modifer(int id, QString nom, QString prenom,int CIN, QString email, QString mdp, int num_tel) ;
    bool supprimer(int id ) ;
    bool charger_livreur(QTableView *tableView) ;
    void table_click_livreur(QString val, QLineEdit *id, QLineEdit *nom, QLineEdit *prenom, QLineEdit *cin, QLineEdit *email, QLineEdit *mdp, QLineEdit *tel  ) ;
    void rechercher_livreur(QString val,QComboBox *comboBox,QTableView *tableView)  ;
    void trier_livreurs(QComboBox *comboBox , QTableView *tableView , QLabel *text_result) ;

};

#endif // LIVREURCLASS_H
