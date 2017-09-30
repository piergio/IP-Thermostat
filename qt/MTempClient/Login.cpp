#include "Login.h"
#include "ui_Login.h"
#include <QDebug>

Login::Login(QWidget *parent) : QDialog(parent), ui(new Ui::Login), m_flag(false){

    QSettings setting;
    QRegExp portRx("^(?:6553[0-5]|655[0-2][0-9]|65[0-4][0-9]{2}|6[0-4][0-9]{3}|[1-5][0-9]{4}|[1-9][0-9]{1,3}|[1-9])$");
    QRegExpValidator * portValidator = new QRegExpValidator(portRx, this);

    ui->setupUi(this);

    ui->portLineEdit->setValidator(portValidator);

    this->setWindowTitle("Login");
    this->setWindowIcon(QIcon(":/ico/img/Key-48.png"));

    if(setting.value(_MTEMP_ADDR).toString() != _MTEMP_NOADDR){

        ui->remeberNetCheck->setChecked(true);

        m_user = setting.value(_MTEMP_ADDR).toString();

        ui->domaniLineEdit->setText(m_user);
    }

    if(setting.value(_MTEMP_PORT).toUInt() != _MTEMP_NOPORT){

        ui->remeberNetCheck->setChecked(true);

        m_port = setting.value(_MTEMP_PORT).toUInt();

        ui->portLineEdit->setText(QString::number(m_port));
    }

    if(setting.value(_MTEMP_USER).toString() != _MTEMP_NOUSER){

        ui->rememberUserCheck->setChecked(true);

        m_user = setting.value(_MTEMP_USER).toString();

        ui->usernameLineEdit->setText(m_user);
    }

    if(setting.value(_MTEMP_PASS).toString() != _MTEMP_NOPASS){

        ui->rememberUserCheck->setChecked(true);

        m_pass = setting.value(_MTEMP_PASS).toString();

        ui->passwordLineEdit->setText(m_pass);
    }
}

Login::~Login(){

    delete ui;
}

bool Login::good(){

    return m_flag;
}

QString Login::address() const{

    return m_addr;
}

quint16 Login::port() const{

    return m_port;
}

QString Login::username() const{

    return m_user;
}

QString Login::password() const{

    return m_pass;
}

void Login::on_domaniLineEdit_textChanged(const QString &arg1){

    QRegExp rx;
    QSettings setting;
    QString rxPattern = "[\[]| |[\]]";

    rx.setPattern(rxPattern);
    rx.setCaseSensitivity(Qt::CaseInsensitive);

    if(arg1.contains(rx)){

        QMessageBox::critical(this, this->windowTitle(), "L'indirizzo non può contenere [, ], o spazi vuoti.");

        ui->domaniLineEdit->clear();
        return;
    }

    if(ui->remeberNetCheck->isChecked()){

        setting.setValue(_MTEMP_ADDR, arg1);
    }else{

        setting.setValue(_MTEMP_ADDR, _MTEMP_NOADDR);
        setting.setValue(_MTEMP_PORT, _MTEMP_NOPORT);
    }
    m_addr = arg1;
}

void Login::on_portLineEdit_textChanged(const QString &arg1){

    QSettings setting;
    m_port = arg1.toUInt();

    if(ui->remeberNetCheck->isChecked()){

        setting.setValue(_MTEMP_PORT, arg1.toUInt());
    }else{

        setting.setValue(_MTEMP_ADDR, _MTEMP_NOADDR);
        setting.setValue(_MTEMP_PORT, _MTEMP_NOPORT);
    }

}

void Login::on_usernameLineEdit_textChanged(const QString &arg1){

    QRegExp rx;
    QSettings setting;
    QString rxPattern = "[\[]| |[\]]";

    rx.setPattern(rxPattern);
    rx.setCaseSensitivity(Qt::CaseInsensitive);

    if(arg1.contains(rx)){

        QMessageBox::critical(this, this->windowTitle(), "Il nome utente non può contenere [, ], o spazi vuoti.");

        ui->usernameLineEdit->clear();
        return;
    }
    if(ui->rememberUserCheck->isChecked()){

        setting.setValue(_MTEMP_USER, arg1);
    }else{

        setting.setValue(_MTEMP_USER, _MTEMP_NOUSER);
        setting.setValue(_MTEMP_PASS, _MTEMP_NOPASS);
    }
    m_user = arg1;
}

void Login::on_passwordLineEdit_textChanged(const QString &arg1){

    QRegExp rx;
    QSettings setting;
    QString rxPattern = "[\[]| |[\]]";

    rx.setPattern(rxPattern);
    rx.setCaseSensitivity(Qt::CaseInsensitive);

    if(arg1.contains(rx)){

        QMessageBox::critical(this, this->windowTitle(), "La password non può contenere [, ], o spazi vuoti.");

        ui->passwordLineEdit->clear();
        return;
    }
    if(ui->rememberUserCheck->isChecked()){

        setting.setValue(_MTEMP_PASS, arg1);
    }else{

        setting.setValue(_MTEMP_USER, _MTEMP_NOUSER);
        setting.setValue(_MTEMP_PASS, _MTEMP_NOPASS);
    }
    m_pass = arg1;
}

void Login::on_abortButton_clicked(){

    m_flag = false;
    this->close();
}

void Login::on_loginButton_clicked(){

    QSettings setting;

    if(m_addr.isEmpty() || (m_addr == _MTEMP_NOADDR)){
        QMessageBox::critical(this, this->windowTitle(), "L'indirizzo non è valido.");
        ui->domaniLineEdit->clear();
        m_flag = false;
        return;
    }
    if(m_port == _MTEMP_NOPORT){
        QMessageBox::critical(this, this->windowTitle(), "La porta non è valida.");
        ui->portLineEdit->clear();
        m_flag = false;
        return;
    }
    if(m_pass.isEmpty() || (m_pass == _MTEMP_NOPASS)){
        QMessageBox::critical(this, this->windowTitle(), "La password non è valida.");
        ui->passwordLineEdit->clear();
        m_flag = false;
        return;
    }
    if(m_user.isEmpty() || (m_user == _MTEMP_NOUSER)){
        QMessageBox::critical(this, this->windowTitle(), "Il nome utente non è valido.");
        ui->usernameLineEdit->clear();
        m_flag = false;
        return;
    }
    if(ui->remeberNetCheck->isChecked()){

        setting.setValue(_MTEMP_ADDR, m_addr);
        setting.setValue(_MTEMP_PORT, m_port);
    }else{

        setting.setValue(_MTEMP_ADDR, _MTEMP_NOADDR);
        setting.setValue(_MTEMP_PORT, _MTEMP_NOPORT);
    }
    if(ui->rememberUserCheck->isChecked()){

        setting.setValue(_MTEMP_USER, m_user);
        setting.setValue(_MTEMP_PASS, m_pass);
    }else{

        setting.setValue(_MTEMP_USER, _MTEMP_NOUSER);
        setting.setValue(_MTEMP_PASS, _MTEMP_NOPASS);
    }

    m_flag = true;
    this->close();
}
