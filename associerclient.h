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

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::AssocierClient *ui;
};
bool Association_Retour(bool x) ;

#endif // ASSOCIERCLIENT_H
