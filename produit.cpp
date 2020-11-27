#include "produit.h"

produit::produit()
{

}

produit::produit(int id , int prix,  QString image , QString nom_produit )
{
    this->id = id ;
    this->prix = prix ;
    this->nom_produit = nom_produit ;
    this->image = image ;


}

