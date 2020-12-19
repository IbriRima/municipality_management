#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ramassage.h"
#include"zone_verte.h"
#include"capteur_humidite.h"
#include"connection.h"
#include<QMessageBox>
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QtMultimedia/QMediaPlayer>
#include <QPropertyAnimation>
#include <QSqlError>
#include <QModelIndex>
#include <QDate>
#include <QMovie>
#include <QSize>
#include <QSortFilterProxyModel>
#include <QtCharts>
#include <QLineSeries>
#include <QtCore>
#include <QHeaderView>
#include <QGridLayout>
#include <QPrinter>
#include <QPrintDialog>
#include <QAbstractItemView>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

/******* Voir 1216 ******/
    ui->setupUi(this);
    /*********** Neww ****************/
  ui->comboBox_Type_Tri->addItem("Choisisser le critère de tri");
   ui->comboBox_Type_Tri->addItem("Aucun critère de tri");
       ui->comboBox_Type_Tri->addItem("Tri selon le nom de cartier");
        ui->comboBox_Type_Tri->addItem("Tri selon le nombre de poubelle");
         ui->comboBox_Type_Tri->addItem("Tri selon la date");
        ui->tri_ramassage->hide();
     /*********** Neww ****************/


       //Add items to comoBox_AdresseAJ

ui->stackedWidget_Environnement->setCurrentIndex(0);
ui->comboBox_NomCartier_AJ->addItem("EL Menzah 1 ");
ui->comboBox_NomCartier_AJ->addItem("EL Menzah 4");
ui->comboBox_NomCartier_AJ->addItem("EL Menzah 5 ");
ui->comboBox_NomCartier_AJ->addItem("EL Menzah 6");
ui->comboBox_NomCartier_AJ->addItem("EL Menzah 7");
ui->comboBox_NomCartier_AJ->addItem("EL Menzah 8");
ui->comboBox_NomCartier_AJ->addItem("EL Menzah 9");
ui->comboBox_NomCartier_AJ->addItem("Ennasr 1");
ui->comboBox_NomCartier_AJ->addItem("Ennasr 2");
ui->comboBox_NomCartier_AJ->addItem("Riadh andalous");

ui->comboBox_NomCartier_MAJ->addItem("EL Menzah 1 ");
ui->comboBox_NomCartier_MAJ->addItem("EL Menzah 4");
ui->comboBox_NomCartier_MAJ->addItem("EL Menzah 5 ");
ui->comboBox_NomCartier_MAJ->addItem("EL Menzah 6");
ui->comboBox_NomCartier_MAJ->addItem("EL Menzah 7");
ui->comboBox_NomCartier_MAJ->addItem("EL Menzah 8");
ui->comboBox_NomCartier_MAJ->addItem("EL Menzah 9");
ui->comboBox_NomCartier_MAJ->addItem("Ennasr 1");
ui->comboBox_NomCartier_MAJ->addItem("Ennasr 2");
ui->comboBox_NomCartier_MAJ->addItem("Riadh andalous");

ui->comboBox_Adresse_ZV_AJ->addItem("Ave Ariana Les Roses");
ui->comboBox_Adresse_ZV_AJ->addItem("Rue el amine chebbi");
ui->comboBox_Adresse_ZV_AJ->addItem("Rue Kaboul");
ui->comboBox_Adresse_ZV_AJ->addItem("Amilcar");
ui->comboBox_Adresse_ZV_AJ->addItem("Rue Hanoun");
ui->comboBox_Adresse_ZV_AJ->addItem("Avenue Abdellaziz Thaalbi");



ui->lineEdit_recherche_R->setPlaceholderText("Chercher ");
ui->lineEdit_recherche_ZV->setPlaceholderText("Chercher ");
//Critère Recherche
ui->comboBox_TypeRech_Ramas->setCurrentIndex(0);
ui->comboBox_TypeRech_Ramas->addItem("Choississez un critère ");
ui->comboBox_TypeRech_Ramas->addItem("Identifiant");
ui->comboBox_TypeRech_Ramas->addItem("Matricule camion");
ui->comboBox_TypeRech_Ramas->addItem("Date");
ui->comboBox_TypeRech_Ramas->addItem("Nombre de poubelles");
ui->comboBox_TypeRech_Ramas->addItem("Duree");
ui->comboBox_TypeRech_Ramas->addItem("Heure début");
ui->comboBox_TypeRech_Ramas->addItem("Nom Cartier");

ui->comboBox_TypeRech_ZV->setCurrentIndex(0);
ui->comboBox_TypeRech_ZV->addItem("Choississez un critère ");
ui->comboBox_TypeRech_ZV->addItem("Identifiant");
ui->comboBox_TypeRech_ZV->addItem("Libellé");
ui->comboBox_TypeRech_ZV->addItem("Adresse");
ui->comboBox_TypeRech_ZV->addItem("Aire");
/******************************/


//Contrainte de saisie Aire
ui->lineEdit_Aire_ZV_AJ->setValidator(new QIntValidator(0,999999, this));
ui->lineEdit_Aire_MAJ_ZV->setValidator(new QIntValidator(0,999999, this));
ui->lineEdit_IDChauffeurAJ->setValidator(new QIntValidator(0,99999999, this));

ui->lineEdit_IDEmpl1_Rama->setValidator(new QIntValidator(0,99999999, this));

ui->lineEdit_IDEmpl2_Rama->setValidator(new QIntValidator(0,99999999, this));


QRegularExpression rx("[0-9][0-9][0-9]TN[0-9][0-9][0-9][0-9][0-9] ");
QValidator *validator = new QRegularExpressionValidator(rx, this);
ui->lineEdit_Matricule_MAJ->setValidator(validator);
ui->lineEdit_MatriculeAJ->setValidator(validator);
//Affichage Tab ZV
     ui->tableView_ZV ->setModel(tmpZV.afficher());
     ui->tableView_ZV ->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


//Affichage Tab Ramassage
  ui->tableView_Ramas->setModel(tmpR.afficher());
  ui->tableView_Ramas->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);



 ui->tableWidget->hide();

//Delete gif
auto movie = new QMovie(this);
movie->setFileName("C:/Users/user/Desktop/Rima/Environnement/gifs2.gif");
QSize size(100,100);
  connect(movie, &QMovie::frameChanged, [=]{
    ui->pushButton_Delete_Ramas->setIcon(movie->currentPixmap());
  });
ui->pushButton_Delete_Ramas->setIconSize(size);
 connect(movie, &QMovie::frameChanged, [=]{
    ui->pushButton_Sup_ZV->setIcon(movie->currentPixmap());
  });
ui->pushButton_Delete_Ramas->setIconSize(size);

ui->pushButton_Sup_ZV->setIconSize(size);
movie->start();
movie->setSpeed(200);


//Modifier gif

  auto movie2 = new QMovie(this);

  movie2->setFileName("C:/Users/user/Desktop/Rima/Environnement/crayons.gif");
    connect(movie2, &QMovie::frameChanged, [=]{
      ui->pushButton_MAJ_Ramas->setIcon(movie2->currentPixmap());
    });

  ui->pushButton_Delete_Ramas->setIconSize(size);
   connect(movie2, &QMovie::frameChanged, [=]{
      ui->pushButton_MAJ_ZV->setIcon(movie2->currentPixmap());
    });
  ui->pushButton_MAJ_Ramas->setIconSize(size);
  ui->pushButton_MAJ_ZV->setIconSize(size);

    movie2->start();
    movie2->setSpeed(50);

 //Search gif

    auto movie3 = new QMovie(this);
    QSize size2(31,31);
    movie3->setFileName("C:/Users/user/Desktop/Rima/Environnement/loupe_anim.gif");
    connect(movie3, &QMovie::frameChanged, [=]{
      ui->pushButton_Icon_serachZV->setIcon(movie3->currentPixmap());

    });
    ui->pushButton_Icon_serachZV->setIconSize(size2);

    movie3->setFileName("C:/Users/user/Desktop/Rima/Environnement/loupe_anim.gif");
    connect(movie3, &QMovie::frameChanged, [=]{
      ui->pushButton_Icon_serachR->setIcon(movie3->currentPixmap());

    });
    ui->pushButton_Icon_serachR->setIconSize(size2);
    movie3->start();
    movie3->setSpeed(50);

    //print gif
    auto movie4 = new QMovie(this);
    QSize size3(90,71);
    movie4->setFileName("C:/Users/user/Desktop/Rima/Environnement/printer2.gif");
    connect(movie4, &QMovie::frameChanged, [=]{
      ui->pushButton_Print->setIcon(movie4->currentPixmap());
 ui->pushButton_Imprimer->setIcon(movie4->currentPixmap());
    });
    ui->pushButton_Print->setIconSize(size3);
        ui->pushButton_Imprimer->setIconSize(size3);
    movie4->start();
    movie4->setSpeed(230);

    auto movie5 = new QMovie(this);
    QSize size4(90,71);
    movie5->setFileName("C:/Users/user/Desktop/Rima/Environnement/irrigation3.gif");
    connect(movie5, &QMovie::frameChanged, [=]{
      ui->pushButton_Irrigat->setIcon(movie5->currentPixmap());

    });
    ui->pushButton_Irrigat->setIconSize(size4);
    movie5->start();
    movie5->setSpeed(190);
    int test=1 ;
    if(test==0)
     {  ui->pushButton->setDisabled(true);
        ui->pushButton_Ajout_ZV->setDisabled(true);
        ui->pushButton_MAJ_ZV->setDisabled(true);
        ui->pushButton_MAJ_Ramas->setDisabled(true);
        ui->pushButton_Delete_Ramas->setDisabled(true);
        ui->pushButton_Sup_ZV->setDisabled(true);

    }
 //Connection Arduino Capteur Humidité
    int ret=C.connect_capteur_humidite();
  qDebug()<<"ret"<<ret;
  switch(ret)
   {
    case(0):qDebug()<<"arduino is available and connected to: "<<C.get_capteur_humidite_port_name();
    break;
    case(1):qDebug()<<"arduino is available but not connected to:"<<C.get_capteur_humidite_port_name();
    break;
    case(-1):qDebug()<<"arduino is not available";
    break;
    }


}

MainWindow::~MainWindow()
{
    delete ui;

}



//SaveAJ_Ramassage
void MainWindow::on_pushButton_Save_AJ_clicked()
{
Ramassage R;
QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Rima/Environnement/Click2.mp3"));
    player->setVolume(50);
    player->play();
/*************/
//Set Values
R.setIdChauffeur(ui->lineEdit_IDChauffeurAJ->text());
R.setMatricule(ui->lineEdit_MatriculeAJ->text());
//R.setId_Ramassage(ui->lineEdit_IDRamassage_AJ->text());
R.setNom_cartier(ui->comboBox_NomCartier_AJ->currentText());
R.setDate(ui->dateEditR_AJ->date().toString("dd/MM/yyyy"));
R.setHdepart(ui->timeEdit_DebAJ->time());
R.setDuree(ui->timeEdit_DureeAJ->time());
R.setNb_Poubelle(ui->spinBox_NbPoubelle_AJ->text());
R.setId_empl1(ui->lineEdit_IDEmpl1_Rama->text());
R.setId_empl2(ui->lineEdit_IDEmpl2_Rama->text());

bool test;
if(!(ui->lineEdit_IDChauffeurAJ->text().isEmpty()||ui->lineEdit_MatriculeAJ->text().isEmpty()||
     ui->comboBox_NomCartier_AJ->currentText().isEmpty()||ui->dateEditR_AJ->date().isNull()||ui->timeEdit_DebAJ->time().isNull()||ui->timeEdit_DureeAJ->time().isNull()||
    ui->spinBox_NbPoubelle_AJ->cleanText().isEmpty()||ui->lineEdit_IDEmpl1_Rama->text().isEmpty()||ui->lineEdit_IDEmpl2_Rama->text().isEmpty()))
{
test= R.ajouter();

qDebug()<<"Test "<<test;
 if (test)
{
     QString ch;
      bool test1;
     for(int i=0;i<3;i++)
     {if(i==0)
            { ch=R.getIdchauffeur();
             qDebug()<<"ch1: "<<ch;
     test1=R.affectation(ch);
         }
         else if (i==1)
         { ch=R.getId_empl1();
     test1=R.affectation2(ch);
      }
         else if (i==2)
         { ch=R.getId_empl2();
     test1=R.affectation3(ch);
 }
     }
     if(test1)
     {
 QMessageBox::information(this,"Notification","Le rammasage d'identifiant "+R.getId_Ramassage()+" a bien été enregistré ");


  //Affichage
 ui->tableView_Ramas->setModel(tmpR.afficher());




ui->stackedWidget_Environnement->setCurrentIndex(1);


 }
else {QMessageBox::critical(this,"Alerte","Les données entrées sont incorrectes ! ");
        R.SupprimerEmploye(R.getId_Ramassage());
         R.Supprimer(R.getId_Ramassage());
ui->stackedWidget_Environnement->setCurrentIndex(1);

}
}

 ui->lineEdit_IDChauffeurAJ->clear();
 ui->lineEdit_MatriculeAJ->clear();
 ui->dateEditR_AJ->clear();

 ui->timeEdit_DureeAJ->clear();
 ui->timeEdit_DebAJ->clear();
 ui->dateEditR_AJ->clear();
 ui->spinBox_NbPoubelle_AJ->clear();
 ui->lineEdit_IDEmpl1_Rama->clear();
 ui->lineEdit_IDEmpl2_Rama->clear();
}
else QMessageBox::critical(this,"Alerte","Il faut tout remplire ! ");



}


//Ajout_ZV
void MainWindow::on_pushButton_Save_ZV_clicked()
{ Zone_Verte Z;
        //sound
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Rima/Environnement/Click2.mp3"));
        player->setVolume(50);
        player->play();



       if(!(ui->lineEdit_Identifiant_ZV_AJ->text().isEmpty()||ui->comboBox_Adresse_ZV_AJ->currentText().isEmpty()||
             ui->lineEdit_Libelle_ZV_AJ->text().isEmpty()||ui->lineEdit_Aire_ZV_AJ->text().isEmpty()))
        {
    Z.setIdentifiant(ui->lineEdit_Identifiant_ZV_AJ->text());
    Z.setAdresse(ui->comboBox_Adresse_ZV_AJ->currentText());
    Z.setLibelle(ui->lineEdit_Libelle_ZV_AJ->text());
    Z.setAire(ui->lineEdit_Aire_ZV_AJ->text());
    QMessageBox msgB;

    msgB.setText("La zone verte d'identifiant "+Z.getIdentifiant()+" a bien été enregistrée ");
    msgB.exec();
      ui->stackedWidget_Environnement->setCurrentIndex(4);


      //Reset lineEdit
      ui->lineEdit_Identifiant_ZV_AJ->clear();
      ui->lineEdit_Libelle_ZV_AJ->clear();
      ui->lineEdit_Aire_ZV_AJ->clear();
        }
       else
QMessageBox::critical(this,"Alerte","Il faut tout remplire ! ");
//Ajout
Z.ajouter();
//Affichage
ui->tableView_ZV ->setModel(tmpZV.afficher());

}

void MainWindow::on_pushButton_Annuler_ZV_MAJ_clicked()
{
     ui->stackedWidget_Environnement->setCurrentIndex(4);
}


void MainWindow::on_pushButton_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Rima/Environnement/Click2.mp3"));
    player->setVolume(50);
    player->play();
    ui->stackedWidget_Environnement->setCurrentIndex(3);

}


void MainWindow::on_pushButton_Annuler_AJ_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Rima/Environnement/Click2.mp3"));
    player->setVolume(50);
    player->play();
    ui->stackedWidget_Environnement->setCurrentIndex(1);
}

void MainWindow::on_pushButton_Annuler_MAJ_clicked()
{
        QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Rima/Environnement/Click2.mp3"));
        player->setVolume(50);
        player->play();

    ui->stackedWidget_Environnement->setCurrentIndex(1);
}


void MainWindow::on_pushButton_ZV_clicked()
{
    ui->stackedWidget_Environnement->setCurrentIndex(4);
}



void MainWindow::on_pushButton_Annuler_ZV_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Rima/Environnement/Click2.mp3"));
    player->setVolume(50);
    player->play();
    ui->stackedWidget_Environnement->setCurrentIndex(4);
}



void MainWindow::on_pushButton_Menu_Environ_Aff_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Rima/Environnement/Click2.mp3"));
    player->setVolume(50);
    player->play();
     ui->stackedWidget_Environnement->setCurrentIndex(0);
}



void MainWindow::on_pushButton_Ajout_ZV_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Rima/Environnement/Click2.mp3"));
    player->setVolume(50);
    player->play();
    ui->stackedWidget_Environnement->setCurrentIndex(6);
}






void MainWindow::on_pushButton_Menu_Environ_Aff_ZV_clicked()
{QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Rima/Environnement/Click2.mp3"));
    player->setVolume(50);
    player->play();
     ui->stackedWidget_Environnement->setCurrentIndex(0);
}





void MainWindow::on_pushButton_Close_Envir_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_Close_Envir_2_clicked()
{
       QApplication::quit();

}

void MainWindow::on_pushButton_Close_Envir_3_clicked()
{
    QApplication::quit();

}

void MainWindow::on_pushButton_Close_Envir_4_clicked()
{
     QApplication::quit();
}

void MainWindow::on_pushButton_Close_Envir_5_clicked()
{
      QApplication::quit();
}

void MainWindow::on_pushButton_Close_Envir_6_clicked()
{
      QApplication::quit();
}

void MainWindow::on_pushButton_Close_Envir_8_clicked()
{
      QApplication::quit();
}






void MainWindow::on_pushButton_Environ_pressed()
{  QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Rima/Environnement/Click2.mp3"));
    player->setVolume(50);
    player->play();
    QPropertyAnimation *animation= new QPropertyAnimation(ui->pushButton_Environ,"geometry");
         animation->setDuration(2000);
         animation->setStartValue(QRect(20,80, 171,41));
         animation->setEndValue(QRect(60,80,171,41));

         animation->start();

         QPropertyAnimation *animation2= new QPropertyAnimation(ui->pushButton_Environ,"geometry");
              animation2->setDuration(1000);
              animation2->setStartValue(QRect(60,80, 171,41));
              animation2->setEndValue(QRect(20,80,171,41));
                 animation2->start();
  animation->destroyed() ;
    animation2->destroyed() ;
}

void MainWindow::on_pushButton_Environ_clicked()
{
    ui->stackedWidget_Environnement->setCurrentIndex(0);
}



void MainWindow::on_pushButton_Marche_clicked()
{
     ui->stackedWidget_Environnement->setCurrentIndex(1);
}

void MainWindow::on_pushButton_Marche_pressed()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Rima/Environnement/Click2.mp3"));
    player->setVolume(50);
    player->play();
    QPropertyAnimation *animation= new QPropertyAnimation(ui->pushButton_Marche,"geometry");
         animation->setDuration(2000);
         animation->setStartValue(QRect(20,140, 171,41));
         animation->setEndValue(QRect(60,140,171,41));

         animation->start();

         QPropertyAnimation *animation2= new QPropertyAnimation(ui->pushButton_Marche,"geometry");
              animation2->setDuration(1000);
              animation2->setStartValue(QRect(60,140, 171,41));
              animation2->setEndValue(QRect(20,140,171,41));
                 animation2->start();
                 animation->destroyed() ;
                 animation2->destroyed() ;
}

void MainWindow::on_pushButton_MP_pressed()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Rima/Environnement/Click2.mp3"));
    player->setVolume(50);
    player->play();
    QPropertyAnimation *animation= new QPropertyAnimation(ui->pushButton_MP,"geometry");
         animation->setDuration(2000);
         animation->setStartValue(QRect(20,20, 171,41));
         animation->setEndValue(QRect(60,20,171,41));

         animation->start();

         QPropertyAnimation *animation2= new QPropertyAnimation(ui->pushButton_MP,"geometry");
              animation2->setDuration(1000);
              animation2->setStartValue(QRect(60,20, 171,41));
              animation2->setEndValue(QRect(20,20,171,41));
                 animation2->start();
                 animation2->destroyed() ;
                   animation->destroyed() ;
}

void MainWindow::on_pushButton_MP_clicked()
{
     ui->stackedWidget_Environnement->setCurrentIndex(1);
}

void MainWindow::on_pushButton_Maintenance_clicked()
{
     ui->stackedWidget_Environnement->setCurrentIndex(1);
}

void MainWindow::on_pushButton_Maintenance_pressed()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Rima/Environnement/Click2.mp3"));
    player->setVolume(50);
    player->play();
    QPropertyAnimation *animation= new QPropertyAnimation(ui->pushButton_Maintenance,"geometry");
         animation->setDuration(2000);
         animation->setStartValue(QRect(20,260, 171,41));
         animation->setEndValue(QRect(60,260,171,41));

         animation->start();

         QPropertyAnimation *animation2= new QPropertyAnimation(ui->pushButton_Maintenance,"geometry");
              animation2->setDuration(1000);
              animation2->setStartValue(QRect(60,260, 171,41));
              animation2->setEndValue(QRect(20,260,171,41));
                 animation2->start();
                 animation2->destroyed() ;
                   animation->destroyed() ;
}

void MainWindow::on_pushButton_RH_clicked()
{
     ui->stackedWidget_Environnement->setCurrentIndex(1);
}

void MainWindow::on_pushButton_RH_pressed()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Rima/Environnement/Click2.mp3"));
    player->setVolume(50);
    player->play();
    QPropertyAnimation *animation= new QPropertyAnimation(ui->pushButton_RH,"geometry");
         animation->setDuration(2000);
         animation->setStartValue(QRect(20,200, 171,41));
         animation->setEndValue(QRect(60,200,171,41));

         animation->start();

         QPropertyAnimation *animation2= new QPropertyAnimation(ui->pushButton_RH,"geometry");
              animation2->setDuration(1000);
              animation2->setStartValue(QRect(60,200, 171,41));
              animation2->setEndValue(QRect(20,200,171,41));
                 animation2->start();
                 animation2->destroyed() ;
                   animation->destroyed() ;
}



//////////////////////////////////////////////////////

void MainWindow::on_pushButton_R_clicked()
{



    ui->stackedWidget_Environnement->setCurrentIndex(1);

}

//////////////////////////////////////////////////////////////


void MainWindow::on_tableView_ZV_activated(const QModelIndex &index)
{

Zone_Verte Z;
QString ID=ui->tableView_ZV->model()->data(index).toString();

QString Aire,Libelle,Adresse;

      Z. Remplissage(&ID,&Libelle,&Adresse,&Aire);

      ui->lineEdit_ID_Aff_ZV->setText(ID) ;
      ui->lineEdit_Libelle_Aff_ZV->setText(Libelle);
      ui->lineEdit_Adresse_Aff_ZV->setText(Adresse);
       ui->lineEdit_Aire_Aff_ZV->setText(Aire);


          // background: yellow;

 ui->groupBox->setTitle( ui->lineEdit_ID_Aff_ZV->text());
 qDebug()<<"Irrigation";
 QObject::connect(C.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

 ui->tableView_ZV->selectRow( index.row());
//ui->tableView_ZV->setStyleSheet("  alternate-background-color: red;");

}



void MainWindow::on_tableView_Ramas_activated(const QModelIndex &index)
{
Ramassage R;
  QString ID=ui->tableView_Ramas->model()->data(index).toString();

QString Matricule,Id_chauffeur,id_empl1,id_empl2,Date,Nb_poubelle,Nom_Cartier,Duree,Heure;
R.Remplissage(&ID,&Matricule,&Date,&Nb_poubelle,&Nom_Cartier,&Duree,&Heure);

 QVector<QString> tab;

tab= R.afficheremploye(&ID);


ui->lineEdit_ID_Ramas_Aff->setText(ID);
ui->lineEdit_Matricule_Aff->setText(Matricule);
ui->lineEdit_IDChauffeur_Aff->setText(tab[0]);
ui->lineEdit_IDEmploye1_Aff->setText(tab[1]);
ui->lineEdit_IDEmploye2_Aff->setText(tab[2]);
ui->lineEdit_Date_Aff->setText(Date);
ui->lineEdit_NbPoubelle_Aff->setText(Nb_poubelle);
ui->lineEdit_Duree_Aff->setText(Duree);
ui->lineEdit_NomCartier_Aff->setText(Nom_Cartier);
ui->lineEdit_HeureDebut_Aff->setText(Heure);


ui->groupBox_2->setTitle( ui->lineEdit_ID_Ramas_Aff->text());
}






void MainWindow::on_pushButton_Delete_Ramas_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Rima/Environnement/trash.mp3"));
        player->setVolume(50);

Ramassage R;


    QString ID;
     ID=ui->lineEdit_ID_Ramas_Aff->text();

    bool test1=R.SupprimerEmploye(ID);
    if  (test1 &&!( ui->groupBox_2->title().isEmpty()) )
       {   player->play();
   tmpR.Supprimer(ID);
        ui->lineEdit_ID_Ramas_Aff->clear();
        ui->lineEdit_Matricule_Aff->clear();
        ui->lineEdit_IDChauffeur_Aff->clear();
        ui->lineEdit_IDEmploye1_Aff->clear();
        ui->lineEdit_IDEmploye2_Aff->clear();
        ui->lineEdit_Date_Aff->clear();
        ui->lineEdit_NbPoubelle_Aff->clear();
        ui->lineEdit_Duree_Aff->clear();
        ui->lineEdit_NomCartier_Aff->clear();
        ui->lineEdit_HeureDebut_Aff->clear();
         ui->lineEdit_Adresse_Aff_ZV->clear();
        ui->groupBox_2->setTitle("");
        ui->tableView_Ramas->setModel(tmpR.afficher());
        QMessageBox::information(nullptr,QObject::tr("Supprimer un ramassage")
                                 ,QObject::tr("Le ramassage a été supprimé"));

    }
    else if ( ui->groupBox_2->title().isEmpty())
    {
        QMessageBox::critical(nullptr,QObject::tr("Supprimer un ramassage")
                                 ,QObject::tr("Pas de ramassage à supprimer!"));
    }
    player->stop();
}

void MainWindow::on_pushButton_Sup_ZV_clicked()
{
    QString ID;
    ID= ui->lineEdit_ID_Aff_ZV->text();
   bool test= tmpZV.Supprimer(ID);
   if  (test && !( ui->groupBox->title().isEmpty()))
      {
       ui->lineEdit_ID_Aff_ZV->clear();
       ui->lineEdit_Libelle_Aff_ZV->clear();
       ui->lineEdit_Adresse_Aff_ZV->clear();
        ui->lineEdit_Aire_Aff_ZV->clear();
       ui->groupBox->setTitle("");
   ui->tableView_ZV ->setModel(tmpZV.afficher());
       QMessageBox::information(nullptr,QObject::tr("Supprimer une zone verte")
                                ,QObject::tr("La zone verte a été supprimée"));

   }
   else if ( ui->groupBox->title().isEmpty())
   {
       QMessageBox::critical(nullptr,QObject::tr("Supprimer une zone verte")
                                ,QObject::tr("Pas de zone verte à supprimer!"));
   }
}

void MainWindow::on_pushButton_MAJ_ZV_clicked()
{if (ui->groupBox->title().isEmpty())
    {
        QMessageBox::critical(nullptr,QObject::tr("Modifier une zone verte")
                                 ,QObject::tr("Pas de zone verte à modifier!"));
    }
    else
    {
     ui->stackedWidget_Environnement->setCurrentIndex(5);

     ui->lineEdit_ID_MAJ_ZV->setText(ui->lineEdit_ID_Aff_ZV->text());
     ui->lineEdit_Aire_MAJ_ZV->setText(ui->lineEdit_Aire_Aff_ZV->text());
     ui->lineEdit_Libelle_MAJ_ZV->setText(ui->lineEdit_Libelle_Aff_ZV->text());

 ui->lineEdit_ID_MAJ_ZV->setDisabled(true);
    }
}
void MainWindow::on_pushButton_MAJ_Ramas_clicked()
{
    if (ui->groupBox_2->title().isEmpty())
    {
        QMessageBox::critical(nullptr,QObject::tr("Modifier un ramassage")
                                 ,QObject::tr("Pas de ramassage à modifier!"));
    }

    else
    {
    ui->stackedWidget_Environnement->setCurrentIndex(2);
    ui->lineEdit_IDRamassage_MAJ->setText(ui->lineEdit_ID_Ramas_Aff->text());
    ui->lineEdit_Matricule_MAJ->setText(ui->lineEdit_Matricule_Aff->text());

    qDebug()<<"Date: "<<ui->lineEdit_Date_Aff->text();
    ui->dateEditR_MAJ->setDate(QDate::fromString(ui->lineEdit_Date_Aff->text(),"dd/MM/yyyy"));
    ui->spinBox_NbPoubelle_MAJ->setValue(ui->lineEdit_NbPoubelle_Aff->text().toInt());
    ui->timeEdit_DureeMAJ->setTime( QTime::fromString(ui->lineEdit_Duree_Aff->text()));
    ui->comboBox_NomCartier_MAJ->setCurrentText(ui->lineEdit_NomCartier_Aff->text());
    ui->timeEdit_DebMAJ->setTime( QTime::fromString(ui->lineEdit_HeureDebut_Aff->text()));
    ui->lineEdit_IDRamassage_MAJ->setDisabled(true);
    }
}
void MainWindow::on_pushButton_Save_ZV_MAJ_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Rima/Environnement/Click2.mp3"));
    player->setVolume(50);
    player->play();

QString ID,Aire,Libelle,Adresse;
Aire=ui->lineEdit_Aire_MAJ_ZV->text();
Libelle=ui->lineEdit_Libelle_MAJ_ZV->text();
ID= ui->lineEdit_ID_MAJ_ZV->text();
Adresse=ui->lineEdit_Adresse_Aff_ZV->text();
  bool test= tmpZV.Modifier(ID,Libelle,Aire,Adresse);
  if  (test)
     {

  ui->tableView_ZV ->setModel(tmpZV.afficher());
      QMessageBox::information(nullptr,QObject::tr("Modifier une zone verte")
                               ,QObject::tr("La zone verte a été modifiée"));
       ui->stackedWidget_Environnement->setCurrentIndex(4);
Zone_Verte Z;

     Z. Remplissage(&ID,&Libelle,&Adresse,&Aire);

     ui->lineEdit_Libelle_Aff_ZV->setText(Libelle);
     ui->lineEdit_Adresse_Aff_ZV->setText(Adresse);
      ui->lineEdit_Aire_Aff_ZV->setText(Aire);
        }

}



void MainWindow::on_pushButton_SaveR_MAJ_clicked()
{
    QMessageBox msgB;
        Ramassage R;
    //Sound
       QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Rima/Environnement/Click2.mp3"));
        player->setVolume(50);
        player->play();

    //Affichage de l'id à MAJ
 //   ui->lineEdit_IDChauffeurMAJ->setText(ui->lineEdit_IDChauffeur_Aff->text());


    QString ID,Matricule,Id_chauffeur,id_empl1,id_empl2,Date,Nb_poubelle,Nom_Cartier,Duree,Heure;


    //Set des vals à jour
   ID=ui->lineEdit_IDRamassage_MAJ->text();

   Matricule=ui->lineEdit_Matricule_MAJ->text();

    Nom_Cartier=ui->comboBox_NomCartier_MAJ->currentText();
    Date=ui->dateEditR_MAJ->date().toString("dd/MM/yyyy");
    Heure=ui->timeEdit_DebMAJ->time().toString();
    Duree=ui->timeEdit_DureeMAJ->time().toString("HH:mm");
    Nb_poubelle=ui->spinBox_NbPoubelle_MAJ->text();

    bool test= tmpR.Modifier(ID,Matricule,Date,Nb_poubelle,Nom_Cartier,Duree,Heure);


    if  (test)
       {

    ui->tableView_Ramas ->setModel(tmpR.afficher());
        QMessageBox::information(nullptr,QObject::tr("Modifier un ramassage ")
                                 ,QObject::tr("Le ramassage  a été modifié"));


R.Remplissage(&ID,&Matricule,&Date,&Nb_poubelle,&Nom_Cartier,&Duree,&Heure);

ui->lineEdit_Matricule_Aff->setText(Matricule);

ui->lineEdit_Date_Aff->setText(Date);
ui->lineEdit_NbPoubelle_Aff->setText(Nb_poubelle);
ui->lineEdit_Duree_Aff->setText(Duree);
ui->lineEdit_NomCartier_Aff->setText(Nom_Cartier);
ui->lineEdit_HeureDebut_Aff->setText(Heure);
ui->stackedWidget_Environnement->setCurrentIndex(1);
  }





}

void MainWindow::on_comboBox_TypeRech_ZV_currentIndexChanged(int index)
{
    if(index==1)
ui->lineEdit_recherche_ZV->setPlaceholderText("Chercher par Identifiant");
   else  if(index==2)
ui->lineEdit_recherche_ZV->setPlaceholderText("Chercher par Libelle");
    else if (index==3)
        ui->lineEdit_recherche_ZV->setPlaceholderText("Chercher par Adresse");
    else if (index==4)
        ui->lineEdit_recherche_ZV->setPlaceholderText("Chercher par Aire");

}


void MainWindow::on_lineEdit_recherche_ZV_returnPressed()
{
 Zone_Verte z;
  QString ch,ch1;
    int indice=0;
  ch= ui->lineEdit_recherche_ZV->text();
      ui->lineEdit_ID_Aff_ZV->clear() ;
       ui->lineEdit_Libelle_Aff_ZV->clear();
       ui->lineEdit_Adresse_Aff_ZV->clear();
      ui->lineEdit_Aire_Aff_ZV->clear();
      ui->groupBox->setTitle("");
ch1=ui->lineEdit_recherche_ZV->placeholderText();
if(ch1=="Chercher par Identifiant")
  {
    indice=1;
 ui->tableView_ZV->setModel(tmpZV.Recherche(indice,ch));
 ui->comboBox_TypeRech_ZV->setCurrentIndex(0);
 ui->lineEdit_recherche_ZV->setPlaceholderText("Chercher ");

}
else if(ch1=="Chercher par Libelle")
{
    indice=2;
    ui->tableView_ZV->setModel(tmpZV.Recherche(indice,ch));
    ui->comboBox_TypeRech_ZV->setCurrentIndex(0);
    ui->lineEdit_recherche_ZV->setPlaceholderText("Chercher ");
}
else if(ch1=="Chercher par Adresse")
{
    indice=3;
    ui->tableView_ZV->setModel(tmpZV.Recherche(indice,ch));
    ui->comboBox_TypeRech_ZV->setCurrentIndex(0);
    ui->lineEdit_recherche_ZV->setPlaceholderText("Chercher ");
}
else if(ch1=="Chercher par Aire")
{
    indice=4;
    ui->tableView_ZV->setModel(tmpZV.Recherche(indice,ch));
    ui->comboBox_TypeRech_ZV->setCurrentIndex(0);
    ui->lineEdit_recherche_ZV->setPlaceholderText("Chercher ");
}
else if(indice==0 && ch=="")
{  //
  ui->tableView_ZV->setModel(tmpZV.afficher());
}
else if(indice==0 && ch!="")
{
    QMessageBox::critical(this,"Attention","Il faut choisire un critère de recherche");
}

}
void MainWindow::on_comboBox_TypeRech_Ramas_currentIndexChanged(int index)
{
  if(index==1)
      ui->lineEdit_recherche_R->setPlaceholderText("Chercher par Identifiant");
    else if (index==2)
            ui->lineEdit_recherche_R->setPlaceholderText("Chercher par Matricule");
       else if (index==3)
               ui->lineEdit_recherche_R->setPlaceholderText("Chercher par Date");
          else if (index==4)
                ui->lineEdit_recherche_R->setPlaceholderText("Chercher par Nombre de poubelle");
              else if (index==5)
                  ui->lineEdit_recherche_R->setPlaceholderText("Chercher par Durée");
                  else if (index==6)
                       ui->lineEdit_recherche_R->setPlaceholderText("Chercher par Heure Début");
                          else if (index==7)
                               ui->lineEdit_recherche_R->setPlaceholderText("Chercher par Nom Cartier");
}
void MainWindow::on_lineEdit_recherche_R_returnPressed()
{
    QString ch,ch1;
    int indice=0;
  ch= ui->lineEdit_recherche_R->text();

ch1=ui->lineEdit_recherche_R->placeholderText();
if(ch1=="Chercher par Identifiant")
  {
    indice=1;
    ui->tableView_Ramas->setModel(tmpR.Recherche(indice,ch));
     ui->comboBox_TypeRech_Ramas->setCurrentIndex(0);
     ui->lineEdit_recherche_R->setPlaceholderText("Chercher ");

}
else if(ch1=="Chercher par Matricule")
{
    indice=2;
    ui->tableView_Ramas->setModel(tmpR.Recherche(indice,ch));
     ui->comboBox_TypeRech_Ramas->setCurrentIndex(0);
     ui->lineEdit_recherche_R->setPlaceholderText("Chercher ");
}
else if(ch1=="Chercher par Date")
{
    indice=3;
    ui->tableView_Ramas->setModel(tmpR.Recherche(indice,ch));
     ui->comboBox_TypeRech_Ramas->setCurrentIndex(0);
     ui->lineEdit_recherche_R->setPlaceholderText("Chercher ");
}
else if(ch1=="Chercher par Nombre de poubelle")
{
    indice=4;
   ui->tableView_Ramas->setModel(tmpR.Recherche(indice,ch));
    ui->comboBox_TypeRech_Ramas->setCurrentIndex(0);
    ui->lineEdit_recherche_R->setPlaceholderText("Chercher ");
}
else if(ch1=="Chercher par Durée")
{
    indice=5;
    ui->tableView_Ramas->setModel(tmpR.Recherche(indice,ch));
     ui->comboBox_TypeRech_Ramas->setCurrentIndex(0);
     ui->lineEdit_recherche_R->setPlaceholderText("Chercher ");
}
else if(ch1=="Chercher par Heure Début")
{
    indice=6;
    ui->tableView_Ramas->setModel(tmpR.Recherche(indice,ch));
     ui->comboBox_TypeRech_Ramas->setCurrentIndex(0);
     ui->lineEdit_recherche_R->setPlaceholderText("Chercher ");
}
else if(ch1=="Chercher par Nom Cartier")
{
    indice=7;
    ui->tableView_Ramas->setModel(tmpR.Recherche(indice,ch));
     ui->comboBox_TypeRech_Ramas->setCurrentIndex(0);
     ui->lineEdit_recherche_R->setPlaceholderText("Chercher ");
}
else if(indice==0 && ch=="")
{
ui->tableView_Ramas->setModel(tmpR.afficher());
}
else if(indice==0 && ch!="")
{
    QMessageBox::critical(this,"Attention","Il faut choisire un critère de recherche");
}





ui->lineEdit_ID_Ramas_Aff->clear();
ui->lineEdit_Matricule_Aff->clear();
ui->lineEdit_IDChauffeur_Aff->clear();
ui->lineEdit_IDEmploye1_Aff->clear();
ui->lineEdit_IDEmploye2_Aff->clear();
ui->lineEdit_Date_Aff->clear();
ui->lineEdit_NbPoubelle_Aff->clear();
ui->lineEdit_Duree_Aff->clear();
ui->lineEdit_NomCartier_Aff->clear();
ui->lineEdit_HeureDebut_Aff->clear();
ui->groupBox_2->setTitle("");

}



void MainWindow::on_pushButton_StatR_clicked()
{

   ui->stackedWidget_Environnement->setCurrentIndex(7);
   ui->graphicsView->show();
 ui->tableView_StatR->hide();

 QChart *chart = new QChart;
   QBarSeries *series = new QBarSeries();

  chart->addSeries(series);
  QBarCategoryAxis *axis= new QBarCategoryAxis();
chart->createDefaultAxes();

  chart->setAxisX(axis,series);
    ui->graphicsView->setChart(chart);
        ui->graphicsView->setRenderHint(QPainter::Antialiasing);
        ui->graphicsView->setMinimumSize(800,550);

/*****************************************************************************/

}




void MainWindow::on_pushButton_Menu_Environ_Aff_2_clicked()
{
        ui->stackedWidget_Environnement->setCurrentIndex(0);


}



void MainWindow::on_pushButton_Print_clicked()
{
    if(!ui->groupBox_2->title().isEmpty())
    {ui->stackedWidget_Environnement->setCurrentIndex(8);
            ui->lineEdit_Date_Imp->setText(ui->lineEdit_Date_Aff->text());
             ui->lineEdit_Duree_Imp->setText(ui->lineEdit_Duree_Aff->text());
            ui->lineEdit_IDChauffeur_Imp->setText(ui->lineEdit_IDChauffeur_Aff->text());
            ui->lineEdit_IDEmploye1_Imp->setText(ui->lineEdit_IDEmploye1_Aff->text());
             ui->lineEdit_IDEmploye2_Imp->setText(ui->lineEdit_IDEmploye2_Aff->text());
              ui->lineEdit_ID_Ramas_Imp->setText(ui->lineEdit_ID_Ramas_Aff->text());
               ui->lineEdit_NomCartier_Imp->setText(ui->lineEdit_NomCartier_Aff->text());
                ui->lineEdit_NbPoubelle_Imp->setText(ui->lineEdit_NbPoubelle_Aff->text());
                 ui->lineEdit_HeureDebut_Imp->setText(ui->lineEdit_HeureDebut_Aff->text());
                  ui->lineEdit_Matricule_Imp->setText(ui->lineEdit_Matricule_Aff->text());
    }
    else QMessageBox::critical(this,"Attention","Vous devez choisire un ramassage à imprimer");
}







void MainWindow::on_pushButton_Imprimer_clicked()
{Ramassage R;
    QString ID=ui->lineEdit_ID_Ramas_Imp->text();

    QPrinter printer(QPrinter::HighResolution);

    printer.setCopyCount(1);


        QPrintDialog *dialog = new QPrintDialog(&printer, this);

        dialog->setWindowTitle(tr("Print Document"));
         dialog->addEnabledOption(QAbstractPrintDialog::PrintSelection);


            QPainter painter;

 painter.begin(&printer);


QFile file;
QDir::setCurrent("/tmp");
file.setFileName("back2.jpg");
QDir::setCurrent("C:/Users/user/Desktop/Rima/Smart_Municipality_2A3");
file.open(QIODevice::ReadOnly);
QImage img(file.fileName());
painter.drawImage(0,0,img.scaled(4958,7017, Qt::IgnoreAspectRatio, Qt::FastTransformation));


QFile file2;
QDir::setCurrent("/tmp");
file2.setFileName("municipal.png");
QDir::setCurrent("C:/Users/user/Desktop/Rima/Smart_Municipality_2A3");
file2.open(QIODevice::ReadOnly);
QImage img2(file2.fileName());
painter.drawImage(0,0,img2.scaled(900,1000, Qt::IgnoreAspectRatio, Qt::FastTransformation));



QString Matricule,Id_chauffeur,id_empl1,id_empl2,Date,Nb_poubelle,Nom_Cartier,Duree,Heure;
Id_chauffeur=ui->lineEdit_IDChauffeur_Imp->text();
id_empl1=ui->lineEdit_IDEmploye1_Imp->text();
id_empl2=ui->lineEdit_IDEmploye2_Imp->text();
R.Remplissage(&ID,&Matricule,&Date,&Nb_poubelle,&Nom_Cartier,&Duree,&Heure);

 painter.setFont(QFont("Harlow Solid Italic",30,-1,1));
  painter.setPen(QColor(0,102,204));
painter.drawText(width()+100,height()+600,"Ramassage d'identifiant "+ID+"" );
 painter.setFont(QFont("Berlin Sans FB Demi Bold",15));
   painter.setPen(QColor(0,0,0));
painter.drawText(width()-500,height()+1600,"Matricule du camion:  "+Matricule+"" );
painter.drawText(width()-500,height()+2100,"Nom du cartier:  "+Nom_Cartier+"" );
painter.drawText(width()-500,height()+2600,"Date:  "+Date+"" );
painter.drawText(width()-500,height()+3100,"Heure début:  "+Heure+"" );
painter.drawText(width()-500,height()+3600,"Durée:  "+Duree+"" );

painter.drawText(width()-500,height()+4100,"CIN des employés:  "+Id_chauffeur+" , "+id_empl1+" , "+id_empl2+"" );
painter.drawText(width()-500,height()+4600,"Nombres de poubelles à ramasser:  "+Nb_poubelle+"" );




            painter.end();
}



void MainWindow::on_pushButton_Menu_Environ_Aff_3_clicked()
{
          ui->stackedWidget_Environnement->setCurrentIndex(0);
}




void MainWindow::update_label()
{  int val;
    data=C.read_from_capteur_humidite();
qDebug()<<"Update";
    val=data.toInt();

    if(data.toInt()>600)
      {
        qDebug()<<"Sèche";
          ui->Notif_irrigation->show();
  ui->tableView_ZV->setStyleSheet(" selection-background-color: red ");
      }
        else if(data.toInt()>100&&data.toInt()<550)
    {
        qDebug()<<"Humide";
           ui->Notif_irrigation->hide();
           ui->tableView_ZV->setStyleSheet(" selection-background-color: green  ");
    }

}

void MainWindow::on_ON_clicked()
{

}






void MainWindow::on_Date_Stat_dateChanged(const QDate &date)
{


QBarSet *set0 = new QBarSet("ramassage");

QString ch1,ch2,ch3;
QStringList list1;
ch1=date.toString("MM/yyyy");
        QStringList list, list2;

        Ramassage R;

 ui->tableView_StatR->show();

     ui->tableView_StatR->setModel(tmpR.afficherSTAT(ch1,ch2));


          ui->tableView_StatR->adjustSize();

QVector<Ramassage> tab;


        for( int row = 0; row < ui->tableView_StatR->model()->rowCount(); ++row )
               {   ui->tableWidget->setColumnCount(3);
           ui->tableWidget->insertRow(ui->tableWidget->rowCount());
         for( int col = 0; col < ui->tableView_StatR->model()->columnCount(); ++col )
                 {
                  QModelIndex index =ui->tableView_StatR->model()->index(row,0);
                   QModelIndex index2 =ui->tableView_StatR->model()->index(row,1);
                    QModelIndex index3 =ui->tableView_StatR->model()->index(row,2);
                    list1.append(index.data().toString());
                   R.setId_Ramassage(index.data().toString());
                   R.setNb_Poubelle(index2.data().toString());
                   R.setDate(index3.data().toString());
        ui->tableWidget->hide();
                }
          tab.push_back(R);

        }


        for(int m=0;m<tab.size();m++)
       {
            for(int index=0;index<tab.size();index++)

     {
       if(tab[index].getDate()==tab[m].getDate()&& m!=index)

       {

           tab[index].setId_Ramassage("");
              int x=tab[m].getNbPoubelle().toInt()+tab[index].getNbPoubelle().toInt();
               QString ch=QVariant(x).toString();
               tab[m].setNb_Poubelle(ch);

         }

       }




       for(int k=0;k<tab.size();k++)

        list.append(tab[k].getDate());

       if(tab[m].getId_Ramassage()!="")
       {

    *set0<<tab[m].getNbPoubelle().toInt();


        }
        }



          ui->stackedWidget_Environnement->setCurrentIndex(7);
                QBarSeries *series = new QBarSeries();
                     series->append(set0);

                    QChart *chart = new QChart;
                     chart->addSeries(series);
                     chart->setTitle("Le nombre de ramassages effectués par la municipalité en '"+ch1+"'");
    QFont serifFont("Segoe Print", 15, QFont::Bold);
                     chart->setTitleFont(serifFont);
                chart->setAnimationOptions(QChart::AllAnimations);

                QBarCategoryAxis *axis= new QBarCategoryAxis();
                axis->append(list);

                chart->createDefaultAxes();

                chart->setAxisX(axis,series);
                chart->legend()->setVisible(true);
                chart->legend()->setAlignment(Qt::AlignBottom);
                QPalette pal =  ui->graphicsView->palette();
                pal.setColor(QPalette::Window, QRgb(0x121218));
                pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));

       ui->graphicsView->show();

     ui->graphicsView->setPalette(pal);
            ui->graphicsView->setChart(chart);
            ui->graphicsView->setRenderHint(QPainter::Antialiasing);
            ui->graphicsView->setMinimumSize(800,550);
}








void MainWindow::on_comboBox_Type_Tri_activated(int index)
{
          ui->tableView_Ramas->setModel(tmpR.Tri(index));
          if(index==0)
               {
           ui->tableView_Ramas->setModel(tmpR.afficher());
           ui->tri_ramassage->hide();
          }
          if(index==1)
               {
           ui->tableView_Ramas->setModel(tmpR.afficher());
           ui->tri_ramassage->hide();
          }
          else if(index==2)
         { ui->tri_ramassage->show();
              ui->tri_ramassage->setText("Les ramassages triés selon le nom de cartier");

          }
          else if(index==3)
          { ui->tri_ramassage->show();
               ui->tri_ramassage->setText("Les ramassages triés selon le nombre de ramassage");

           }
          else if(index==4)
          { ui->tri_ramassage->show();
               ui->tri_ramassage->setText("Les ramassages triés selon la date");

           }
           ui->comboBox_Type_Tri->setCurrentIndex(0);
}
