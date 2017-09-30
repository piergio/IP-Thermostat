#include "EditRoom.h"
#include "ui_EditRoom.h"

EditRoom::EditRoom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditRoom)
{
    ui->setupUi(this);
}

EditRoom::~EditRoom()
{
    delete ui;
}
