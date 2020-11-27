#include "clientclass.h"
#include "agent.h"
clientclass::clientclass():agent()
{

}

clientclass::clientclass(int id, QString nom, QString prenom,int CIN, QString email, QString mdp, int num_tel, int points_fid):agent(id,nom,prenom,CIN,email,mdp,num_tel)
{
    this->points_fid = 0 ;
}

bool clientclass::ajouter()
{
    QSqlQuery query ;
    QString res_id = QString::number(get_id()) ;
    QString res_CIN = QString::number(get_cin()) ;
    QString res_numtel = QString::number(get_numtel()) ;
    QString nom = get_nom() ;
    QString prenom = get_prenom() ;
    QString email = get_email() ;
    QString mdp = get_mdp() ;


    query.prepare("INSERT INTO CLIENT(ID,NOM,PRENOM,CIN,EMAIL,MDP,TEL,POINTS)"
                  "VALUES(:id_agent, :nom, :prenom, :CIN, :email, :mdp, :num_tel, :points)") ;
    query.bindValue(":id_agent", res_id) ;
    query.bindValue(":nom", nom) ;
    query.bindValue(":prenom", prenom) ;
    query.bindValue(":CIN", res_CIN) ;
    query.bindValue(":email", email) ;
    query.bindValue(":mdp", mdp) ;
    query.bindValue(":num_tel",res_numtel) ;
    query.bindValue(":points", 0) ;
    return  query.exec() ;
}

bool clientclass::modifer(int id, QString nom, QString prenom,int CIN, QString email, QString mdp, int num_tel, int points_fid)
{
    QString res_id = QString::number(id) ;
    QString res_cin = QString::number(CIN) ;
    QString res_points = QString::number(points_fid) ;
    QString res_tel = QString::number(num_tel) ;
    QSqlQuery query ;
    query.prepare("update CLIENT set ID='"+res_id+"', NOM='"+nom+"', PRENOM='"+prenom+"', CIN='"+res_cin+"', EMAIL='"+email+"', MDP='"+mdp+"', TEL='"+res_tel+"' , POINTS='"+res_points+"' where ID='"+res_id+"' ") ;
    return query.exec() ;
}

bool clientclass::supprimer(int id )
{
    QString res_id = QString::number(id) ;
    QSqlQuery query ;
        query.prepare("Delete from CLIENT where ID='"+res_id+"'") ;
       return   query.exec() ;
}
