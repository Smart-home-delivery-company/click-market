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

bool livreurclass::charger_livreur(QTableView *tableView)
{
    QSqlQueryModel * modal = new QSqlQueryModel() ;
    QSqlQuery *query = new QSqlQuery();
    query->prepare("select * from ALIVREUR") ;
    query->exec() ;
    modal->setQuery(*query) ;
    tableView->setModel(modal) ;
    return true ;

}

void livreurclass::table_click_livreur(QString val, QLineEdit *id, QLineEdit *nom, QLineEdit *prenom, QLineEdit *cin, QLineEdit *email, QLineEdit *mdp, QLineEdit *tel  )
{
    QSqlQuery query ;
    query.prepare("select * from ALIVREUR where ID = '"+val+"'") ;
    if (query.exec())
    {
        while (query.next())
        {
            id->setText(query.value(0).toString()) ;
            nom->setText(query.value(1).toString()) ;
            prenom->setText(query.value(2).toString()) ;
            cin->setText(query.value(3).toString()) ;
            email->setText(query.value(4).toString()) ;
            mdp->setText(query.value(5).toString()) ;
            tel->setText(query.value(6).toString()) ;

        }

    }
}


void livreurclass::rechercher_livreur(QString val,QComboBox *comboBox,QTableView *tableView)
{
    QSqlQueryModel * modal = new QSqlQueryModel() ;
    if (comboBox->currentIndex()==1)
    {
        QSqlQuery *query = new QSqlQuery();
        query->prepare("select * from ALIVREUR where ID = '"+val+"'" ) ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
    } else if (comboBox->currentIndex()==2)
    {
        QSqlQuery *query = new QSqlQuery();
        query->prepare("select * from ALIVREUR where PRENOM='"+val+"'") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
    } else if (comboBox->currentIndex()==3)
    {
        QSqlQuery *query = new QSqlQuery();
        query->prepare("select * from ALIVREUR where EMAIL='"+val+"'") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
    } else if (comboBox->currentIndex()==4)
    {
        QSqlQuery *query = new QSqlQuery();
        query->prepare("select * from ALIVREUR where CIN='"+val+"'") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
    } else if (comboBox->currentIndex()==5)
    {
        QSqlQuery *query = new QSqlQuery();
        query->prepare("select * from ALIVREUR where NOM='"+val+"'") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
    } else if (comboBox->currentIndex()==6)
    {
        QSqlQuery *query = new QSqlQuery();
        query->prepare("select * from ALIVREUR where TEL='"+val+"'") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
    }
}

void livreurclass::trier_livreurs(QComboBox *comboBox , QTableView *tableView , QLabel *text_result)
{
    if (comboBox->currentIndex()==1)
    {



          QSqlQueryModel * modal = new QSqlQueryModel() ;
          QSqlQuery *query = new QSqlQuery();
           query->prepare("select * from ALIVREUR ORDER BY ID") ;
          query->exec() ;
          modal->setQuery(*query) ;
          tableView->setModel(modal) ;


        text_result->setText("Succés tri par ID. ") ;
    } else if (comboBox->currentIndex()==2)
    {

        QSqlQueryModel * modal = new QSqlQueryModel() ;
        QSqlQuery *query = new QSqlQuery();
         query->prepare("select * from ALIVREUR ORDER BY NOM") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;

        text_result->setText("Succés tri par nom.") ;
    } else if (comboBox->currentIndex()==3)
    {
        QSqlQueryModel * modal = new QSqlQueryModel() ;
        QSqlQuery *query = new QSqlQuery();
         query->prepare("select * from ALIVREUR ORDER BY EMAIL") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
        text_result->setText("Succés tri par email.") ;
    } else if (comboBox->currentIndex()==4)
    {
        QSqlQueryModel * modal = new QSqlQueryModel() ;
        QSqlQuery *query = new QSqlQuery();
         query->prepare("select * from ALIVREUR ORDER BY CIN") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
        text_result->setText("Succés tri par CIN.") ;
    } else if (comboBox->currentIndex()==5)
    {
        QSqlQueryModel * modal = new QSqlQueryModel() ;
        QSqlQuery *query = new QSqlQuery();
         query->prepare("select * from ALIVREUR ORDER BY PRENOM") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
        text_result->setText("Succés tri par nom.") ;
    } else if (comboBox->currentIndex()==6)
    {
        QSqlQueryModel * modal = new QSqlQueryModel() ;
        QSqlQuery *query = new QSqlQuery();
         query->prepare("select * from ALIVREUR ORDER BY TEL") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
        text_result->setText("Succés tri par téléphone.") ;
    }
}
