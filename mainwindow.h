#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<Employe.h>
#include<compte.h>
#include"ramassage.h"
#include"zone_verte.h"
#include"capteur_humidite.h"
#include "evenement.h"
#include "citoyen.h"
#include"Capt_Pression.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

/*************************************** Begin Wassim ****************************************/
    void on_pushButton_aj_clicked();

    void on_pushButton_Annuler_AJ_clicked();

    void on_pushButton_Annuler_MAJ_clicked();

    void on_pushButton_Save_MAJ_clicked();

    void on_pushButton_compte_clicked();


    void on_pushButton_Annuler_compte_clicked();

    void on_pushButton_Ajout_compte_clicked();


    void on_pushButton_Annuler_compte_MAJ_clicked();

    void on_pushButton_Save_compte_clicked();

    void on_pushButton_Save_compte_MAJ_clicked();

    void on_pushButton_Menu_compte_clicked();


    void on_pushButton_Close_Em_maj_clicked();

    void on_pushButton_Close_Em_AJ_clicked();

 void on_pushButton_Close_compte_MAJ_clicked();
void on_pushButton_Close_compte_AJ_clicked();
void on_pushButton_Environ_pressed();

void on_pushButton_Environ_clicked();

void on_pushButton_Marche_clicked();

void on_pushButton_Marche_pressed();

void on_pushButton_MP_pressed();

void on_pushButton_MP_clicked();

void on_pushButton_Maintenance_clicked();

void on_pushButton_Maintenance_pressed();

void on_pushButton_RH_clicked();

void on_pushButton_RH_pressed();

void on_pushButton_employe_clicked();

void on_pushButton_Menu_RH_clicked();

void load();

void showContextMenu(const QPoint &pos);

void viewcompte();
void editcompte();
void deletecompte();
void viewemploye();
void editemploye();
void deleteemploye();
void loade();
void showContextMenue(const QPoint &pos);



void on_pushButton_Save_employe_clicked();




void on_pushButton_annuler_aff_clicked();
void on_lineEdit_recherche_compte_textChanged(const QString &arg1);


void on_pushButton_Close_clicked();


void on_pushButton_Close_em_clicked();


void on_pushButton_Close_affu_clicked();

void on_pushButton_Close_affe_clicked();

void on_pushButton_annuler_affe_clicked();

void on_pushButton_login_clicked();

void on_pushButton_Close_compte_clicked();
void on_pushButton_affiche_compte_clicked();
void on_pushButton_affiche_em_clicked();


void on_lineEdit_recherche_employe_textChanged(const QString &arg1);
/******************************************* End Wassim *****************************************************************/

/***********************************************************************************************************************/
/******************************************* Begin Rima **************************************************************/

void on_pushButton_clicked();

void on_pushButton_Save_AJ_clicked();

void on_pushButton_Annuler_AJ_R_clicked();

void on_pushButton_Annuler_MAJ_R_clicked();

void on_pushButton_SaveR_MAJ_clicked();

void on_pushButton_ZV_clicked();

void on_pushButton_Annuler_ZV_clicked();

void on_pushButton_Menu_Environ_Aff_clicked();

void on_pushButton_Ajout_ZV_clicked();

void on_pushButton_Annuler_ZV_MAJ_clicked();

void on_pushButton_Save_ZV_clicked();

void on_pushButton_Save_ZV_MAJ_clicked();

void on_pushButton_Menu_Environ_Aff_ZV_clicked();

void on_pushButton_Close_Envir_clicked();

void on_pushButton_Close_Envir_2_clicked();

void on_pushButton_Close_Envir_3_clicked();

void on_pushButton_Close_Envir_4_clicked();

void on_pushButton_Close_Envir_5_clicked();

void on_pushButton_Close_Envir_6_clicked();

void on_pushButton_Close_Envir_8_clicked();





void on_pushButton_R_clicked();

void on_tableView_ZV_activated(const QModelIndex &index);

void on_tableView_Ramas_activated(const QModelIndex &index);

void on_pushButton_MAJ_Ramas_clicked();

void on_pushButton_MAJ_ZV_clicked();

void on_pushButton_Delete_Ramas_clicked();

void on_pushButton_Sup_ZV_clicked();

void on_lineEdit_recherche_ZV_returnPressed();

void on_lineEdit_recherche_R_returnPressed();


void on_pushButton_StatR_clicked();


void on_pushButton_Menu_Environ_Aff_2_clicked();


void on_comboBox_TypeRech_Ramas_currentIndexChanged(int index);
void on_comboBox_TypeRech_ZV_currentIndexChanged(int index);


void on_pushButton_Imprimer_clicked();

void on_pushButton_Print_clicked();

void on_pushButton_Menu_Environ_Aff_3_clicked();

void update_label();
void on_pushButton_MP_Envi_clicked();

void on_pushButton_MP_Envi_pressed();

void on_pushButton_Environ_Envi_clicked();



void on_pushButton_Marche_Envi_clicked();

void on_pushButton_Marche_Envi_pressed();

void on_pushButton_RH_Envi_clicked();

void on_pushButton_RH_Envi_pressed();

void on_pushButton_Maintenance_Envi_clicked();

void on_pushButton_Maintenance_Envi_pressed();

void on_pushButton_Environ_Envi_pressed();
void on_Date_Stat_dateChanged(const QDate &date);
void on_pushButton_Irrigat_clicked();
/****************************************************** End Rima ************************************************/
/****************************************************************************************************************/
/****************************************Begin Nardine**********************************************************/
void on_pushButton_event_clicked();

void on_pushButton_etat_clicked();


void on_MenuP_clicked();

void on_pushButtonajoutcit_clicked();

void on_pushButton_save_clicked();

void on_pushButton_cancel_clicked();

void on_tri_clicked();

void on_pushButton_maj_event_clicked();

void on_pushButton_del_event_clicked();

void on_maj_save_clicked();

void on_maj_cancel_clicked();

void on_ajouter_cit_clicked();

void on_Menu_2_clicked();

void on_recherche_clicked();

void on_pushButton_save_2_clicked();

void on_pushButton_cancel_2_clicked();

void on_pushButton_impression_clicked();

void on_pushButton_maj_cit_clicked();

void on_pushButton_del_cit_clicked();

void on_majcit_cancel_clicked();

void on_maj_save_2_clicked();

void on_maj_cancel_2_clicked();

void on_Menu_clicked();


void on_tableView_citoyen_activated(const QModelIndex &index);

void on_tableView_event_activated(const QModelIndex &index);

void on_exit_clicked();

void on_pushButton_stat_clicked();

void statistiques();

void on_stat_cancel_clicked();

void on_pushButton_3_clicked();
/**********************************************End Nardine***********************************************************/


/****************************************Begin Semah**********************************************************/

public  slots:
    void DeleteSlotRessource(int);
    void DeleteSlotReclamation(int);

    void ModifierSlotRessource(int);
    void ModifierSlotReclamation(int);

    void on_pushButton_MaintenanceIN_clicked();

    void on_pushButton_Ressource_Materiel_2_clicked();

    void on_pushButton_Reclamations_2_clicked();


    void on_pushButton_backMaintenance_4_clicked();

    void on_pushButton_AnnulerSauvgarderCoomposant_2_clicked();

    void on_pushButton_SauvgarderComposant_2_clicked();

    void on_pushButton_AjouterComposant_2_clicked();

    void on_pushButton_Sauvgarder_Reclamation_2_clicked();

    void on_pushButton_Annuler_Reclamation_2_clicked();

    void on_pushButton_AjouterReclamation_2_clicked();


    void on_MenuP_2_clicked();
    void on_envi_2_clicked();
    void on_res_2_clicked();
    void on_marche_2_clicked();






    void update_btn();
private slots:
    void on_Ressource_Search_2_textChanged(const QString &arg1);

    void on_checkBox_NOM_RESS_2_stateChanged(int arg1);

    void on_checkBox_TYPE_RESS_2_stateChanged(int arg1);

    void on_checkBox_ETAT_RESS_2_stateChanged(int arg1);

    void on_pushButton_backMaintenance_3_clicked();

    void on_checkBox_nature_REc_2_stateChanged(int arg1);

    void on_checkBox_Type_REc_2_stateChanged(int arg1);

    void on_checkBox_Route_REc_2_stateChanged(int arg1);

    void on_Reclamation_Serach_2_textChanged(const QString &arg1);

    void on_Order_2_clicked();

    void on_pushButton_Statistique_2_clicked();

    void on_pushButton_StatMaint_Retour_clicked();

    void on_comboBox_stat_2_currentIndexChanged(int index);


    void on_checkBox_Date_2_stateChanged(int arg1);

/****************************************************** End Semah ************************************************/
/****************************************************************************************************************/
void on_pushButton_Menu_Environ_Aff_ZV_2_clicked();

void on_annuler_clicked();

void on_envi_clicked();

void on_res_clicked();

void on_maintenance_clicked();

void on_marche_clicked();

void on_close_clicked();


void on_pushButton_Ress_BackBTN_clicked();

void on_communication_2_clicked();

private:
    Ui::MainWindow *ui;
    Zone_Verte tmpZV;
    Ramassage tmpR;
   Capteur_humidite C;
   QByteArray data;
   Citoyen Ctmp;
   Evenement Etmp;
   QString ID;
   QPropertyAnimation *animation;
   int num=0;

    Capt_Pression A;
};
#endif // MAINWINDOW_H
