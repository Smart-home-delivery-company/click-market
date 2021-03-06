#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>

namespace Ui {
class client;
}

class client : public QMainWindow
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();

private slots:
    void on_button_deconnecter_clicked();

private:
    Ui::client *ui;
};

#endif // CLIENT_H
