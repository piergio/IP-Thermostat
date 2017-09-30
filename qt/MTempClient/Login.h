#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QString>
#include <QRegExp>
#include <QSettings>
#include <QMessageBox>

#include "clientdefs.h"

namespace Ui {
    class Login;
}

class Login : public QDialog{

    Q_OBJECT

    public:
        explicit Login(QWidget *parent = 0);
        ~Login();

        bool good();

        QString address() const;
        quint16 port() const;
        QString username() const;
        QString password() const;

    private slots:
        void on_domaniLineEdit_textChanged(const QString &arg1);

        void on_portLineEdit_textChanged(const QString &arg1);

        void on_usernameLineEdit_textChanged(const QString &arg1);

        void on_passwordLineEdit_textChanged(const QString &arg1);

        void on_abortButton_clicked();

        void on_loginButton_clicked();

    private:
        Ui::Login * ui;
        QString     m_addr;
        quint16     m_port;
        QString     m_user;
        QString     m_pass;
        bool        m_flag;
};

#endif // LOGIN_H
