#ifndef MTEMPCOMMONS_H
#define MTEMPCOMMONS_H

#include "MTempDefs.h"
#include "ASystemConfig.h"

#ifdef __32MX270F256D__

#   include "AString.h"
#   include "ADateTime.h"
#   include "A24LC512.h"
#   include <cstring>

    namespace AFramework{

        typedef AString     QString;
        typedef uint8       quint8;
        typedef uint16      quint16;
        typedef uint32      quint32;

    }

#else

#   include <QString>
#   include <QStringList>

    namespace AFramework{

        class ADateTime{

            public:

                enum Weekdays{
                    NoWeekday,
                    Sunday,
                    Monday,
                    Tuesday,
                    Wednesday,
                    Thursday,
                    Friday,
                    Saturday
                };
        };

    }

#endif



namespace AFramework{

    class Program{
        public:
            Program();

            Program(const ADateTime::Weekdays wDay,
                    const quint8 sHours,
                    const quint8 sMinutes,
                    const quint8 eHours,
                    const quint8 eMinutes,
                    const quint8 targetTemp,
                    const quint8 en,
                    bool  & ok);

            Program(const QString & wDay,
                    const QString & sHours,
                    const QString & sMinutes,
                    const QString & eHours,
                    const QString & eMinutes,
                    const QString & targetTemp,
                    const QString & en,
                    bool  & ok);
            Program(const QString & program, bool & ok);

            bool fromString(const QString & program);

            ADateTime::Weekdays weekday() const;
            quint8 startHours() const;
            quint8 startMinutes() const;
            quint8 endHours() const;
            quint8 endMinutes() const;
            quint8 targetTemperature() const;
            bool   isEnabled() const;

            bool setWeekday(const ADateTime::Weekdays wDay);
            bool setWeekday(const QString & str);

            bool setStartHours(const quint8 sHours);
            bool setStartHours(const QString & str);

            bool setStartMinutes(const quint8 sMinutes);
            bool setStartMinutes(const QString & str);

            bool setEndHours(const quint8 eHours);
            bool setEndHours(const QString & str);

            bool setEndMinutes(const quint8 eMinutes);
            bool setEndMinutes(const QString & str);

            bool setTargetTemperature(const quint8 targetTemp);
            bool setTargetTemperature(const QString & str);

            void setEnabled();
            void setDisabled();

            QString toString() const;

        private:
            ADateTime::Weekdays m_weekday;
            quint8              m_startHours;
            quint8              m_startMinutes;
            quint8              m_endHours;
            quint8              m_endMinutes;
            quint8              m_targetTemp;
            bool                m_enabled;
    };

    class Room{

        public:

            enum RoomNumber{
                Room0,
                Room1,
                Room2,
                Room3,
                Room4,
                Room5,
                Room6,
                Room7
            };

            Room();

#           ifdef __32MX270F256D__

                            Room(const RoomNumber roomNum, bool & ok);
                    bool    loadRoom();
                    bool    saveRoom();
                    bool    loadProgram(const ADateTime::Weekdays day);
                    bool    saveProgram(const ADateTime::Weekdays day);
            static  void    setEEPROM(A24LC512 * mem);
            static  void    setPORT(volatile AHardwarePort * port);
#           endif

            Room(const QString & name, const QString & sensorAddress, const QString relayOut, bool & ok);

            bool    fromString(const QString & str);
            RoomNumber roomNumber() const;
            QString roomName() const;
            QString sensorAddress() const;
            quint32 relayOut() const;
            Program program(const ADateTime::Weekdays day) const;
            quint8  currentTemperature() const;

            bool    setTemperature(const quint8 temp);
            bool    setRoomNumber(const RoomNumber room);
            bool    setRoomName(const QString & name);
            bool    setSensorAddress(const quint8 addr);
            bool    setRelayOut(const quint32 gpio);
            bool    setProgram(const ADateTime::Weekdays day, const QString & str);
            bool    isForcedOn() const;
            bool    isForcedOff() const;
            bool    isAuto()const;
            bool    isOn() const;
            bool    isOff() const;
            bool    forceOn(const bool force);
            bool    forceOff(const bool force);
            bool    setAuto(const bool flg);
            QString toString() const;
            #ifdef __32MX270F256D__
            bool    on();
            bool    off();
            #endif

        private:

#           ifdef __32MX270F256D__
                             quint16 getRadd() const;
                             quint16 getPadd(const ADateTime::Weekdays day) const;
            static           quint16         m_ROOM_BASE_ADDR;
            static           A24LC512 *      m_mem;
            static  volatile AHardwarePort * m_relayPort;
#           endif
            
            char       m_roomName      [_MTEMP_ROOM_NAME_VEC_SIZE  ];
            Program    m_weekProgram   [_MTEMP_WEEKPROGRAM_VEC_SIZE];
            quint8     m_sensorAddrees;
            quint32    m_relayOut;
            bool       m_forcedOn;
            bool       m_forcedOff;
            RoomNumber m_number;
            quint8     m_temp;
    };

}

#endif // MTEMPCOMMONS_H
