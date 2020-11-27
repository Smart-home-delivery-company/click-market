#ifndef AGENT_H
#define AGENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

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
};

#endif // AGENT_H
