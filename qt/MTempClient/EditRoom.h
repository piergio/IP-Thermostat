#ifndef EDITROOM_H
#define EDITROOM_H

#include <QDialog>

namespace Ui {
class EditRoom;
}

class EditRoom : public QDialog
{
    Q_OBJECT

public:
    explicit EditRoom(QWidget *parent = 0);
    ~EditRoom();

private:
    Ui::EditRoom *ui;
};

#endif // EDITROOM_H
