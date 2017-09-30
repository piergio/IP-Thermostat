#ifndef GUIROOM_H
#define GUIROOM_H

#include <QObject>
#include <QString>
#include <QPushButton>
#include <QGroupBox>
#include <QLineEdit>

#include "MTempCommons.h"

using namespace AFramework;

class GuiRoom : public QObject{

    Q_OBJECT

    public:

        enum RoomState{
            On,
            Off
        };

        enum RoomMode{
            Auto,
            ForcedOn,
            ForcedOff
        };

        GuiRoom(QObject * parent = 0);

        void init(const Room::RoomNumber room,
                  QGroupBox   * container,
                  QLineEdit   * temperature,
                  QLineEdit   * status,
                  QPushButton * forceOnBtn,
                  QPushButton * forceOffBtn,
                  QPushButton * setAutoBtn,
                  QPushButton * updateBtn,
                  QPushButton * configBtn);

    public slots:
        void setRoomName(const QString & name);
        QString roomName() const;

        void setTemperature(const quint32 temp);
        quint32 temperature() const;

        void setStatus(const RoomState stat);
        RoomState status() const;

        void setRoomMode(const RoomMode mode);
        RoomMode roomMode() const;

        void setRelayOut(const quint32 out);
        quint32 relayOut();

        void setSensorAddress(quint8 addr);
        quint8 sensorAddress();

        quint8 roomNumber() const;

        void update(const QString & str);

        void enable(const bool all = true);

        void disable(const bool all = true);

    signals:

        void updateRequest(Room::RoomNumber num);
        void forceOnRequest(Room::RoomNumber num);
        void forceOffRequest(Room::RoomNumber num);
        void forceAutoRequest(Room::RoomNumber num);
        void configRequest(Room::RoomNumber num);

    private slots:

        void raiseUpdate();
        void raiseForceOn();
        void raiseForceOff();
        void raiseAuto();
        void raiseConfig();

    private:
        Room::RoomNumber    m_room;
        quint8              m_addr;
        quint32             m_relayOut;
        QGroupBox   *       m_container;
        QLineEdit   *       m_temperature;
        QLineEdit   *       m_status;
        QPushButton *       m_forceOnBtn;
        QPushButton *       m_forceOffBtn;
        QPushButton *       m_setAutoBtn;
        QPushButton *       m_updateBtn;
        QPushButton *       m_configBtn;
};

#endif // GUIROOM_H
