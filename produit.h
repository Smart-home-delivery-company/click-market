#ifndef PRODUIT_H
#define PRODUIT_H
#include <QLabel>
#include <QPushButton>

class produit
{
public:

    int id ;
    int prix ;
    QString image ;
    QString nom_produit ;


    produit()  ;
    produit(int id , int prix, QString image , QString nom_produit ) ;

    //void on_bouttonpanier_clicked() ;
};

#endif // PRODUIT_H
