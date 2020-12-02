#ifndef ASSOCIERCLIENT_H
#define ASSOCIERCLIENT_H

#include <QDialog>

namespace Ui {
class AssocierClient;
}

class AssocierClient : public QDialog
{
    Q_OBJECT

public:
    explicit AssocierClient(QWidget *parent = nullptr);
    ~AssocierClient();
    bool association_faite = false ;
    QString email_asc ;
    QString nom_asc ;
    QString prenom_asc ;
    int cin_asc ;
    int tel_asc ;
    int points_asc ;
    int id_asc ;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::AssocierClient *ui;
    void trouver_client() ;
};
bool Association_Retour(bool x) ;
QString  Email_Associer (QString x) ;

#endif // ASSOCIERCLIENT_H
