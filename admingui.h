#ifndef ADMINGUI_H
#define ADMINGUI_H

#include <QMainWindow>

namespace Ui {
class adminGUI;
}

class adminGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminGUI(QWidget *parent = nullptr);
    ~adminGUI();

private slots:
    void on_tableView_2_activated(const QModelIndex &index);

    void on_signup_boutton_2_clicked();

    void on_boutton_chargerclients_2_clicked();

    void on_boutton_supprimerclient_2_clicked();

    void on_boutton_modifierclient_2_clicked();

    void on_boutton_rechercher_2_clicked();

    void on_signup_boutton_3_clicked();

    void on_boutton_chargerclients_3_clicked();

    void on_tableView_3_activated(const QModelIndex &index);

    void on_boutton_modifierclient_3_clicked();

    void on_boutton_rechercher_3_clicked();

    void on_boutton_supprimerclient_3_clicked();

private:
    Ui::adminGUI *ui;
};

#endif // ADMINGUI_H
