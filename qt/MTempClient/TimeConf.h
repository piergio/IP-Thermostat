#ifndef TIMECONF_H
#define TIMECONF_H

#include <QDialog>

namespace Ui {
class TimeConf;
}

class TimeConf : public QDialog
{
    Q_OBJECT

public:
    explicit TimeConf(QWidget *parent = 0);
    ~TimeConf();

private:
    Ui::TimeConf *ui;
};

#endif // TIMECONF_H
