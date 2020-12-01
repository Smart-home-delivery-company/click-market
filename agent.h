#ifndef AGENT_H
#define AGENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
class agent
{
protected:
    int id ;
    QString nom ;
    QString prenom ;
    int CIN ;
    QString email ;
    QString mdp ;
    int num_tel ;

public :
    agent();
    agent(int id, QString nom, QString prenom,int CIN, QString email, QString mdp, int num_tel ) ;
    int get_id() {return id ;} ;
    QString get_nom() {return nom; } ;
    QString get_prenom() {return prenom ; } ;
    int get_cin() {return CIN ;} ;
    QString get_email() {return email ; } ;
    QString get_mdp() {return mdp ; } ;
    int get_numtel() {return num_tel ; } ;

    bool ajouter() ;
    bool test_login() ;
    bool supprimer(int) ;
    bool modifer(int id, QString nom, QString prenom,int CIN, QString email, QString mdp, int num_tel) ;
    bool charger_agents(QTableView *tableView) ;
    void table_click_agent(QString val, QLineEdit *id, QLineEdit *nom, QLineEdit *prenom, QLineEdit *cin, QLineEdit *email, QLineEdit *mdp, QLineEdit *tel  ) ;
    void rechercher_agent(QString val , QComboBox *comboBox , QTableView *tableView) ;
    void trier_agents(QComboBox *comboBox , QTableView *tableView , QLabel *text_result) ;
};

#endif // AGENT_H
