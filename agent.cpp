 #include "agent.h"

agent::agent()
{
    id = 0 ;
    nom = "";
    prenom ="";
    CIN = 0 ;
    email = "" ;
    mdp = "" ;
    num_tel = 0 ;
}

agent::agent(int id_agent, QString nom, QString prenom,int CIN, QString email, QString mdp, int num_tel )
{
    this->id = id_agent ;
    this->nom = nom ;
    this->prenom =prenom ;
    this->CIN = CIN ;
    this->email = email ;
    this->mdp = mdp ;
    this->num_tel = num_tel ;
}

bool agent::ajouter()
{
    QSqlQuery query ;
    QString res_id = QString::number(get_id()) ;
    QString res_CIN = QString::number(get_cin()) ;
    QString res_numtel = QString::number(get_numtel()) ;
    query.prepare("INSERT INTO AGENT(ID,NOM,PRENOM,CIN,EMAIL,MDP,TEL)"
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


bool agent::test_login()
{
    QSqlQuery query ;
    if (query.exec("select *from AGENT where EMAIL='"+email+"' and MDP='"+mdp+"' "))
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


bool agent::supprimer(int id )
{
    QString res_id = QString::number(id) ;
    QSqlQuery query ;
        query.prepare("Delete from AGENT where ID='"+res_id+"'") ;
       return   query.exec() ;
}

bool agent::modifer(int id, QString nom, QString prenom,int CIN, QString email, QString mdp, int num_tel)
{
    QString res_id = QString::number(id) ;
    QString res_cin = QString::number(CIN) ;
    QString res_tel = QString::number(num_tel) ;
    QSqlQuery query ;
    query.prepare("update AGENT set ID='"+res_id+"', NOM='"+nom+"', PRENOM='"+prenom+"', CIN='"+res_cin+"', EMAIL='"+email+"', MDP='"+mdp+"', TEL='"+res_tel+"' where ID='"+res_id+"'") ;
    return query.exec() ;
}



bool agent::charger_agents(QTableView *tableView)
{
    QSqlQueryModel * modal = new QSqlQueryModel() ;
    QSqlQuery *query = new QSqlQuery();
    query->prepare("select * from AGENT") ;
    query->exec() ;
    modal->setQuery(*query) ;
    tableView->setModel(modal) ;
    return true ;

}

void agent::table_click_agent(QString val, QLineEdit *id, QLineEdit *nom, QLineEdit *prenom, QLineEdit *cin, QLineEdit *email, QLineEdit *mdp, QLineEdit *tel  )
{
    QSqlQuery query ;
    query.prepare("select * from AGENT where ID = '"+val+"'") ;
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


void agent::rechercher_agent(QString val , QComboBox *comboBox , QTableView *tableView)
{
    QSqlQueryModel * modal = new QSqlQueryModel() ;
    if (comboBox->currentIndex()==1)
    {
        QSqlQuery *query = new QSqlQuery();
        query->prepare("select * from AGENT where ID = '"+val+"'" ) ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
    } else if (comboBox->currentIndex()==2)
    {
        QSqlQuery *query = new QSqlQuery();
        query->prepare("select * from AGENT where PRENOM='"+val+"'") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
    } else if (comboBox->currentIndex()==3)
    {
        QSqlQuery *query = new QSqlQuery();
        query->prepare("select * from AGENT where EMAIL='"+val+"'") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
    }
}


void agent::trier_agents(QComboBox *comboBox , QTableView *tableView , QLabel *text_result)
{
    if (comboBox->currentIndex()==1)
    {



          QSqlQueryModel * modal = new QSqlQueryModel() ;
          QSqlQuery *query = new QSqlQuery();
           query->prepare("select * from AGENT ORDER BY ID") ;
          query->exec() ;
          modal->setQuery(*query) ;
          tableView->setModel(modal) ;


        text_result->setText("Succés tri par ID. ") ;
    } else if (comboBox->currentIndex()==2)
    {

        QSqlQueryModel * modal = new QSqlQueryModel() ;
        QSqlQuery *query = new QSqlQuery();
         query->prepare("select * from AGENT ORDER BY NOM") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;

        text_result->setText("Succés tri par nom.") ;
    } else if (comboBox->currentIndex()==3)
    {
        QSqlQueryModel * modal = new QSqlQueryModel() ;
        QSqlQuery *query = new QSqlQuery();
         query->prepare("select * from AGENT ORDER BY EMAIL") ;
        query->exec() ;
        modal->setQuery(*query) ;
        tableView->setModel(modal) ;
        text_result->setText("Succés tri par email.") ;
    }

}
