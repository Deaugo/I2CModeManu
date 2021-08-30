 #include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Multipages->setCurrentIndex(0);
    //this->fd = initI2C();
    timer = new QTimer(this);
    timer->setSingleShot(true);
    if (fd != -1)
        statusBar()->showMessage("connection I2C initialisée",5000);
    else
        statusBar()->showMessage("Echec initialisation du bus",5000);
}

        // Définition palette led //

const QPalette Led = QPalette();

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SDLMenuButton_released()
{
    ui->Multipages->setCurrentIndex(1);

}

void MainWindow::on_ManuButton_clicked()
{
    ui->Multipages->setCurrentIndex(2);
}

void MainWindow::on_actionSDLMenu_triggered()
{
    ui->Multipages->setCurrentIndex(1);

}

void MainWindow::on_actionMenu_Principal_triggered()
{
    ui->Multipages->setCurrentIndex(0);
}

void MainWindow::on_actionManualMode_triggered()
{
    ui->Multipages->setCurrentIndex(2);
}

void MainWindow::on_actiontest_commande_triggered()
{
    ui->Multipages->setCurrentIndex(3);
}

/*int MainWindow::initI2C()
{
    int countdown = 0;
    fd = wiringPiI2CSetup(DEVICE_ID);
    while(fd==-1)
      {
        if(countdown >=5)
        {
            QMessageBox *initError = new QMessageBox(QMessageBox::Warning,"Problème technique","Echec de l'initialisation du Bus I2C.");
            initError->open();
            return 0;
        }
        countdown++;
      }
    return fd;

}*/



//void MainWindow::on_Supercondamnation_clicked()
//{
//    wiringPiI2CWrite(fd,SConda);
//    wiringPiI2CWrite(fd,0);
//}


//void MainWindow::on_Uncondamn_clicked()
//{
//    wiringPiI2CWrite(fd,Unconda);
//    wiringPiI2CWrite(fd,0);
//}

//void MainWindow::on_Condamn_clicked()
//{
//    wiringPiI2CWrite(fd,Conda);
//    wiringPiI2CWrite(fd,0);
//}

//void MainWindow::data_receive()
//{
//    int data;
//    data = wiringPiI2CRead(fd);
//    if (data!= -1)
//        ui->textEdit->setText("switch activé");
//}





void MainWindow::on_lineEditPin1_editingFinished()
{
    texte = ui->lineEditPin1->text();
    QLineEdit *texteDescrip = new QLineEdit();
    QLineEdit *texteConfig = new QLineEdit();
    texteDescrip->setText(texte);
    texteConfig->setText(texte);
    ui->tableFIEManu->setCellWidget(0,0,texteDescrip);
    ui->tableFIEcmd->setCellWidget(0,0,texteConfig);
}

void MainWindow::on_lineEditPin2_editingFinished()
{
    texte = ui->lineEditPin2->text();
    QLineEdit *texteDescrip = new QLineEdit();
    QLineEdit *texteConfig = new QLineEdit();
    texteDescrip->setText(texte);
    texteConfig->setText(texte);
    ui->tableFIEManu->setCellWidget(1,0,texteDescrip);
    ui->tableFIEcmd->setCellWidget(1,0,texteConfig);
}

void MainWindow::on_lineEditPin3_editingFinished()
{
    texte = ui->lineEditPin3->text();
    QLineEdit *texteDescrip = new QLineEdit();
    QLineEdit *texteConfig = new QLineEdit();
    texteDescrip->setText(texte);
    texteConfig->setText(texte);
    ui->tableFIEManu->setCellWidget(2,0,texteDescrip);
    ui->tableFIEcmd->setCellWidget(2,0,texteConfig);
}

void MainWindow::on_lineEditPin4_editingFinished()
{
    texte = ui->lineEditPin4->text();
    QLineEdit *texteDescrip = new QLineEdit();
    QLineEdit *texteConfig = new QLineEdit();
    texteDescrip->setText(texte);
    texteConfig->setText(texte);
    ui->tableFIEManu->setCellWidget(3,0,texteDescrip);
    ui->tableFIEcmd->setCellWidget(3,0,texteConfig);
}

void MainWindow::on_lineEditPin5_editingFinished()
{
    texte = ui->lineEditPin5->text();
    QLineEdit *texteDescrip = new QLineEdit();
    QLineEdit *texteConfig = new QLineEdit();
    texteDescrip->setText(texte);
    texteConfig->setText(texte);
    ui->tableFIEManu->setCellWidget(4,0,texteDescrip);
    ui->tableFIEcmd->setCellWidget(4,0,texteConfig);
}

void MainWindow::on_lineEditPin6_editingFinished()
{
    texte = ui->lineEditPin6->text();
    QLineEdit *texteDescrip = new QLineEdit();
    QLineEdit *texteConfig = new QLineEdit();
    texteDescrip->setText(texte);
    texteConfig->setText(texte);
    ui->tableFIEManu->setCellWidget(5,0,texteDescrip);
    ui->tableFIEcmd->setCellWidget(5,0,texteConfig);
}

void MainWindow::on_lineEditPin7_editingFinished()
{
    texte = ui->lineEditPin7->text();
    QLineEdit *texteDescrip = new QLineEdit();
    QLineEdit *texteConfig = new QLineEdit();
    texteDescrip->setText(texte);
    texteConfig->setText(texte);
    ui->tableFIEManu->setCellWidget(6,0,texteDescrip);
    ui->tableFIEcmd->setCellWidget(6,0,texteConfig);
}

void MainWindow::on_lineEditPin8_editingFinished()
{
    texte = ui->lineEditPin8->text();
    QLineEdit *texteDescrip = new QLineEdit();
    QLineEdit *texteConfig = new QLineEdit();
    texteDescrip->setText(texte);
    texteConfig->setText(texte);
    ui->tableFIEManu->setCellWidget(7,0,texteDescrip);
    ui->tableFIEcmd->setCellWidget(7,0,texteConfig);
}


void MainWindow::on_comboBoxPin1_currentIndexChanged(int index)
{
    texte = ui->comboBoxPin1->currentText();
    QLineEdit *textePin = new QLineEdit();
    QLineEdit *textePin2 = new QLineEdit();
    textePin->setText(texte);
    textePin2->setText(texte);
    ui->tableFIEManu->setCellWidget(0,1,textePin);
    ui->tableFIEcmd->setCellWidget(0,1,textePin2);
    //comRelai(30, index);
    ConfigButton(30,index);

}

void MainWindow::on_comboBoxPin2_currentIndexChanged(int index)
{
    texte = ui->comboBoxPin2->currentText();
    QLineEdit *textePin = new QLineEdit();
    QLineEdit *textePin2 = new QLineEdit();
    textePin->setText(texte);
    textePin2->setText(texte);
    ui->tableFIEManu->setCellWidget(1,1,textePin);
    ui->tableFIEcmd->setCellWidget(1,1,textePin2);
    //comRelai(31, index);
    ConfigButton(31,index);
}

void MainWindow::on_comboBoxPin3_currentIndexChanged(int index)
{
    texte = ui->comboBoxPin3->currentText();
    QLineEdit *textePin = new QLineEdit();
    QLineEdit *textePin2 = new QLineEdit();
    textePin->setText(texte);
    textePin2->setText(texte);
    ui->tableFIEManu->setCellWidget(2,1,textePin);
    ui->tableFIEcmd->setCellWidget(2,1,textePin2);
    //comRelai(32, index);
    ConfigButton(32,index);
}

void MainWindow::on_comboBoxPin4_currentIndexChanged(int index)
{
    texte = ui->comboBoxPin4->currentText();
    QLineEdit *textePin = new QLineEdit();
    QLineEdit *textePin2 = new QLineEdit();
    textePin->setText(texte);
    textePin2->setText(texte);
    ui->tableFIEManu->setCellWidget(3,1,textePin);
    ui->tableFIEcmd->setCellWidget(3,1,textePin2);
    //comRelai(33, index);
    ConfigButton(33,index);
}

void MainWindow::on_comboBoxPin5_currentIndexChanged(int index)
{
    texte = ui->comboBoxPin5->currentText();
    QLineEdit *textePin = new QLineEdit();
    QLineEdit *textePin2 = new QLineEdit();
    textePin->setText(texte);
    textePin2->setText(texte);
    ui->tableFIEManu->setCellWidget(4,1,textePin);
    ui->tableFIEcmd->setCellWidget(4,1,textePin2);
    //comRelai(34, index);
    ConfigButton(34,index);
}

void MainWindow::on_comboBoxPin6_currentIndexChanged(int index)
{
    texte = ui->comboBoxPin6->currentText();
    QLineEdit *textePin = new QLineEdit();
    QLineEdit *textePin2 = new QLineEdit();
    textePin->setText(texte);
    textePin2->setText(texte);
    ui->tableFIEManu->setCellWidget(5,1,textePin);
    ui->tableFIEcmd->setCellWidget(5,1,textePin2);
    //comRelai(35, index);
    ConfigButton(35,index);
}

void MainWindow::on_comboBoxPin7_currentIndexChanged(int index)
{
    texte = ui->comboBoxPin7->currentText();
    QLineEdit *textePin = new QLineEdit();
    QLineEdit *textePin2 = new QLineEdit();
    textePin->setText(texte);
    textePin2->setText(texte);
    ui->tableFIEManu->setCellWidget(6,1,textePin);
    ui->tableFIEcmd->setCellWidget(6,1,textePin2);
    //comRelai(36, index);
    ConfigButton(36,index);
}

void MainWindow::on_comboBoxPin8_currentIndexChanged(int index)
{
    texte = ui->comboBoxPin8->currentText();
    QLineEdit *textePin = new QLineEdit();
    QLineEdit *textePin2 = new QLineEdit();
    textePin->setText(texte);
    textePin2->setText(texte);
    ui->tableFIEManu->setCellWidget(7,1,textePin);
    ui->tableFIEcmd->setCellWidget(7,1,textePin2);
    //comRelai(37, index);
    ConfigButton(37,index);

}

//void MainWindow::MajTableauPin(int index, QLineEdit *textePin, QLineEdit *textePin2)
//{
//    switch (index)
//    {
//        case 1 :
//        {
//            textePin->setText("N/A");
//            textePin2->setText("N/A");
//            break;
//        }
//        case 2 :
//        {
//            textePin->setText("Commande Moteur");
//            textePin2->setText("Commande Moteur");
//            break;
//        }
//        case 3 :
//        {
//            textePin->setText("GND");
//            textePin2->setText("GND");
//            break;
//        }
//        case 4 :
//        {
//            textePin->setText("Data Switch");
//            textePin2->setText("Data Switch");
//            break;
//        }
//        case 5 :
//        {
//            textePin->setText("Data BUS");
//            textePin2->setText("Data BUS");
//            break;
//        }
//        case 6 :
//        {
//            textePin->setText("Clock BUS");
//            textePin2->setText("Clock BUS");
//            break;
//        }
//    }
//}

void MainWindow::on_pushButton_2_clicked()
{
    //ui->tableFIEcmd->setHidden(false);
    ui->Multipages->setCurrentIndex(3);
}

/*void MainWindow::comRelai(int relai, int index)
{
    wiringPiI2CWrite(fd,relai);
    timer->start(200);
    wiringPiI2CWrite(fd,index);
}*/

//    wiringPiI2CWrite(fd,relai);
//    int i = 0;
//    tempo = false;
//    while (data != relai && tempo != true)
//    {
//       for (i=0;i<10;i++)
//       {
//         data = wiringPiI2CRead(fd);
//         timer->start(200);
//       }
//      tempo = true;
//    }
//    if (tempo == true)
//        statusBar()->showMessage("Erreur de transmission",1000);
//    else
//        {
//            statusBar()->showMessage("Signal reçu et confirmée: ");
//            wiringPiI2CWrite(fd,index);
//            timer->start(2000);
//            statusBar()->showMessage("Signal envoyée");
//        }
//}

//bool MainWindow::temporisation()
//{
//    bool fin = false;
//    timer->start(5000);
//    fin = true;
//    return fin;
//}


void MainWindow::on_actionPlein_Ecran_toggled(bool arg1)
{
    if (arg1==true)
        this->showFullScreen();
    else if (arg1==false)
        this->showNormal();
}

void MainWindow::ConfigButton(int relai, int index)
{
    if (index == 2)
        Conda = relai-8;
    else if (index == 3)
        Unconda = relai-8;
    else if (index == 4)
        SConda = relai-8;
    else {}
}

