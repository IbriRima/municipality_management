#include "citoyen.h"
#include "mainwindow.h"
Citoyen::Citoyen()
{

}
Citoyen::Citoyen(QString id,QString nom,QString prenom,QString sexe,QString date,QString lieu ,QString mail ,QString tel)
{
    this->Id_cit=id;
    this->Nom_cit=nom;
    this->Prenom_cit=prenom;
    this->Sexe_cit=sexe;
    this->Date_cit=date;
    this->Lieu_cit=lieu;
    this->Mail_cit=mail;
    this->Tel_cit=tel;
}
bool Citoyen::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CITOYENS (ID_CIT,NOM_CIT,PRENOM_CIT,SEXE_CIT,DATE_CIT,LIEU_CIT,MAIL_CIT,TEL_CIT)"" VALUES(:Id_cit, :Nom_cit, :Prenom_cit, :Sexe_cit,:Date_cit,:Lieu_cit,:Mail_cit,:Tel_cit)");
    query.bindValue(":Id_cit",Id_cit);
    query.bindValue(":Nom_cit",Nom_cit);
    query.bindValue(":Prenom_cit",Prenom_cit);
    query.bindValue(":Sexe_cit",Sexe_cit);
    query.bindValue(":Date_cit",Date_cit);
    query.bindValue(":Lieu_cit",Lieu_cit);
    query.bindValue(":Mail_cit",Mail_cit);
    query.bindValue(":Tel_cit",Tel_cit);
    return query.exec();

}
bool Citoyen::controle()
{
   if(Id_cit=="")  return false;
   else            return true;


}
bool Citoyen::supprimer(QString Id_cit)
{
   QSqlQuery query;
   query.prepare("DELETE FROM CITOYENS WHERE ID_CIT= :id");
   query.bindValue(":id",Id_cit);
   return query.exec();

}

QSqlQueryModel * Citoyen::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

       model->setQuery("select *from CITOYENS");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CIT"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_CIT"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM_CIT"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("SEXE_CIT"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_CIT"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("LIEU_CIT"));
       model->setHeaderData(6,Qt::Horizontal,QObject::tr("MAIL_CIT"));
       model->setHeaderData(7,Qt::Horizontal,QObject::tr("TEL_CIT"));


       return model;
}
 bool Citoyen::maj(QString old_id)
 {
     QSqlQuery qry;

     qry.prepare("UPDATE CITOYENS SET ID_CIT=:id, NOM_CIT=:Nom_cit, PRENOM_CIT=:Prenom_cit,SEXE_CIT=:Sexe_cit, DATE_CIT=:Date_cit,LIEU_CIT=:Lieu_cit,MAIL_CIT=:Mail_cit,TEL_CIT=:tel WHERE ID_CIT =:old_id ");
     qry.bindValue(":id",Id_cit);
     qry.bindValue(":Nom_cit",Nom_cit);
     qry.bindValue(":Prenom_cit",Prenom_cit);
     qry.bindValue(":Sexe_cit",Sexe_cit);
     qry.bindValue(":Date_cit",Date_cit);
     qry.bindValue(":Lieu_cit",Lieu_cit);
     qry.bindValue(":Mail_cit",Mail_cit);
     qry.bindValue(":tel",Tel_cit);
     qry.bindValue(":old_id",old_id);

      if(!qry.exec()){
          QMessageBox::critical(nullptr, QObject::tr("citoyen déjà existant"),
                      QObject::tr("réessayez un autre identifiant"), QMessageBox::Ok);
          return false;
      }
      else{
          qDebug("Values added to DB");
          return true;
      }
  }

 QSqlQueryModel * Citoyen::recherche(QString nom)
 {

     QSqlQueryModel * model= new QSqlQueryModel();
         if(nom=="")
         {

         }
         model->setQuery("SELECT * FROM CITOYENS WHERE (NOM_CIT =  '"+nom+"' OR PRENOM_CIT = '"+nom+"' OR ID_CIT='"+nom+"') ;");
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CIT"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_CIT"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM_CIT"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("SEXE_CIT"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_CIT"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("LIEU_CIT"));
         model->setHeaderData(6,Qt::Horizontal,QObject::tr("MAIL_CIT"));
         model->setHeaderData(7,Qt::Horizontal,QObject::tr("TEL_CIT"));

     return model ;
 }
 QSqlQueryModel * Citoyen::trier()
 {
     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("SELECT * FROM CITOYENS ORDER BY NOM_CIT ;");

     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CIT"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_CIT"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM_CIT"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("SEXE_CIT"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_CIT"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("LIEU_CIT"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("MAIL_CIT"));
     model->setHeaderData(7,Qt::Horizontal,QObject::tr("TEL_CIT"));


     return model;
 }
 void Citoyen::printPDF(int *num)
 {
     QPrinter printer;
     //printer.setOutputFormat(QPrinter::PdfFormat);
     //printer.setOutputFileName("C:/temp/acte.pdf");

     QPdfWriter pdf("c:/Users/user/Documents/file.pdf");
     QPainter painter(&pdf);
    /* QImage image(":/Documents/Acte.jpg"); //creation d un acte de naissance
     if (! painter.begin(&printer)) { // failed to open file
         qWarning("failed to open file, is it writable?");
         QMessageBox msgBox;
         msgBox.setIcon(QMessageBox::Information);
         msgBox.setText("failed to create the pdf.");
         msgBox.exec();
     }*/
     //else{
         num++;
         QFont font = painter.font();
         font.setPointSize(font.pointSize() * 2);
         painter.setFont(font);
         painter.setPen(Qt::cyan);
         //painter.drawImage(-20,-40,image);
         painter.drawText(540, 1520, "Nom: ");
         painter.drawText(540, 1520, "Nom: ");
         painter.drawText(620, 1640, "Prenom: ");
         painter.drawText(545, 1780, "Sexe: ");
         painter.drawText(840, 1890, "Date de naissance: ");
         painter.drawText(840, 2000, "Lieu de naissance: ");

         painter.setPen(Qt::black);
         painter.drawText(1620, 800, this->Id_cit);
         painter.drawText(540, 1520, this->Nom_cit);
         painter.drawText(540, 1520, this->Nom_cit);
         painter.drawText(620, 1640, this->Prenom_cit);
         painter.drawText(545, 1780, this->Sexe_cit);
         painter.drawText(840, 1890, this->Date_cit);
         painter.drawText(840, 2000, this->Lieu_cit);
         painter.end();
         QMessageBox msgBox;
         msgBox.setIcon(QMessageBox::Information);
         msgBox.setText("A pdf has been created.");
         msgBox.exec();
     //}
 }
QSqlQuery Citoyen::select(QString id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM CITOYENS WHERE ID_CIT='"+id+"'");
    return query;
}
