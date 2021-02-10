#include "gauges.h"
#include "ui_gauges.h"

Gauges::Gauges(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gauges)
{
    ui->setupUi(this);
}

Gauges::~Gauges()
{
    delete ui;
}
