#ifndef LIVREURCLASS_H
#define LIVREURCLASS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "agent.h"

class livreurclass : public agent
{
public:
    livreurclass();
    livreurclass(int id, QString nom, QString prenom,int CIN, QString email, QString mdp, int num_tel) ;

    bool ajouter() ;
    bool modifer(int id, QString nom, QString prenom,int CIN, QString email, QString mdp, int num_tel) ;
    bool supprimer(int id ) ;
};

#endif // LIVREURCLASS_H
