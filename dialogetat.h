#ifndef DIALOGETAT_H
#define DIALOGETAT_H

#include <QDialog>
//test
namespace Ui {
class Dialogetat;
}

class Dialogetat : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogetat(QWidget *parent = nullptr);
    ~Dialogetat();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_2_clicked();

    void on_tableWidget_etat_cellDoubleClicked(int row, int column);

    void on_maj_save_clicked();

    void on_maj_cancel_clicked();


    void on_Menu_clicked();

private:
    Ui::Dialogetat *ui;
};

#endif // DIALOGETAT_H
