#ifndef MTEMPCLIENT_H
#define MTEMPCLIENT_H

#include <QIcon>
#include <QSettings>
#include <QMainWindow>
#include <QDate>
#include <QTime>
#include <QDateTime>

#include "MClient.h"
#include "clientdefs.h"
#include "NetworkConfig.h"
#include "Login.h"
#include "TimeConf.h"
#include "GuiRoom.h"

namespace Ui {

    class MTempClient;
}

class MTempClient : public QMainWindow{
    Q_OBJECT

public:
    explicit MTempClient(QWidget *parent = 0);
    ~MTempClient();

private slots:
    void on_actionConfigura_triggered();

    void on_actionLogin_triggered();

    void on_actionLogout_triggered();

    void notifyConnected();

    void notifyError(QAbstractSocket::SocketError);

    void notifyDisconnected();

    void rxHandler(MClient::BoardAnswer answer);

    void notifyFailure();

    void notifyError();

    void disableActions();

    void enableActions();

    void disableWindow();

    void enableWindow();

    void on_timeRefreshButton_clicked();

    void on_timeSetButton_clicked();

    void updateRequestHandler(Room::RoomNumber num);

    void forceOnRequestHandler(Room::RoomNumber num);

    void forceOffRequestHandler(Room::RoomNumber num);

    void forceAutoRequestHandler(Room::RoomNumber num);

private:

    enum Commands{
        NOCOMM,
        TIMEGET,
        TIMESET,
        ROOMSTAT,
        ROOMSET
    };

    void setCurrentRoom(Room::RoomNumber room);
    void timeget();
    void timeset();
    void roomstat();
    void roomset(QString name, quint8 addr, quint32 relayOut, GuiRoom::RoomMode mode);
    QDateTime parseTimeget(const QString & str);

    Ui::MTempClient * ui;

    bool              m_auth;
    QString           m_addr;
    quint16           m_port;
    QString           m_user;
    QString           m_pass;
    MClient *         m_client;
    Commands          m_currentComm;
    GuiRoom           m_rooms[0x08];
    GuiRoom *         m_currentRoom;
};

#endif // MTEMPCLIENT_H
