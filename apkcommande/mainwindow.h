#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDebug>
#include <QTimer>
//#include "wiringPiI2C.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString texte, datatext;
    QTableWidgetItem *ItemTexte, *ItemPin;
    QTimer *timer;
    const QPalette Led;
    //QDebug *infoStream;
    int data = 0;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_SDLMenuButton_released();

    void on_actionSDLMenu_triggered();

    void on_actionMenu_Principal_triggered();

    void on_actiontest_commande_triggered();

    //void on_Supercondamnation_clicked();

    //void on_Uncondamn_clicked();

    //void on_Condamn_clicked();

    void on_ManuButton_clicked();

    void on_actionManualMode_triggered();

    void on_lineEditPin1_editingFinished();

    void on_lineEditPin2_editingFinished();

    void on_lineEditPin3_editingFinished();

    void on_lineEditPin4_editingFinished();

    void on_lineEditPin5_editingFinished();

    void on_lineEditPin6_editingFinished();

    void on_lineEditPin7_editingFinished();

    void on_lineEditPin8_editingFinished();

    void on_comboBoxPin1_currentIndexChanged(int index);

    void on_comboBoxPin2_currentIndexChanged(int index);

    void on_comboBoxPin3_currentIndexChanged(int index);

    void on_comboBoxPin4_currentIndexChanged(int index);

    void on_comboBoxPin5_currentIndexChanged(int index);

    void on_comboBoxPin6_currentIndexChanged(int index);

    void on_comboBoxPin7_currentIndexChanged(int index);

    void on_comboBoxPin8_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void on_actionPlein_Ecran_toggled(bool arg1);

private:
    Ui::MainWindow *ui;
    int DEVICE_ID = 0x0b;
    //int initI2C();
    //void MajTableauPin(int, QLineEdit*, QLineEdit*);
    //void comRelai(int,int);
    void ConfigButton(int,int);
    //bool temporisation ();
    int fd = 0;
    bool tempo = false ;
    int index = 0;
    int Conda = 0;
    int SConda = 0;
    int Unconda = 0;
};



#endif // MAINWINDOW_H
