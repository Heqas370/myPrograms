#ifndef GAUGES_H
#define GAUGES_H

#include <QDialog>

namespace Ui {
class Gauges;
}

class Gauges : public QDialog
{
    Q_OBJECT

public:
    explicit Gauges(QWidget *parent = nullptr);
    ~Gauges();

private:
    Ui::Gauges *ui;
};

#endif // GAUGES_H
