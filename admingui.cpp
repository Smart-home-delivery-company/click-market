#include "admingui.h"
#include "ui_admingui.h"
#include "agent.h"
#include <QPixmap>
#include "livreurclass.h"
adminGUI::adminGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminGUI)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Abdelaziz/Desktop/Qt_Projects/clickmarketlogo.png") ;
    QPixmap pix1("C:/Users/Abdelaziz/Desktop/Qt_Projects//ClickMarket/shoppingbag_icon.png") ;
    ui->logopic1->setPixmap(pix.scaled(300,300,Qt::KeepAspectRatio)) ;
    ui->navbar_card->setPixmap(pix1.scaled(65,65,Qt::KeepAspectRatio)) ;
}

adminGUI::~adminGUI()
{
    delete ui;
}


// ======================= GESTION AGENTS
void adminGUI::on_tableView_2_activated(const QModelIndex &index)
{
    QString val = ui->tableView_2->model()->data(index).toString() ;
    QSqlQuery query ;
    query.prepare("select * from AGENT where ID = '"+val+"'") ;
    if (query.exec())
    {
        while (query.next())
        {
            ui->id_2->setText(query.value(0).toString()) ;
            ui->nom_2->setText(query.value(1).toString()) ;
            ui->prenom_2->setText(query.value(2).toString()) ;
            ui->cin_2->setText(query.value(3).toString()) ;
            ui->email_2->setText(query.value(4).toString()) ;
            ui->mdp_2->setText(query.value(5).toString()) ;
            ui->tel_2->setText(query.value(6).toString()) ;

        }

    }
}


void adminGUI::on_signup_boutton_2_clicked()
{
    QString nom = ui->nom_insc_2->text() ;
    QString prenom = ui->pren_insc_2->text() ;
    QString email = ui->email_insc_2->text() ;
    int CIN = ui->cin_insc_2->text().toInt() ;
    int num_tel = ui->tel_insc_2->text().toInt() ;

    QString mdp    ;
    if ((ui->mdp_insc_2->text()==ui->mdp2_insc_2->text())&&(ui->mdp_insc_2->text()!=""))
    {
        mdp = ui->mdp_insc_2->text() ;
    }
    //int ui->tel_insc->text().toInt() ;
    int id = 21 ;

    agent C(id,nom,prenom,CIN,email,mdp,num_tel) ;
    bool test  = C.ajouter() ;
    if (test==true)
    {
        ui->label_probleme_2->setText("Agent Ajouté avec succés !") ;
    } else
    {
        ui->label_probleme_2->setText("Erreur d'inscription ! Réessayez.") ;
    }
}

void adminGUI::on_boutton_chargerclients_2_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel() ;
    QSqlQuery *query = new QSqlQuery();
    query->prepare("select * from AGENT") ;
    query->exec() ;
    modal->setQuery(*query) ;
    ui->tableView_2->setModel(modal) ;
}

void adminGUI::on_boutton_supprimerclient_2_clicked()
{
    QString id = ui->id_2->text() ;
    QString nom = ui->nom_2->text() ;
    QString prenom = ui->prenom_2->text() ;
    QString cin = ui->cin_2->text() ;
    QString email = ui->email_2->text() ;
    QString mdp = ui->mdp_2->text() ;
    QString tel = ui->tel_2->text() ;

    agent C ;
    bool test = C.supprimer(id.toInt()) ;


    if (test==true)
    {
        ui->text_result_2->setText("Client supprimé.") ;
    } else
    {
        ui->text_result_2->setText("Probléme lors de la suppression du client.") ;
    }
}

void adminGUI::on_boutton_modifierclient_2_clicked()
{
    QString id = ui->id_2->text() ;
    QString nom = ui->nom_2->text() ;
    QString prenom = ui->prenom_2->text() ;
    QString cin = ui->cin_2->text() ;
    QString email = ui->email_2->text() ;
    QString mdp = ui->mdp_2->text() ;
    QString tel = ui->tel_2->text() ;

    agent D(id.toInt(),nom,prenom,cin.toInt(),email,mdp,tel.toInt()) ;
    bool test = D.modifer(id.toInt(),nom,prenom,cin.toInt(),email,mdp,tel.toInt()) ;
    if (test==true)
    {
        ui->text_result_2->setText("Client modifié avec succés !") ;
    } else
    {
        ui->text_result_2->setText("Probléme lors de la modification.") ;
    }
}

void adminGUI::on_boutton_rechercher_2_clicked()
{
    QString val = ui->input_recherche_2->text();
    QSqlQueryModel * modal = new QSqlQueryModel() ;
    QSqlQuery *query = new QSqlQuery();
    query->prepare("select * from AGENT where ID = '"+val+"' or NOM='"+val+"' or PRENOM='"+val+"' or EMAIL='"+val+"' or CIN='"+val+"' or TEL='"+val+"'") ;
    query->exec() ;
    modal->setQuery(*query) ;
    ui->tableView_2->setModel(modal) ;
}











// ======================= GESTION LIVREUR
void adminGUI::on_signup_boutton_3_clicked()
{
    QString nom = ui->nom_insc_3->text() ;
    QString prenom = ui->pren_insc_3->text() ;
    QString email = ui->email_insc_3->text() ;
    int CIN = ui->cin_insc_3->text().toInt() ;
    int num_tel = ui->tel_insc_3->text().toInt() ;

    QString mdp    ;
    if ((ui->mdp_insc_3->text()==ui->mdp2_insc_3->text())&&(ui->mdp_insc_3->text()!=""))
    {
        mdp = ui->mdp_insc_3->text() ;
    }
    //int ui->tel_insc->text().toInt() ;
    int id = 1 ;

    livreurclass C(id,nom,prenom,CIN,email,mdp,num_tel) ;
    bool test  = C.ajouter() ;
    if (test==true)
    {
        ui->label_probleme_3->setText("Livreur Ajouté avec succés !") ;
    } else
    {
        ui->label_probleme_3->setText("Erreur d'inscription ! Réessayez.") ;
    }


}

void adminGUI::on_boutton_chargerclients_3_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel() ;
    QSqlQuery *query = new QSqlQuery();
    query->prepare("select * from ALIVREUR") ;
    query->exec() ;
    modal->setQuery(*query) ;
    ui->tableView_3->setModel(modal) ;
}

void adminGUI::on_tableView_3_activated(const QModelIndex &index)
{
    QString val = ui->tableView_3->model()->data(index).toString() ;
    QSqlQuery query ;
    query.prepare("select * from ALIVREUR where ID = '"+val+"'") ;
    if (query.exec())
    {
        while (query.next())
        {
            ui->id_3->setText(query.value(0).toString()) ;
            ui->nom_3->setText(query.value(1).toString()) ;
            ui->prenom_3->setText(query.value(2).toString()) ;
            ui->cin_3->setText(query.value(3).toString()) ;
            ui->email_3->setText(query.value(4).toString()) ;
            ui->mdp_3->setText(query.value(5).toString()) ;
            ui->tel_3->setText(query.value(6).toString()) ;

        }

    }
}

void adminGUI::on_boutton_modifierclient_3_clicked()
{
    /*QString id = ui->id_3->text() ;
    QString nom = ui->nom_3->text() ;
    QString prenom = ui->prenom_3->text() ;
    QString cin = ui->cin_3->text() ;
    QString email = ui->email_3->text() ;
    QString mdp = ui->mdp_3->text() ;
    QString tel = ui->tel_3->text() ;

    livreurclass D(id.toInt(),nom,prenom,cin.toInt(),email,mdp,tel.toInt()) ;
    bool test = D.modifer(id.toInt(),nom,prenom,cin.toInt(),email,mdp,tel.toInt()) ;
    if (test==true)
    {
        ui->text_result_3->setText("Livreur modifié avec succés !") ;
    } else
    {
        ui->text_result_3->setText("Probléme lors de la modification.") ;
    }*/

    QString id = ui->id_3->text() ;
    QString nom = ui->nom_3->text() ;
    QString prenom = ui->prenom_3->text() ;
    QString cin = ui->cin_3->text() ;
    QString email = ui->email_3->text() ;
    QString mdp = ui->mdp_3->text() ;
    QString tel = ui->tel_3->text() ;

    livreurclass D(id.toInt(),nom,prenom,cin.toInt(),email,mdp,tel.toInt()) ;
    bool test = D.modifer(id.toInt(),nom,prenom,cin.toInt(),email,mdp,tel.toInt()) ;
    if (test==true)
    {
        ui->text_result_3->setText("Livreur modifié avec succés !") ;
    } else
    {
        ui->text_result_3->setText("Probléme lors de la modification.") ;
    }


}

void adminGUI::on_boutton_rechercher_3_clicked()
{
    QString val = ui->input_recherche_3->text();
    QSqlQueryModel * modal = new QSqlQueryModel() ;
    QSqlQuery *query = new QSqlQuery();
    query->prepare("select * from ALIVREUR where ID = '"+val+"' or NOM='"+val+"' or PRENOM='"+val+"' or EMAIL='"+val+"' or CIN='"+val+"' or TEL='"+val+"'") ;
    query->exec() ;
    modal->setQuery(*query) ;
    ui->tableView_3->setModel(modal) ;
}

void adminGUI::on_boutton_supprimerclient_3_clicked()
{
    QString id = ui->id_3->text() ;
    QString nom = ui->nom_3->text() ;
    QString prenom = ui->prenom_3->text() ;
    QString cin = ui->cin_3->text() ;
    QString email = ui->email_3->text() ;
    QString mdp = ui->mdp_3->text() ;
    QString tel = ui->tel_3->text() ;
    livreurclass C ;
    bool test = C.supprimer(id.toInt()) ;


    if (test==true)
    {
        ui->text_result_3->setText("Livreur supprimé.") ;
    } else
    {
        ui->text_result_3->setText("Probléme lors de la suppression du client.") ;
    }
}
