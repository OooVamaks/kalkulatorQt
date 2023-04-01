#include "kalkulator.h"
#include "ui_kalkulator.h"


double wartosc = 0.0;
char zmienna;


kalkulator::kalkulator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::kalkulator)
{
    ui->setupUi(this);
    ui->ekran->setText(QString::number(wartosc));

    connect(ui->Przy0, SIGNAL(released()), this,
              SLOT(Cyfra()));

    connect(ui->Przy1, SIGNAL(released()), this,
              SLOT(Cyfra()));
    connect(ui->Przy2,SIGNAL(released()), this,
              SLOT(Cyfra()));
    connect(ui->Przy3, SIGNAL(released()), this,
              SLOT(Cyfra()));
    connect(ui->Przy4, SIGNAL(released()), this,
              SLOT(Cyfra()));
    connect(ui->Przy5, SIGNAL(released()), this,
              SLOT(Cyfra()));
    connect(ui->Przy6, SIGNAL(released()), this,
              SLOT(Cyfra()));
    connect(ui->Przy7, SIGNAL(released()), this,
              SLOT(Cyfra()));
    connect(ui->Przy8, SIGNAL(released()), this,
              SLOT(Cyfra()));
    connect(ui->Przy9, SIGNAL(released()), this,
              SLOT(Cyfra()));

 connect(ui->dodawanie, SIGNAL(released()), this,
           SLOT(Dzialanie()));
 connect(ui->odej, SIGNAL(released()), this,
           SLOT(Dzialanie()));
  connect(ui->mnozenie, SIGNAL(released()), this,
           SLOT(Dzialanie()));
 connect(ui->dzielenie, SIGNAL(released()), this,
           SLOT(Dzialanie()));
 connect(ui->rownosc, SIGNAL(released()), this,
           SLOT(Rownosc()));
 connect(ui->znak, SIGNAL(released()), this,
           SLOT(Zmiana_Znaku()));
 connect(ui->clear, SIGNAL(released()), this,
           SLOT(clear()));
 connect (ui->przecinek, SIGNAL(released()), this, SLOT(przecinek_push()));




}




kalkulator::~kalkulator()
{
    delete ui;
}

void kalkulator :: Cyfra(){
     QPushButton *przycisk = (QPushButton *) sender();
    QString NaPrzycisku = przycisk ->text();
    QString liczbaEkran = ui->ekran-> text();
    if(liczbaEkran. toDouble () ==0){
        ui->ekran->setText(NaPrzycisku);}
    else {
        QString LiczbaWieksza =liczbaEkran + NaPrzycisku;
        ui->ekran->setText(LiczbaWieksza);
    }
    }
void kalkulator::Dzialanie(){
    zmienna= 0;
    QString LiczbaWartosc = ui->ekran->text();
    wartosc = LiczbaWartosc.toDouble();
    QPushButton *przycisk = (QPushButton *)sender();
    QString NaPrzycisku= przycisk->text();
    if(QString::compare(NaPrzycisku, "+") == 0){
        zmienna = 1;
         } else if(QString::compare(NaPrzycisku, "x") == 0){
             zmienna = 2;
         } else if(QString::compare(NaPrzycisku, "-") == 0) {
        zmienna =3;
         } else if(QString::compare(NaPrzycisku, "/" )==0){
    zmienna = 4;
         }
            ui->ekran->setText("");
}
void kalkulator::Rownosc(){
    double wartosc_ = 0.0;
    QString ekranLiczba = ui->ekran->text();
    double ekranLiczbaDBL= ekranLiczba.toDouble();
    switch(zmienna){
    case 1:
        wartosc_ = wartosc + ekranLiczbaDBL;
        ui->ekran->setText(QString::number(wartosc_));
        break;

    case 2:

        wartosc_ = wartosc * ekranLiczbaDBL;
        ui->ekran->setText(QString::number(wartosc_));
        break;

    case 3:
       wartosc_ = wartosc - ekranLiczbaDBL;
       ui->ekran->setText(QString::number(wartosc_));
        break;

     case 4:
        if( ekranLiczbaDBL != 0 ) {
       wartosc_ = wartosc / ekranLiczbaDBL;
       ui->ekran->setText(QString::number(wartosc_));

    }
    else if ( ekranLiczbaDBL == 0 ){
         ui->ekran->setText("Error");
         return;
         break;


    }



}}
void kalkulator::clear(){

ui->ekran->setText("0");


}
void kalkulator::Zmiana_Znaku(){
    QString displayVal = ui->ekran->text();
        wartosc = displayVal.toDouble();
    if ( wartosc > 0){ui->ekran->setText("-"+QString::number(wartosc));}
    else if(wartosc < 0){ ui->ekran->setText(QString::number(fabs(wartosc)));
    }}


void kalkulator::przecinek_push(){
    QString LiczbaWartosc = ui->ekran->text();
    wartosc = LiczbaWartosc.toDouble();
    ui->ekran->setText(QString::number(wartosc)+".");



}
