#include "admingui.h"
#include "ui_admingui.h"
#include "agent.h"
#include <QPixmap>
#include "livreurclass.h"

#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>


QT_CHARTS_USE_NAMESPACE

adminGUI::adminGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminGUI)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Abdelaziz/Desktop/Qt_Projects/clickmarketlogo.png") ;
    QPixmap pix1("C:/Users/Abdelaziz/Desktop/Qt_Projects//ClickMarket/shoppingbag_icon.png") ;
    ui->logopic1->setPixmap(pix.scaled(300,300,Qt::KeepAspectRatio)) ;
    ui->navbar_card->setPixmap(pix1.scaled(65,65,Qt::KeepAspectRatio)) ;

    Animation = new QPropertyAnimation(ui->logopic1,"geometry") ;
    Animation->setDuration(4000) ;
    Animation->setStartValue(ui->logopic1->geometry()) ;
    Animation->setEndValue(QRect(10,-55,300,300)) ;
    Animation->start() ;
}

adminGUI::~adminGUI()
{
    delete ui;
}


// ======================= GESTION AGENTS
void adminGUI::on_tableView_2_activated(const QModelIndex &index)
{
    QString val = ui->tableView_2->model()->data(index).toString() ;
    agent C ;
    C.table_click_agent(val,ui->id_2,ui->nom_2,ui->prenom_2, ui->cin_2, ui->email_2,ui->mdp_2, ui->tel_2);
}



void adminGUI::on_boutton_chargerclients_2_clicked()
{
    agent C ;
    bool test = C.charger_agents(ui->tableView_2) ;
    if (test==true)
    {
        ui->text_result_2->setText("Liste des agents chargée avec succés !") ;
    } else
    {
        ui->text_result_2->setText("Probléme lors du chargement.") ;
    }
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
    agent C ;
    C.rechercher_agent(val,ui->comboBox_4,ui->tableView_2) ;
}


void adminGUI::on_boutton_ajouter_clicked()
{
    int id = ui->id_2->text().toInt() ;
    QString nom = ui->nom_2->text() ;
    QString prenom = ui->prenom_2->text() ;
    int cin = ui->cin_2->text().toInt() ;
    QString email = ui->email_2->text() ;
    QString mdp = ui->mdp_2->text() ;
    int tel = ui->tel_2->text().toInt() ;
    agent C(id,nom,prenom,cin,email,mdp,tel) ;
    bool test = C.ajouter() ;


    if (test==true)
    {
        ui->text_result_2->setText("Agent ajouté.") ;
    } else
    {
        ui->text_result_2->setText("Probléme lors de l'ajout de l'agent.") ;
    }
}



void adminGUI::on_boutton_trier_2_clicked()
{
    agent C ;
    C.trier_agents(ui->comboBox_2,ui->tableView_2,ui->text_result_2) ;
}
























// ======================= GESTION LIVREUR


void adminGUI::on_boutton_chargerclients_3_clicked()
{
    livreurclass C ;
    bool test = C.charger_livreur(ui->tableView_3) ;
    if (test==true)
    {
        ui->text_result_3->setText("Liste des livreurs chargée avec succés !") ;
    } else
    {
        ui->text_result_3->setText("Probléme lors du chargement.") ;
    }
}

void adminGUI::on_tableView_3_activated(const QModelIndex &index)
{
    QString val = ui->tableView_3->model()->data(index).toString() ;
    livreurclass C ;
    C.table_click_livreur(val,ui->id_3,ui->nom_3,ui->prenom_3, ui->cin_3, ui->email_3,ui->mdp_3, ui->tel_3);
}

void adminGUI::on_boutton_modifierclient_3_clicked()
{


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
        ui->text_result_3->setText("Probléme lors de la suppression de l'agent.") ;
    }
}



void adminGUI::on_boutton_ajouter_2_clicked()
{
    int id = ui->id_3->text().toInt() ;
    QString nom = ui->nom_3->text() ;
    QString prenom = ui->prenom_3->text() ;
    int cin = ui->cin_3->text().toInt() ;
    QString email = ui->email_3->text() ;
    QString mdp = ui->mdp_3->text() ;
    int tel = ui->tel_3->text().toInt() ;
    livreurclass C(id,nom,prenom,cin,email,mdp,tel) ;
    bool test  = C.ajouter() ;
    if (test==true)
    {
        ui->text_result_3->setText("Livreur Ajouté avec succés !") ;
    } else
    {
        ui->text_result_3->setText("Probléme lors de l'ajout du livreur.") ;
    }
}



void adminGUI::on_boutton_trier_3_clicked()
{
    livreurclass C ;
    C.trier_livreurs(ui->comboBox_3,ui->tableView_3,ui->text_result_3) ;
}


void adminGUI::on_boutton_rechercher_4_clicked()
{
    QString val = ui->input_recherche_3->text();
    livreurclass C ;
    C.rechercher_livreur(val,ui->comboBox_5,ui->tableView_3) ;
}


// ======================================================================================================
void adminGUI::openStats()
{
    chart = new stats();

    chart->show();

}
void adminGUI::on_navbar_Sant_3_clicked()
{
    openStats() ;
    stats *S ;

    QBarSet *set0 = new QBarSet("Electronique") ;
    QBarSet *set1 = new QBarSet("Maison") ;
    QBarSet *set2 = new QBarSet("Fashion") ;
    QBarSet *set3 = new QBarSet("Electronique") ;

    *set0 << 10 ;
    *set1 << 12 ;
    *set2 << 4 ;
    *set3 << 8 ;

    QBarSeries *series = new QBarSeries() ;
    series->append(set0) ;
    series->append(set1) ;
    series->append(set2) ;
    series->append(set3) ;

    QChart *chart = new QChart() ;
    chart->addSeries(series) ;
    chart->setTitle("Statistiques des commandes") ;
    chart->setAnimationOptions(QChart::AllAnimations) ;
    QStringList categories ;
    categories << "Ce mois" ;
    QBarCategoryAxis *axis = new QBarCategoryAxis() ;
    axis->append(categories) ;
    chart->createDefaultAxes() ;
    chart->setAxisX(axis,series) ;
    chart->legend()->setVisible(true) ;
    chart->legend()->setAlignment(Qt::AlignBottom) ;

    QChartView *chartView = new QChartView(chart) ;
    chartView->setRenderHint(QPainter::Antialiasing) ;
    QPalette pal =  qApp->palette() ;
    pal.setColor(QPalette::Window, QRgb(0xffffff)) ;
    pal.setColor(QPalette::WindowText, QRgb(0x404040)) ;
    qApp->setPalette(pal) ;


    S->setCentralWidget(chartView) ;
    S->resize(420,300) ;
    S->show() ;

}

void adminGUI::on_boutton_animerLogo_clicked()
{
    Animation = new QPropertyAnimation(ui->logopic1,"geometry") ;
    Animation->setDuration(4000) ;
    Animation->setStartValue(ui->logopic1->geometry()) ;
    Animation->setEndValue(QRect(10,-100,300,300)) ;
    Animation->start() ;
}
