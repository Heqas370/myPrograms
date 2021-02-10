#include "plots.h"
#include "ui_plots.h"

Plots::Plots(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Plots)
{
    ui->setupUi(this);
}

Plots::~Plots()
{
    delete ui;
}
