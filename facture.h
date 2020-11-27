#ifndef FACTURE_H
#define FACTURE_H
#include "login.h"
#include <QDialog>
#include <QPixmap>

namespace Ui {
class Facture;
}

class Facture : public QDialog
{
    Q_OBJECT

public:
    explicit Facture(QWidget *parent = nullptr);
    ~Facture();

private:
    Ui::Facture *ui;
};

#endif // FACTURE_H
