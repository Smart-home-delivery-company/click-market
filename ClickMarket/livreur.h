#ifndef LIVREUR_H
#define LIVREUR_H

#include <QMainWindow>

namespace Ui {
class livreur;
}

class livreur : public QMainWindow
{
    Q_OBJECT

public:
    explicit livreur(QWidget *parent = nullptr);
    ~livreur();

private slots:
    void on_button_deconnecter_clicked();

private:
    Ui::livreur *ui;
};

#endif // LIVREUR_H
