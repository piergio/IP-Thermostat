#ifndef LOADER_H
#define LOADER_H

#include <QDialog>
#include <QString>
#include <QMovie>

namespace Ui {
    class Loader;
}

class Loader : public QDialog{
    Q_OBJECT

    public:
        explicit Loader(const QString & title, QWidget *parent = 0);
        ~Loader();

    public slots:
        void setMessage(const QString & msg);

    private:
        Ui::Loader *ui;
        QMovie *    m_movie;
};

#endif // LOADER_H
