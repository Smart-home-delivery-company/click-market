#ifndef AJOUTERPRODUIT_H
#define AJOUTERPRODUIT_H
#include "login.h"
#include <QDialog>
#include "produit.h"
#include <QPushButton>

namespace Ui {
class AjouterProduit;
}

class AjouterProduit :  public QDialog
{
    Q_OBJECT

public:
    explicit AjouterProduit(QWidget *parent = nullptr);
    ~AjouterProduit();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::AjouterProduit *ui;
};

#endif // AJOUTERPRODUIT_H
