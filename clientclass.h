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
    clientclass();
    clientclass(int id, QString nom, QString prenom,int CIN, QString email, QString mdp, int num_tel, int points_fid) ;
    bool ajouter() ;
    bool modifer(int id, QString nom, QString prenom,int CIN, QString email, QString mdp, int num_tel, int points_fid) ;
    bool supprimer(int id) ;
};

#endif // CLIENTCLASS_H
