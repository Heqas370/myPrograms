#ifndef TELEMETRIA_H
#define TELEMETRIA_H
#include"plots.h"
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class Telemetria; }
QT_END_NAMESPACE

class Telemetria : public QMainWindow
{
    Q_OBJECT

public:
    Telemetria(QWidget *parent = nullptr);
    ~Telemetria();

private slots:

    void on_Plots_clicked();

private:
    Ui::Telemetria *ui;
     Plots *plot;
};
#endif // TELEMETRIA_H
