#include "login.h"
#include "ui_login.h"
#include <QPixmap>
#include <QPushButton>
#include <QFileDialog>
#include "mainwindow.h"
#include <QMap>
//#include "ui_facture.h"
#include "clientclass.h"
#include <QTableView>
#include <QAbstractTableModel>


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
#include "cartes.h"
#include <QVBoxLayout>


login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{

    ui->setupUi(this);
    QPixmap pix("C:/Users/Abdelaziz/Desktop/Qt_Projects/clickmarketlogo.png") ;
    QPixmap pix1("C:/Users/Abdelaziz/Desktop/Qt_Projects//ClickMarket/shoppingbag_icon.png") ;
    QPixmap pix2("C:/Users/Abdelaziz/Desktop/Qt_Projects/ClickMarket/shoppingcart_icon.png") ;

    ui->logopic1->setPixmap(pix.scaled(300,300,Qt::KeepAspectRatio)) ;
    ui->navbar_card->setPixmap(pix1.scaled(65,65,Qt::KeepAspectRatio)) ;
    ui->label_shopcarticon->setPixmap(pix2.scaled(55,55,Qt::KeepAspectRatio)) ;
    ui->stackedWidget->setCurrentIndex(2) ;
    ui->stackedWidget_3->setCurrentIndex(0) ;
    client_associe=false ;
    QString t = "1212" ;
    //produit P1(100, ui->pushButton_2, ui->total_panier) ;
    connect((ui->finaliser_avecass), SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    int converti = 0 ;




}

login::~login()
{
    delete ui;
}






void login::on_pcportable_next_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1) ;
}

void login::on_pcportable_next_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0) ;
}

void login::on_navbar_Elect_clicked()
{
    ui->stackedWidget->setCurrentIndex(0) ;
    ui->stackedWidget_2->setCurrentIndex(0) ;

}

void login::on_navbar_Accueil_clicked()
{
    ui->stackedWidget->setCurrentIndex(2) ;
}

void login::on_item_1_clicked()
{

    int total = (ui->total_panier->text()).toInt() ;
    total = total + 64 ;
    QString t = QString::number(total) ;
    ui->total_panier->setText(t)   ;
    ui->total_label->setText(ui->total_panier->text()) ;
    ui->label_73->setText(ui->total_panier->text()) ;


}





void login::on_navbar_Sant_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1) ;
}

void login::on_button_deconnecter_clicked()
{
    MainWindow M ;
    M.show() ;

}

void login::on_navbar_Sant_3_clicked()
{
    if (client_associe==true)
    {
        ui->stackedWidget->setCurrentIndex(3) ;
        ui->stackedWidget_3->setCurrentIndex(1) ;
    } else
    {
        ui->stackedWidget->setCurrentIndex(3) ;
    }

}



void login::on_pushButton_16_clicked()
{
    QString emailAsc="" ;
    AssocierClient A ;
    A.exec() ;
    if (A.association_faite==true)
    {
        client_associe=true ;
        ui->stackedWidget_3->setCurrentIndex(1) ;
        ui->email_ascText->setText(A.email_asc) ;

    }

}



void login::on_pushButton_24_clicked()
{
    client_associe=false ;
    ui->stackedWidget->setCurrentIndex(3) ;
}



void login::on_pushButton_17_clicked()
{
    AjouterProduit A ;
    A.exec() ;


}









void login::on_pushButton_4_clicked()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
    ui->input_image->setText(fichier) ;
}


void login::afficher_item(QListWidgetItem *item , produit P)
{
    QString image = P.image ;
    QString nom_prod = P.nom_produit ;
    QString prixproduit = QString::number(P.prix)  ;
    QString id_prod = QString::number(P.id) ;

    item->setText("ID : " + id_prod + "\nArticle : " + nom_prod + "\nPrix : " + prixproduit ) ;
    item->setIcon(QIcon(P.image)) ;



}


int login::chercher_produit(QListWidgetItem *item)
{
    for (QMap<int , QListWidgetItem *> :: iterator it = tab_elec.begin() ; it !=tab_elec.end() ; ++it)
    {

        if ( it.value() == item )
        {
            return it.key() ;
        }
    }

    return -1 ;
}


void login::update_produit(int produit_id, int prix , QString nom , QString image)
{
    for (QList<produit> :: iterator it = tab_produits.begin() ; it !=tab_produits.end() ; ++it)
    {
        if (it->id == produit_id)
        {
            it->prix = prix ;
            it->nom_produit = nom ;
            it->image = image ;
        }


    }
}



void login::on_pushButton_2_clicked()
{
    if ((ui->prix_produit->text()!="")&&(ui->input_image->text()!=""))
    {
        QString image = ui->input_image->text() ;
        QString nom_prod = ui->input_nomprod->text() ;
        int prixproduit = (ui->input_prix->text()).toInt() ;
        int id = (ui->input_id->text()).toInt() ;

        produit P(id,prixproduit,image,nom_prod) ;

        ui->listWidget->setIconSize(QSize(100,100)) ;

        //QPixmap pix11(image) ;



        //QListWidgetItem *item = new QListWidgetItem(QIcon(ui->input_image->text()),"ID : " + P.id +"Article : " + nom_prod + "\nPrix : " + ui->input_prix->text());
        QListWidgetItem *item = new QListWidgetItem ;
        tab_produits.push_back(P) ; // base de donnees
        tab_elec.insert(P.id,item) ;
        afficher_item(item,P) ;
        ui->listWidget->addItem(item) ;

    }
}

void login::on_produit_modification_clicked()
{
    QString image = ui->input_image->text() ;
    QString nom_prod = ui->input_nomprod->text() ;
    int prix = ui->input_prix->text().toInt() ;

    int produit_id = chercher_produit(ui->listWidget->currentItem()) ;
    update_produit(produit_id, prix, nom_prod ,image) ;

    ui->listWidget->currentItem()->setText("ID : " + QString::number(produit_id) + "\nArticle : " + nom_prod + "\nPrix : " + QString::number(prix)) ;
    ui->listWidget->currentItem()->setIcon(QIcon(image)) ;




}

void login::on_produit_suppression_clicked()
{
    int produit_id = chercher_produit(ui->listWidget->currentItem()) ;
    int i=0 ;
    for (QList<produit> :: iterator it = tab_produits.begin() ; it !=tab_produits.end() ; ++it)
    {

        if (it->id == produit_id)
        {
            tab_produits.removeAt(i) ;
        }
        i++;
    }



    delete ui->listWidget->takeItem(ui->listWidget->row(ui->listWidget->currentItem()));
    //ui->listWidget->takeItem(ui->listWidget->currentItem())  ;
}

void login::on_pushButton_3_clicked()
{
    QListWidgetItem *item1 =  new QListWidgetItem(QIcon(ui->listWidget->currentItem()->icon()),ui->listWidget->currentItem()->text()) ;
    QListWidgetItem *item2 =  new QListWidgetItem(QIcon(ui->listWidget->currentItem()->icon()),ui->listWidget->currentItem()->text()) ;
    ui->listWidget_2->setIconSize(QSize(100,100)) ;
    ui->listWidget_3->setIconSize(QSize(100,100)) ;

    ui->listWidget_2->addItem(item1) ;
    ui->listWidget_3->addItem(item2) ;

    int produit_id = chercher_produit(ui->listWidget->currentItem())     ;


    for (QList<produit> :: iterator it = tab_produits.begin() ; it !=tab_produits.end() ; ++it)
    {

        if (it->id == produit_id)
        {
            tab_panier.push_back(*it) ;
        }

    }

    if (converti==1)
    {
        calcul_prix(5) ;
    } else
    {
        calcul_prix(0) ;
    }




}




// ========= retirer produit sans associer client ==============
void login::on_pushButton_5_clicked()
{
      int produit_id = chercher_produit(ui->listWidget_2->currentItem())     ;
    int i=0 ;

    for (QList<produit> :: iterator it = tab_panier.begin() ; it !=tab_panier.end() ; ++it)
    {

        if (it->id == produit_id)
        {
            tab_panier.erase(it) ;
        }
        i++;
    }


    delete ui->listWidget_2->takeItem(ui->listWidget_2->row(ui->listWidget_2->currentItem()));

    if (converti==1)
    {
        calcul_prix(5) ;
    } else
    {
        calcul_prix(0) ;
    }

}

// ========= retirer produit avec associer client ==============
void login::on_pushButton_8_clicked()
{
    delete ui->listWidget_3->takeItem(ui->listWidget->row(ui->listWidget->currentItem()));
}

void login::on_pushButton_6_clicked()
{
    ui->listWidget_2->clear() ;
    tab_panier.clear() ;

    if (converti==1)
    {
        calcul_prix(5) ;
    } else
    {
        calcul_prix(0) ;
    }

}


// =========== Facture =====================

void login::on_pushButton_clicked()
{
    Facture  F ;
    int i=0 , x=200 ;
    float prix = 0 ;

    for (QList<produit> :: iterator it = tab_panier.begin() ; it !=tab_panier.end() ; ++it)
    {
        QLabel *label = new QLabel(&F);

        i++ ;
        label->setText("============  Article "+ QString::number(i) +"  ============\nID : "+ QString::number(it->id) + "\nNom Article : "+ it->nom_produit +"\nPrix : " + QString::number(it->prix) +"\n") ;
        label->move(100,x) ;
        x+=70 ;
        prix += it->prix ;
    }
    ui->total_label->setText(QString::number(prix)) ;

    QLabel *label_total = new QLabel(&F);
    QLabel *label_prixtotal = new QLabel(&F);
    QLabel *label_produit = new QLabel(&F);
    QLabel *label_remise = new QLabel(&F);

    label_total->setText("Total : ") ;
    label_total->move(300,750) ;
    label_total->setStyleSheet("font-family : MS Shell Dlg 2 ; font : 14pt ; font-weight : bold ; ") ;



    label_produit->setText(QString::number(prix)) ;
    label_produit->move(200,140) ;
    label_produit->setStyleSheet("font-family : MS Shell Dlg 2 ; font : 10pt ; font-weight : bold ; ") ;

    if (converti==1)
    {
         label_produit->setText("Remise : 5%") ;
         prix = prix - (prix*5/100) ;
    } else
    {
        label_produit->setText("Remise : 0%") ;
    }

    label_produit->move(100,170) ;
    label_produit->setStyleSheet("font-family : MS Shell Dlg 2 ; font : 10pt ; font-weight : bold ; ") ;


    label_prixtotal->setText(QString::number(prix)) ;
    label_prixtotal->move(380,750) ;
    label_prixtotal->setStyleSheet("font-family : MS Shell Dlg 2 ; font : 14pt ; font-weight : bold ; ") ;


    F.exec() ;

    delete (label_total) ;
    delete (label_prixtotal) ;
    delete (label_produit) ;
    delete(label_remise) ;

}

// ================= Prix ==============================
void login::calcul_prix(int remise)
{
    float prix = 0 ;
    for (QList<produit> :: iterator it = tab_panier.begin() ; it !=tab_panier.end() ; ++it)
    {
         prix+=it->prix ;
    }
    prix = prix - (prix*remise/100) ;
    ui->total_label->setText(QString::number(prix)) ;
    ui->total_avecAss->setText(QString::number(prix)) ;

}


void login::on_boutton_convertir_points_clicked()
{
    if (ui->points_fidelites->text().toInt() > 100)
    {
        int x = ui->points_fidelites->text().toInt()-100 ;
        ui->points_fidelites->setText(QString::number(x)) ;
        ui->pourcentage->setText("5") ;

    }
    calcul_prix(5) ;
    converti = 1 ;
}



void login::on_supprimer_compte_associe_clicked()
{
    converti = 0 ;
    ui->stackedWidget_3->setCurrentIndex(0) ;
    ui->pourcentage->setText("0") ;
    calcul_prix(0) ;
}




// ============== Ajouter compte client
void login::on_signup_boutton_clicked()
{


}


// ============== Cliquer sur Gestion Client
void login::on_navbar_Sant_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(5) ;
}

void login::on_boutton_chargerclients_clicked()
{
    clientclass C ;
    bool test = C.charger_clients(ui->tableView) ;
    if (test==true)
    {
        ui->text_result->setText("Liste des clients chargée avec succés !") ;
    } else
    {
        ui->text_result->setText("Probléme lors du chargement.") ;
    }


}

void login::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString() ;
    clientclass C ;
    C.table_click_client(val,ui->id,ui->nom,ui->prenom, ui->cin, ui->email,ui->mdp, ui->tel, ui->points);
}

void login::on_boutton_supprimerclient_clicked()
{
    QString id = ui->id->text() ;
    QString nom = ui->nom->text() ;
    QString prenom = ui->prenom->text() ;
    QString cin = ui->cin->text() ;
    QString email = ui->email->text() ;
    QString mdp = ui->mdp->text() ;
    QString tel = ui->tel->text() ;
    QString points = ui->points->text() ;
    clientclass C ;
    bool test = C.supprimer(id.toInt()) ;


    if (test==true)
    {
        ui->text_result->setText("Client supprimé.") ;
    } else
    {
        ui->text_result->setText("Probléme lors de la suppression du client.") ;
    }
}

void login::on_boutton_modifierclient_clicked()
{
    QString id = ui->id->text() ;
    QString nom = ui->nom->text() ;
    QString prenom = ui->prenom->text() ;
    QString cin = ui->cin->text() ;
    QString email = ui->email->text() ;
    QString mdp = ui->mdp->text() ;
    QString tel = ui->tel->text() ;
    QString points = ui->points->text() ;


    clientclass D(id.toInt(),nom,prenom,cin.toInt(),email,mdp,tel.toInt(),points.toInt()) ;
    bool test = D.modifer(id.toInt(),nom,prenom,cin.toInt(),email,mdp,tel.toInt(),points.toInt()) ;


    if (test==true)
    {
        ui->text_result->setText("Client modifié avec succés !") ;
    } else
    {
        ui->text_result->setText("Probléme lors de la modification.") ;
    }

}

void login::on_boutton_rechercher_clicked()
{
    QString val = ui->input_recherche->text();
    clientclass C ;
    C.rechercher_client(val,ui->comboBox_2,ui->tableView) ;
}




void login::on_boutton_trier_clicked()
{
    clientclass C ;
    C.trier_client(ui->comboBox,ui->tableView,ui->text_result) ;
}

void login::on_boutton_ajouter_clicked()
{
    QString id = ui->id->text() ;
    QString nom = ui->nom->text() ;
    QString prenom = ui->prenom->text() ;
    QString cin = ui->cin->text() ;
    QString email = ui->email->text() ;
    QString mdp = ui->mdp->text() ;
    QString tel = ui->tel->text() ;
    QString points = ui->points->text() ;

    if ((id==NULL)||(nom=="")||(prenom=="")||(cin==NULL)||(email=="")||(mdp=="")||(tel==NULL)||(mdp.size()<6)||(nom.contains(QRegExp("[^a-zA-Z ]")))||(prenom.contains(QRegExp("[^a-zA-Z ]"))))
    {
        ui->text_result->setText("Veuillez vérifier les détails.") ;
    } else
    {
        clientclass D(id.toInt(),nom,prenom,cin.toInt(),email,mdp,tel.toInt(),points.toInt()) ;
        bool test = D.ajouter() ;


        if (test==true)
        {
            ui->text_result->setText("Client ajouté avec succés !") ;
        } else
        {
            ui->text_result->setText("Probléme lors de l'ajout du client.") ;
        }
    }


}

void login::on_navbar_Sant_5_clicked()
{

}

void login::on_finaliser_avecass_clicked()
{
    carte = new Cartes ;
    carte->show() ;
}
