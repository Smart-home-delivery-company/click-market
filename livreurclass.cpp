#include "livreurclass.h"

livreurclass::livreurclass():agent()
{

}
livreurclass::livreurclass(int id, QString nom, QString prenom,int CIN, QString email, QString mdp, int num_tel)
{    this->id = id ;
    this->nom = nom ;
    this->prenom =prenom ;
    this->CIN = CIN ;
    this->email = email ;
    this->mdp = mdp ;
    this->num_tel = num_tel ;
}

bool livreurclass::ajouter()
{
    QSqlQuery query ;
    QString res_id = QString::number(get_id()) ;
    QString res_CIN = QString::number(get_cin()) ;
    QString res_numtel = QString::number(get_numtel()) ;
    query.prepare("INSERT INTO ALIVREUR(ID,NOM,PRENOM,CIN,EMAIL,MDP,TEL)"
                  "VALUES(:id_agent, :nom, :prenom, :CIN, :email, :mdp, :num_tel)") ;
    query.bindValue(":id_agent", res_id) ;
    query.bindValue(":nom", nom) ;
    query.bindValue(":prenom", prenom) ;
    query.bindValue(":CIN", res_CIN) ;
    query.bindValue(":email", email) ;
    query.bindValue(":mdp", mdp) ;
    query.bindValue(":num_tel",res_numtel) ;
    return  query.exec() ;
}


bool livreurclass::supprimer(int id )
{
    QString res_id = QString::number(id) ;
    QSqlQuery query ;
    query.prepare("Delete from ALIVREUR where ID='"+res_id+"'") ;
    return   query.exec() ;
}

bool livreurclass::modifer(int id, QString nom, QString prenom,int CIN, QString email, QString mdp, int num_tel)
{
    QString res_id = QString::number(id) ;
    QString res_cin = QString::number(CIN) ;
    QString res_tel = QString::number(num_tel) ;
    QSqlQuery query ;
    query.prepare("update ALIVREUR set ID='"+res_id+"', NOM='"+nom+"', PRENOM='"+prenom+"', CIN='"+res_cin+"', EMAIL='"+email+"', MDP='"+mdp+"', TEL='"+res_tel+"' where ID='"+res_id+"' ") ;
    return query.exec() ;
}
