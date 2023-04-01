#ifndef KALKULATOR_H
#define KALKULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class kalkulator; }
QT_END_NAMESPACE

class kalkulator : public QMainWindow
{
    Q_OBJECT

public:
    kalkulator(QWidget *parent = nullptr);
    ~kalkulator();

private:
    Ui::kalkulator *ui;
private slots:
    void Cyfra();
    void Dzialanie();
    void Rownosc();
    void clear();
    void Zmiana_Znaku();
    void przecinek_push();




};
#endif // KALKULATOR_H
