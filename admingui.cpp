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

#include <QVBoxLayout>

#include <QMediaPlayer>

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



    QMediaPlayer *music = new QMediaPlayer() ;
    music->setMedia(QUrl("C:/Users/Abdelaziz/Desktop/Qt_Projects/ClickMarket/bgmusic.mp3")) ;
    music->play() ;


    clicksound = new QMediaPlayer() ;
    clicksound->setMedia(QUrl("C:/Users/Abdelaziz/Desktop/Qt_Projects/ClickMarket/ajoutsound.mp3")) ;
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

    if ((id==NULL)||(nom=="")||(prenom=="")||(cin==NULL)||(email=="")||(mdp=="")||(tel==NULL))
    {
        ui->text_result_2->setText("Veuillez vérifier les détails.") ;
    } else
    {

        agent C ;
        bool test = C.supprimer(id.toInt()) ;


        if (test==true)
        {
            clicksound->play() ;
            ui->text_result_2->setText("Client supprimé.") ;
        } else
        {
            ui->text_result_2->setText("Probléme lors de la suppression du client.") ;
        }
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

    if ((id==NULL)||(nom=="")||(prenom=="")||(cin==NULL)||(email=="")||(mdp=="")||(tel==NULL))
    {
        ui->text_result_2->setText("Veuillez vérifier les détails.") ;
    } else
    {
        agent D(id.toInt(),nom,prenom,cin.toInt(),email,mdp,tel.toInt()) ;
        bool test = D.modifer(id.toInt(),nom,prenom,cin.toInt(),email,mdp,tel.toInt()) ;
        if (test==true)
        {
            clicksound->play() ;
            ui->text_result_2->setText("Client modifié avec succés !") ;
        } else
        {
            ui->text_result_2->setText("Probléme lors de la modification.") ;
        }
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
   /* bool menu::verifnom()
    {


        if (text.contains(QRegExp("[^a-zA-Z ]") ) || ui->nomemploye->text().isEmpty())
        {
            ui->nomemploye->clear();

            ui->label_NomControl->setPixmap(falseim);
                ui->nomemploye->setPlaceholderText("contient que des caracteres") ;
            return false;
        }
        else
        {
            ui->label_NomControl->setPixmap(trueim);
            return true;
        }

    } */



    int id = ui->id_2->text().toInt() ;
    QString nom = ui->nom_2->text() ;
    QString prenom = ui->prenom_2->text() ;
    int cin = ui->cin_2->text().toInt() ;
    QString email = ui->email_2->text() ;
    QString mdp = ui->mdp_2->text() ;
    int tel = ui->tel_2->text().toInt() ;


    if ((id==NULL)||(nom=="")||(prenom=="")||(cin==NULL)||(email=="")||(mdp=="")||(tel==NULL)||(mdp.size()<6) || (nom.contains(QRegExp("[^a-zA-Z ]")))||(prenom.contains(QRegExp("[^a-zA-Z ]"))))
    {
        ui->text_result_2->setText("Veuillez vérifier les détails.") ;
    } else
    {
        agent C(id,nom,prenom,cin,email,mdp,tel) ;
        bool test = C.ajouter() ;
        if (test==true)
        {
            clicksound->play() ;


            ui->text_result_2->setText("Agent ajouté.") ;
        } else
        {
            ui->text_result_2->setText("Probléme lors de l'ajout de l'agent.") ;
        }
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

    if ((id==NULL)||(nom=="")||(prenom=="")||(cin==NULL)||(email=="")||(mdp=="")||(tel==NULL))
    {
        ui->text_result_3->setText("Veuillez vérifier les détails.") ;
    } else
    {
        livreurclass D(id.toInt(),nom,prenom,cin.toInt(),email,mdp,tel.toInt()) ;
        bool test = D.modifer(id.toInt(),nom,prenom,cin.toInt(),email,mdp,tel.toInt()) ;
        if (test==true)
        {
            clicksound->play() ;
            ui->text_result_3->setText("Livreur modifié avec succés !") ;
        } else
        {
            ui->text_result_3->setText("Probléme lors de la modification.") ;
        }
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

    if ((id==NULL)||(nom=="")||(prenom=="")||(cin==NULL)||(email=="")||(mdp=="")||(tel==NULL))
    {
        ui->text_result_3->setText("Veuillez vérifier les détails.") ;
    } else
    {
        livreurclass C ;
        bool test = C.supprimer(id.toInt()) ;


        if (test==true)
        {
            clicksound->play() ;
            ui->text_result_3->setText("Livreur supprimé.") ;
        } else
        {
            ui->text_result_3->setText("Probléme lors de la suppression de l'agent.") ;
        }
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
    if ((id==NULL)||(nom=="")||(prenom=="")||(cin==NULL)||(email=="")||(mdp=="")||(tel==NULL)||(mdp.size()<6)||(nom.contains(QRegExp("[^a-zA-Z ]")))||(prenom.contains(QRegExp("[^a-zA-Z ]"))))
    {
        ui->text_result_3->setText("Veuillez vérifier les détails.") ;
    } else
    {
        livreurclass C(id,nom,prenom,cin,email,mdp,tel) ;
        bool test  = C.ajouter() ;
        if (test==true)
        {
            clicksound->play() ;


            ui->text_result_3->setText("Livreur ajouté.") ;
        } else
        {
            ui->text_result_3->setText("Probléme lors de l'ajout du livreur.") ;
        }
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

        QWidget *w = new QWidget();
        w->setObjectName("Stats");
       QVBoxLayout *layout = new QVBoxLayout;

       QBarSet *set0 = new QBarSet("Electroniques");
       QBarSet *set1 = new QBarSet("Maison");
       QBarSet *set2 = new QBarSet("Fashion");
       QBarSet *set3 = new QBarSet("Sante et beaute");
        QBarSeries *series = new QBarSeries();

        //--------------------------
        QSqlQuery query,query1,query2,query3 ;
            query.prepare("SELECT PRIX from PRODUIT where CATEGORIE = 'ELECTRONIQUE' ") ;
           query.exec() ;
           int e=0 ;
           while (query.next()) {
               QString e1 = query.value(0).toString() ;
               e += e1.toInt() ;
               }

           query1.prepare("SELECT PRIX from PRODUIT where CATEGORIE = 'MAISON' ") ;
          query1.exec() ;
          int m=0 ;
          while (query1.next()) {
              QString e1 = query1.value(0).toString() ;
              m += e1.toInt() ;
              }

          query2.prepare("SELECT PRIX from PRODUIT where CATEGORIE = 'FASHION' ") ;
         query2.exec() ;
         int f=0 ;
         while (query2.next()) {
             QString e1 = query2.value(0).toString() ;
             f += e1.toInt() ;
             }

         query3.prepare("SELECT PRIX from PRODUIT where CATEGORIE = 'SANTE' ") ;
        query3.exec() ;
        int s=0 ;
        while (query3.next()) {
            QString e1 = query3.value(0).toString() ;
            s += e1.toInt() ;
            }




      int   max=0 ;
      if ((e>m)&&(e>f)&&(e>s))
      {
          max = e ;
      } else if ((m>f)&&(m>s))
      {
          max = m ;
      } else if (f>s)
      {
          max = f ;
      } else
      {
          max =s ;
      }

      *set0 << e ;
      series->append(set0);

      *set1 << m ;
      series->append(set1);

      *set2 << f ;
      series->append(set2);

      *set3 << s ;
      series->append(set3);
      //***************************


       QChart *chart = new QChart();
           chart->addSeries(series);
           chart->setTitle("Statisqtues des revenues en DT");
           chart->setAnimationOptions(QChart::SeriesAnimations);

           QStringList categories;
               categories << "Catégories" ;
               QBarCategoryAxis *axisX = new QBarCategoryAxis();
               axisX->append(categories);
               chart->addAxis(axisX, Qt::AlignBottom);
               series->attachAxis(axisX);
               QValueAxis *axisY = new QValueAxis();
                   axisY->setRange(0,max);
                   chart->addAxis(axisY, Qt::AlignLeft);
                   series->attachAxis(axisY);
                   chart->legend()->setVisible(true);
                       chart->legend()->setAlignment(Qt::AlignBottom);



          QChartView *view = new QChartView(chart);
          view->setRenderHint(QPainter::Antialiasing);
           layout->addWidget(view);
           w->setLayout(layout);
           w->resize(620,700);

        w->show();





}

void adminGUI::on_boutton_animerLogo_clicked()
{
    Animation = new QPropertyAnimation(ui->logopic1,"geometry") ;
    Animation->setDuration(4000) ;
    Animation->setStartValue(ui->logopic1->geometry()) ;
    Animation->setEndValue(QRect(10,-100,300,300)) ;
    Animation->start() ;
}




void adminGUI::on_navbar_Accueil_clicked()
{
    ui->stackedWidget->setCurrentIndex(1) ;
}

void adminGUI::on_navbar_Sant_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0) ;
}

void adminGUI::on_navbar_Elect_clicked()
{
    ui->stackedWidget->setCurrentIndex(1) ;
}
