#include "clientclass.h"
#include "agent.h"
clientclass::clientclass():agent()
{

}

clientclass::clientclass(int id, QString nom, QString prenom,int CIN, QString email, QString mdp, int num_tel, int points_fid):agent(id,nom,prenom,CIN,email,mdp,num_tel)
{
    this->points_fid = points_fid ;
}

bool clientclass::test_login()
{
    QSqlQuery query ;
    if (query.exec("select *from CLIENT where EMAIL='"+email+"' and MDP='"+mdp+"' "))
    {
        int count =0 ;
        while (query.next())
        {
            count++ ;
        }
        if (count ==1)
        {
            return true ;
        }
    }
    return false ;
}


bool clientclass::ajouter()
{
    QSqlQuery query ;
    QString res_id = QString::number(get_id()) ;
    QString res_CIN = QString::number(get_cin()) ;
    QString res_numtel = QString::number(get_numtel()) ;
    QString res_points = QString::number(get_pointsfid()) ;
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
    query.bindValue(":points", res_points ) ;
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





bool clientclass::charger_clients(QTableView *tableView)
{
    QSqlQueryModel * modal = new QSqlQueryModel() ;
    QSqlQuery *query = new QSqlQuery();
    query->prepare("select * from CLIENT") ;
    query->exec() ;
    modal->setQuery(*query) ;
    tableView->setModel(modal) ;
    return true ;

}

void clientclass::table_click_client(QString val, QLineEdit *id, QLineEdit *nom, QLineEdit *prenom, QLineEdit *cin, QLineEdit *email, QLineEdit *mdp, QLineEdit *tel, QLineEdit *points  )
{
    QSqlQuery query ;
    query.prepare("select * from CLIENT where ID = '"+val+"'") ;
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
            points->setText(query.value(7).toString()) ;
        }

    }
}


void clientclass::rechercher_client(QString val , QComboBox *comboBox , QTableView *tableView)
{
    QSqlQueryModel * modal = new QSqlQueryModel() ;
    if (comboBox->currentIndex()==1)
    {
        QSqlQuery *query = new QSqlQuery();
        query->prepare("select * from CLIENT where ID = '"+val+"'" ) ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
    } else if (comboBox->currentIndex()==2)
    {
        QSqlQuery *query = new QSqlQuery();
        query->prepare("select * from CLIENT where PRENOM='"+val+"'") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
    } else if (comboBox->currentIndex()==3)
    {
        QSqlQuery *query = new QSqlQuery();
        query->prepare("select * from CLIENT where EMAIL='"+val+"'") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
    } else if (comboBox->currentIndex()==4)
    {
        QSqlQuery *query = new QSqlQuery();
        query->prepare("select * from CLIENT where CIN='"+val+"'") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
    } else if (comboBox->currentIndex()==5)
    {
        QSqlQuery *query = new QSqlQuery();
        query->prepare("select * from CLIENT where NOM='"+val+"'") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
    } else if (comboBox->currentIndex()==6)
    {
        QSqlQuery *query = new QSqlQuery();
        query->prepare("select * from CLIENT where TEL='"+val+"'") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
    }
}


void clientclass::trier_client(QComboBox *comboBox , QTableView *tableView , QLabel *text_result)
{
    if (comboBox->currentIndex()==1)
    {



          QSqlQueryModel * modal = new QSqlQueryModel() ;
          QSqlQuery *query = new QSqlQuery();
           query->prepare("select * from CLIENT ORDER BY ID") ;
          query->exec() ;
          modal->setQuery(*query) ;
          tableView->setModel(modal) ;


        text_result->setText("Succés tri par ID. ") ;
    } else if (comboBox->currentIndex()==2)
    {

        QSqlQueryModel * modal = new QSqlQueryModel() ;
        QSqlQuery *query = new QSqlQuery();
         query->prepare("select * from CLIENT ORDER BY NOM") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;

        text_result->setText("Succés tri par nom.") ;
    } else if (comboBox->currentIndex()==3)
    {
        QSqlQueryModel * modal = new QSqlQueryModel() ;
        QSqlQuery *query = new QSqlQuery();
         query->prepare("select * from CLIENT ORDER BY EMAIL") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
        text_result->setText("Succés tri par email.") ;
    } else if (comboBox->currentIndex()==4)
    {
        QSqlQueryModel * modal = new QSqlQueryModel() ;
        QSqlQuery *query = new QSqlQuery();
         query->prepare("select * from CLIENT ORDER BY CIN") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
        text_result->setText("Succés tri par CIN.") ;
    } else if (comboBox->currentIndex()==5)
    {
        QSqlQueryModel * modal = new QSqlQueryModel() ;
        QSqlQuery *query = new QSqlQuery();
         query->prepare("select * from CLIENT ORDER BY PRENOM") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
        text_result->setText("Succés tri par prénom.") ;
    } else if (comboBox->currentIndex()==6)
    {
        QSqlQueryModel * modal = new QSqlQueryModel() ;
        QSqlQuery *query = new QSqlQuery();
         query->prepare("select * from CLIENT ORDER BY TEL") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
        text_result->setText("Succés tri par téléphone.") ;
    } else if (comboBox->currentIndex()==7)
    {
        QSqlQueryModel * modal = new QSqlQueryModel() ;
        QSqlQuery *query = new QSqlQuery();
         query->prepare("select * from CLIENT ORDER BY POINTS") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
        text_result->setText("Succés tri par points de fidélités.") ;
    }

}

