#include "MTempCommons.h"

/**
 * @brief AFramework::Program::Program
 */

AFramework::Program::Program() : m_weekday(ADateTime::Sunday),
                                 m_startHours(0),
                                 m_startMinutes(0),
                                 m_endHours(23),
                                 m_endMinutes(59),
                                 m_targetTemp(25),
                                 m_enabled(false){

}

AFramework::Program::Program(const AFramework::ADateTime::Weekdays wDay,
                             const quint8 sHours,
                             const quint8 sMinutes,
                             const quint8 eHours,
                             const quint8 eMinutes,
                             const quint8 targetTemp,
                             const quint8 en,
                             bool  &ok) : Program(){

    ok = (setWeekday(wDay)               &&
          setEndHours(eHours)            &&
          setEndMinutes(eMinutes)        &&
          setStartHours(sHours)          &&
          setStartMinutes(sMinutes)      &&
          setTargetTemperature(targetTemp));

    if(ok){
        if(en){
            setEnabled();
        }else{
            setDisabled();
        }
    }
}

AFramework::Program::Program(const QString &wDay,
                             const QString &sHours,
                             const QString &sMinutes,
                             const QString &eHours,
                             const QString &eMinutes,
                             const QString &targetTemp,
                             const QString &en,
                             bool  &ok) : Program(){
    
    ok = (setWeekday(wDay)                 &&
          setEndHours(eHours)              &&
          setEndMinutes(eMinutes)          &&
          setStartHours(sHours)            &&
          setStartMinutes(sMinutes)        &&
          setTargetTemperature(targetTemp) &&
          (en.size() == 1 && (en[0] == _MTEMP_ENABLED || en[0] == _MTEMP_DISABLED)));

    if(ok){
        if(en[0] == _MTEMP_ENABLED){
            setEnabled();
        }else{
            setDisabled();
        }
    }
}

AFramework::Program::Program(const QString & program, bool &ok) : Program(){

    ok = fromString(program);
}

bool AFramework::Program::fromString(const QString &program){

    bool    ok = false;
    QString wDay;
    QString sHours;
    QString sMinutes;
    QString eHours;
    QString eMinutes;
    QString en;
    QString targetTemp;
//0123456789ABCDEF01    
//D*HS*MS*HE*ME*TT*E
    if(program.size() != 0x12){

        ok = false;
    }else{
        wDay       += program[0x00];
        sHours     += program[0x02];
        sHours     += program[0x03];
        sMinutes   += program[0x05];
        sMinutes   += program[0x06];
        eHours     += program[0x08];
        eHours     += program[0x09];
        eMinutes   += program[0x0B];
        eMinutes   += program[0x0C];
        targetTemp += program[0x0E];
        targetTemp += program[0x0F];
        en         += program[0x11];
    }

    ok = (setWeekday(wDay)                 &&
          setEndHours(eHours)              &&
          setEndMinutes(eMinutes)          &&
          setStartHours(sHours)            &&
          setStartMinutes(sMinutes)        &&
          setTargetTemperature(targetTemp) &&
          (en.size() == 1 && (en[0] == _MTEMP_ENABLED || en[0] == _MTEMP_DISABLED)));

    if(ok){
        if(en[0] == _MTEMP_ENABLED){
            setEnabled();
        }else{
            setDisabled();
        }
    }

    return ok;
}

AFramework::ADateTime::Weekdays AFramework::Program::weekday() const{

    return m_weekday;
}

#ifdef __32MX270F256D__
AFramework::quint8 AFramework::Program::startHours() const{
#else
quint8 AFramework::Program::startHours() const{
#endif

    return m_startHours;
}

#ifdef __32MX270F256D__
AFramework::quint8 AFramework::Program::startMinutes() const{
#else
quint8 AFramework::Program::startMinutes() const{
#endif

    return m_startMinutes;
}

#ifdef __32MX270F256D__
AFramework::quint8 AFramework::Program::endHours() const{
#else
quint8 AFramework::Program::endHours() const{
#endif

    return m_endHours;
}

#ifdef __32MX270F256D__
AFramework::quint8 AFramework::Program::endMinutes() const{
#else
quint8 AFramework::Program::endMinutes() const{
#endif

    return m_endMinutes;
}

#ifdef __32MX270F256D__
AFramework::quint8 AFramework::Program::targetTemperature() const{
#else
quint8 AFramework::Program::targetTemperature() const{
#endif

    return m_targetTemp;
}

bool AFramework::Program::isEnabled() const{

    return m_enabled;
}

bool AFramework::Program::setWeekday(const AFramework::ADateTime::Weekdays wDay){

    if(wDay == ADateTime::NoWeekday){

        return false;
    }

    m_weekday = wDay;

    return true;
}

bool AFramework::Program::setWeekday(const QString &str){
#   ifdef __32MX270F256D__

    if(str.size() != 1){
        
        return false;
    }
    
    if((static_cast<quint8>(str[0] - 0x30) >  7) ||
        static_cast<quint8>(str[0] - 0x30) == 0) {

        return false;
    }

    m_weekday = static_cast<ADateTime::Weekdays>(str[0] - 0x30);

    return true;

#   else

    if(str.size() != 1){

        return false;
    }

    if((static_cast<quint8>(str[0].toLatin1() - 0x30) >  7) ||
        static_cast<quint8>(str[0].toLatin1() - 0x30) == 0) {

        return false;
    }

    m_weekday = static_cast<ADateTime::Weekdays>(str[0].toLatin1() - 0x30);

    return true;

#   endif
}

bool AFramework::Program::setStartHours(const quint8 sHours){

    if(sHours > 23 || sHours > m_endHours){

        return false;
    }

    if(sHours == m_endHours && m_startMinutes > m_endMinutes){

        return false;
    }

    m_startHours = sHours;

    return true;
}

bool AFramework::Program::setStartHours(const QString &str){
#   ifdef __32MX270F256D__

    if(str.size() != 2){

        return false;
    }

    return setStartHours((static_cast<quint8>(str[0] - 0x30) * 10) +
                          static_cast<quint8>(str[1] - 0x30));

#   else

    if(str.size() != 2){

        return false;
    }

    return setStartHours((static_cast<quint8>(str[0].toLatin1() - 0x30) * 10) +
                          static_cast<quint8>(str[1].toLatin1() - 0x30));

#   endif
}

bool AFramework::Program::setStartMinutes(const quint8 sMinutes){

    if(sMinutes > 59){

        return false;
    }

    if(sMinutes >= m_endMinutes && m_startHours == m_endHours){

        return false;
    }

    m_startMinutes = sMinutes;

    return true;
}

bool AFramework::Program::setStartMinutes(const QString &str){
#   ifdef __32MX270F256D__

    if(str.size() != 2){

        return false;
    }
    
    return setStartMinutes((static_cast<quint8>(str[0] - 0x30) * 10) +
                            static_cast<quint8>(str[1] - 0x30));
    
#   else

    if(str.size() != 2){

        return false;
    }

    return setStartMinutes((static_cast<quint8>(str[0].toLatin1() - 0x30) * 10) +
                            static_cast<quint8>(str[1].toLatin1() - 0x30));

#   endif
}

bool AFramework::Program::setEndHours(const quint8 eHours){

    if(eHours > 23 || eHours < m_startHours){

        return false;
    }

    if(eHours == m_startHours && m_endMinutes < m_startMinutes){

        return false;
    }

    m_endHours = eHours;

    return true;
}

bool AFramework::Program::setEndHours(const QString &str){
#   ifdef __32MX270F256D__

    if(str.size() != 2){

        return false;
    }

    return setEndHours((static_cast<quint8>(str[0] - 0x30) * 10) +
                        static_cast<quint8>(str[1] - 0x30));

#   else

    if(str.size() != 2){

        return false;
    }

    return setEndHours((static_cast<quint8>(str[0].toLatin1() - 0x30) * 10) +
                        static_cast<quint8>(str[1].toLatin1() - 0x30));

#   endif
}

bool AFramework::Program::setEndMinutes(const quint8 eMinutes){

    if(eMinutes > 59){

        return false;
    }

    if(eMinutes <= m_startMinutes && m_startHours == m_endHours){

        return false;
    }

    m_endMinutes = eMinutes;

    return true;
}

bool AFramework::Program::setEndMinutes(const QString &str){
#   ifdef __32MX270F256D__

    if(str.size() != 2){

        return false;
    }

    return setEndMinutes((static_cast<quint8>(str[0] - 0x30) * 10) +
                          static_cast<quint8>(str[1] - 0x30));

#   else

    if(str.size() != 2){

        return false;
    }

    return setEndMinutes((static_cast<quint8>(str[0].toLatin1() - 0x30) * 10) +
                          static_cast<quint8>(str[1].toLatin1() - 0x30));

#   endif
}

bool AFramework::Program::setTargetTemperature(const quint8 targetTemp){

    if(targetTemp > 40 || targetTemp < 18){

        return false;
    }

    m_targetTemp = targetTemp;

    return true;
}

bool AFramework::Program::setTargetTemperature(const QString &str){
#   ifdef __32MX270F256D__

    if(str.size() != 2){

        return false;
    }

    return setTargetTemperature((static_cast<quint8>(str[0] - 0x30) * 10) +
                                 static_cast<quint8>(str[1] - 0x30));

#   else

    if(str.size() != 2){

        return false;
    }

    return setTargetTemperature((static_cast<quint8>(str[0].toLatin1() - 0x30) * 10) +
                                 static_cast<quint8>(str[1].toLatin1() - 0x30));

#   endif
}

void AFramework::Program::setEnabled(){

    m_enabled = true;
}

void AFramework::Program::setDisabled(){

    m_enabled = false;
}

#ifdef __32MX270F256D__
AFramework::QString AFramework::Program::toString() const{
#else
QString AFramework::Program::toString() const{    
#endif
    QString str;

    str += static_cast<char>(m_weekday                  + 0x30);
    str += _MTEMP_SEP;
    str += static_cast<char>((m_startHours      / 0x0A) + 0x30);
    str += static_cast<char>((m_startHours      % 0x0A) + 0x30);
    str += _MTEMP_SEP;
    str += static_cast<char>((m_startMinutes    / 0x0A) + 0x30);
    str += static_cast<char>((m_startMinutes    % 0x0A) + 0x30);
    str += _MTEMP_SEP;
    str += static_cast<char>((m_endHours        / 0x0A) + 0x30);
    str += static_cast<char>((m_endHours        % 0x0A) + 0x30);
    str += _MTEMP_SEP;
    str += static_cast<char>((m_endMinutes      / 0x0A) + 0x30);
    str += static_cast<char>((m_endMinutes      % 0x0A) + 0x30);
    str += _MTEMP_SEP;
    str += static_cast<char>((m_targetTemp      / 0x0A) + 0x30);
    str += static_cast<char>((m_targetTemp      % 0x0A) + 0x30);
    str += _MTEMP_SEP;
    str += (m_enabled ? _MTEMP_ENABLED : _MTEMP_DISABLED      );
    
    return str;
}

/**
 * @brief AFramework::Room::Room
 */


#ifdef __32MX270F256D__
             AFramework::quint16         AFramework::Room::m_ROOM_BASE_ADDR(_MTEMP_ROOM_0_ADDRESS);
             AFramework::A24LC512 *      AFramework::Room::m_mem(NULL);
    volatile AFramework::AHardwarePort * AFramework::Room::m_relayPort(NULL);
#endif

AFramework::Room::Room() : m_sensorAddrees(0),
                           m_relayOut(0),
                           m_forcedOn(false),
                           m_forcedOff(false),
                           m_number(Room0), 
                           m_temp(0){
    memset(m_roomName   , 0x00,_MTEMP_ROOM_NAME_VEC_SIZE  );
    memset(m_weekProgram, 0x00, (sizeof(Program) * _MTEMP_WEEKPROGRAM_VEC_SIZE));

}

#ifdef __32MX270F256D__

AFramework::Room::Room(const AFramework::Room::RoomNumber roomNum, bool &ok){
    if(!m_mem){
        ok = false;
    }
    m_number = roomNum;
}

bool AFramework::Room::loadRoom(){
    QString str;
    bool    flg = false;

    if(!m_mem){
        return false;
    }

    flg = m_mem->read(getRadd(), str);

    if(flg && str.good()){
        fromString(str);
        return true;
    }else{
        return false;
    }
}

bool AFramework::Room::saveRoom(){

    if(!m_mem){
        return false;
    }
    
    return m_mem->write(getRadd(), toString());
}

bool AFramework::Room::loadProgram(const AFramework::ADateTime::Weekdays day){
    QString str;
    bool    flg = false;
    if(!m_mem || day == ADateTime::NoWeekday){
        return false;
    }

    flg = m_mem->read(getPadd(day), str);
    
    if(flg && str.good()){
        return m_weekProgram[static_cast<quint8>(day) - 1].fromString(str);
    }else{
        return false;
    }
}

bool AFramework::Room::saveProgram(const AFramework::ADateTime::Weekdays day){

    if(!m_mem || day == ADateTime::NoWeekday){
        return false;
    }
    
    return m_mem->write(getPadd(day), m_weekProgram[static_cast<quint8>(day) - 1].toString());
}

void AFramework::Room::setEEPROM(A24LC512 *mem){

    m_mem = mem;
}

void AFramework::Room::setPORT(volatile AHardwarePort *port){

    m_relayPort = port;
}

AFramework::quint16 AFramework::Room::getRadd() const{

    return (m_ROOM_BASE_ADDR +
            static_cast<quint16>(m_number) * (_MTEMP_ROOM_LENGTH +
                                             (_MTEMP_WEEKPROGRAM_VEC_SIZE * _MTEMP_PROG_LENGTH)));
}

AFramework::quint16 AFramework::Room::getPadd(const ADateTime::Weekdays day) const{

    return (getRadd() + _MTEMP_ROOM_LENGTH + (static_cast<quint16>(day) - 1) * _MTEMP_PROG_LENGTH);
}

#endif

bool AFramework::Room::fromString(const QString &str){
#ifdef __32MX270F256D__
    //DANILO
    AStringList * list = NULL;
    QString       temp;
    bool          flg0 = false;
    bool          flg1 = false;
    bool          flg2 = false;
    
    list = str.split('*');

    if(list && str.good()){
        temp = list->at(0);
        flg0 = setRoomName(temp);
        temp = list->at(1);
        m_sensorAddrees = static_cast<quint8>(temp.toInt32(flg1));
        temp = list->at(2);
        m_relayOut = static_cast<quint32>(temp.toInt32(flg2));
        delete list;
        return (flg0 && flg1 && flg2);
    }
    return false;
#else
    QStringList list;
    QString     temp;
    bool          flg0 = false;
    bool          flg1 = false;
    bool          flg2 = false;
    list = str.split("*");
    flg0 = setRoomName(list[0]);
    m_sensorAddrees = static_cast<quint8>(list[1].toInt(&flg1));
    m_relayOut = static_cast<quint32>(list[2].toInt(&flg2));
    return (flg0 && flg1 && flg2);
#endif
}

AFramework::Room::RoomNumber AFramework::Room::roomNumber() const{
    
    return m_number;
}

#ifdef __32MX270F256D__
AFramework::QString AFramework::Room::roomName() const{
#else
QString AFramework::Room::roomName() const{
#endif

    return m_roomName;
}

#ifdef __32MX270F256D__
AFramework::QString AFramework::Room::sensorAddress() const{
#else
QString AFramework::Room::sensorAddress() const{
#endif

    return QString(m_sensorAddrees);
}


#ifdef __32MX270F256D__
AFramework::quint32 AFramework::Room::relayOut() const{
#else
quint32 AFramework::Room::relayOut() const{
#endif

    return m_relayOut;
}

AFramework::Program AFramework::Room::program(const AFramework::ADateTime::Weekdays day) const{
    
    if(day == ADateTime::NoWeekday){
        return Program();
    }

    return m_weekProgram[static_cast<quint8>(day) - 1];
}

#ifdef __32MX270F256D__
AFramework::quint8 AFramework::Room::currentTemperature() const{
#else
quint8 AFramework::Room::currentTemperature() const{
#endif
#ifdef __32MX270F256D__
    //DANILO
#else
    //GIUSEPPE
#endif
    
    return m_temp;
}

bool AFramework::Room::setTemperature(const quint8 temp){
    
    m_temp = temp;
}

bool AFramework::Room::setRoomNumber(const RoomNumber room){
    
    m_number = room;
    return true;
}

bool AFramework::Room::setRoomName(const QString &name){
    if(name.size() > _MTEMP_ROOM_NAME_VEC_SIZE - 1){
        return false;
    }
    for(quint16 i = 0; i < name.size(); i++){
#       ifdef __32MX270F256D__
        //DANILO
        m_roomName[i] = name[i];
#       else
        //GIUSEPPE
        m_roomName[i] = name[i].toLatin1();
#       endif
    }
    m_roomName[name.size()] = 0x00;
    return true;
}

bool AFramework::Room::setSensorAddress(const quint8 addr){

    if(addr > 7){
        return false;
    }
    m_sensorAddrees = addr;
    return true;
}

bool AFramework::Room::setRelayOut(const quint32 gpio){

    if(!(gpio & (gpio - 1)) && gpio > 0x8000){
        return false;
    }
    m_relayOut = gpio;
    return true;
}

bool AFramework::Room::setProgram(const AFramework::ADateTime::Weekdays day, const QString &str){

    if(day == ADateTime::NoWeekday){
        return false;
    }
    return m_weekProgram[static_cast<quint8>(day) - 1].fromString(str);

}

bool AFramework::Room::isForcedOn() const{

    return m_forcedOn;
}

bool AFramework::Room::isForcedOff() const{

    return m_forcedOff;
}

bool AFramework::Room::isAuto()const{
    
    return ((!m_forcedOff) && (!m_forcedOn));
}

bool AFramework::Room::isOn() const{
#ifdef __32MX270F256D__
    //DANILO
    return (m_relayPort->latchRead(m_relayOut) == Hi);
#else
    //GIUSEPPE
#endif
}

bool AFramework::Room::isOff() const{
#ifdef __32MX270F256D__
    //DANILO
    return (m_relayPort->latchRead(m_relayOut) == Lo);
#else
    //GIUSEPPE
#endif
}

bool AFramework::Room::forceOn(const bool force){

    if(force){
        
        m_forcedOn = force;
        m_forcedOff = !force;
    }
    return true;
}

bool AFramework::Room::forceOff(const bool force){

    if(force){
        
        m_forcedOff = force;
        m_forcedOn = !force;
    }
    return true;
}

bool AFramework::Room::setAuto(const bool flg){
    
    if(flg){
        m_forcedOn = false;
        m_forcedOff = false;   
    }
    return true;
}

#ifdef __32MX270F256D__
AFramework::QString AFramework::Room::toString() const{
#else
QString AFramework::Room::toString() const{
#endif
    QString str;

    str += m_roomName;
    str += _MTEMP_SEP;
    str += static_cast<char>(m_sensorAddrees + 0x30);
    str += _MTEMP_SEP;
#   ifdef __32MX270F256D__
    str += QString(static_cast<sint32>(m_relayOut));
#   else
    str += QString(m_relayOut);
#   endif    

    return str;
}
#ifdef __32MX270F256D__
bool AFramework::Room::on(){
    
    if(isOn()){
        return true;
    }
    return m_relayPort->write(relayOut(), Hi);
}

bool AFramework::Room::off(){
    
    if(isOff()){
        return true;
    }
    return m_relayPort->write(relayOut(), Lo);
}
#endif
