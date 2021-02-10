#include "telemetria.h"
#include "ui_telemetria.h"
Telemetria::Telemetria(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Telemetria)
{
    ui->setupUi(this);
}

Telemetria::~Telemetria()
{
    delete ui;
}



void Telemetria::on_Plots_clicked()
{
    plot=new Plots(this);
    plot->setWindowTitle("Plots");
    plot->show();

}
