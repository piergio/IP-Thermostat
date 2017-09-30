#include "MTempClient.h"
#include "ui_MTempClient.h"

#define SEP     (QString(_MTEMP_SEP))
#define USRPSW  (m_user + SEP + m_pass + SEP)


MTempClient::MTempClient(QWidget *parent) : QMainWindow(parent), ui(new Ui::MTempClient), m_auth(false), m_currentComm(NOCOMM){

    QSettings setting;
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/ico/img/Dew Point-64.png"));

    if(!setting.contains(_MTEMP_PORT)){
        setting.setValue(_MTEMP_PORT, _MTEMP_NOPORT);
    }
    if(!setting.contains(_MTEMP_ADDR)){
        setting.setValue(_MTEMP_ADDR, _MTEMP_NOADDR);
    }
    if(!setting.contains(_MTEMP_USER)){
        setting.setValue(_MTEMP_USER, _MTEMP_NOUSER);
    }
    if(!setting.contains(_MTEMP_PASS)){
        setting.setValue(_MTEMP_PASS, _MTEMP_NOPASS);
    }

    m_client = new MClient(this);

    connect(m_client, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(notifyError(QAbstractSocket::SocketError)));
    connect(m_client, SIGNAL(connected()),
            this, SLOT(notifyConnected()));
    connect(m_client, SIGNAL(answerReceived(MClient::BoardAnswer)),
            this, SLOT(rxHandler(MClient::BoardAnswer)));
    connect(m_client, SIGNAL(disconnected()),
            this, SLOT(notifyDisconnected()));
    /*  configuro le stanze                                                                         */
    m_rooms[0].init(Room::Room0, ui->roomGroupBox_1, ui->temperatureEdit_1, ui->statusLineEdit_1, ui->forceOnButton_1, ui->forceOffButton_1, ui->setAutoButton_1, ui->updateButton_1, ui->configButton_1);
    m_rooms[1].init(Room::Room1, ui->roomGroupBox_2, ui->temperatureEdit_2, ui->statusLineEdit_2, ui->forceOnButton_2, ui->forceOffButton_2, ui->setAutoButton_2, ui->updateButton_2, ui->configButton_2);
    m_rooms[2].init(Room::Room2, ui->roomGroupBox_3, ui->temperatureEdit_3, ui->statusLineEdit_3, ui->forceOnButton_3, ui->forceOffButton_3, ui->setAutoButton_3, ui->updateButton_3, ui->configButton_3);
    m_rooms[3].init(Room::Room3, ui->roomGroupBox_4, ui->temperatureEdit_4, ui->statusLineEdit_4, ui->forceOnButton_4, ui->forceOffButton_4, ui->setAutoButton_4, ui->updateButton_4, ui->configButton_4);
    m_rooms[4].init(Room::Room4, ui->roomGroupBox_5, ui->temperatureEdit_5, ui->statusLineEdit_5, ui->forceOnButton_5, ui->forceOffButton_5, ui->setAutoButton_5, ui->updateButton_5, ui->configButton_5);
    m_rooms[5].init(Room::Room5, ui->roomGroupBox_6, ui->temperatureEdit_6, ui->statusLineEdit_6, ui->forceOnButton_6, ui->forceOffButton_6, ui->setAutoButton_6, ui->updateButton_6, ui->configButton_6);
    m_rooms[6].init(Room::Room6, ui->roomGroupBox_7, ui->temperatureEdit_7, ui->statusLineEdit_7, ui->forceOnButton_7, ui->forceOffButton_7, ui->setAutoButton_7, ui->updateButton_7, ui->configButton_7);
    m_rooms[7].init(Room::Room7, ui->roomGroupBox_8, ui->temperatureEdit_8, ui->statusLineEdit_8, ui->forceOnButton_8, ui->forceOffButton_8, ui->setAutoButton_8, ui->updateButton_8, ui->configButton_8);
    /*  inizializzo le stanze                                                                       */
    for(int i = 0; i < 8; i++){
        m_rooms[i].setTemperature(0);
        m_rooms[i].setStatus(GuiRoom::Off);
        m_rooms[i].setRoomName("Stanza ?");
        m_rooms[i].setRoomMode(GuiRoom::Auto);
        //m_rooms[i].disable();
        connect(&m_rooms[i], SIGNAL(updateRequest(Room::RoomNumber))   , this, SLOT(updateRequestHandler(Room::RoomNumber))   );
        connect(&m_rooms[i], SIGNAL(forceAutoRequest(Room::RoomNumber)), this, SLOT(forceAutoRequestHandler(Room::RoomNumber)));
        connect(&m_rooms[i], SIGNAL(forceOffRequest(Room::RoomNumber)) , this, SLOT(forceOffRequestHandler(Room::RoomNumber)) );
        connect(&m_rooms[i], SIGNAL(forceOnRequest(Room::RoomNumber))  , this, SLOT(forceOnRequestHandler(Room::RoomNumber))  );
    }
    enableActions();
    disableWindow();
}

MTempClient::~MTempClient(){

    delete ui;
}

void MTempClient::on_actionConfigura_triggered(){

    NetworkConfig config;

    config.exec();
}

void MTempClient::on_actionLogin_triggered(){

    Login login;

    login.exec();

    if(login.good()){
        disableActions();
        m_addr = login.address();
        m_port = login.port();
        m_user = login.username();
        m_pass = login.password();

        m_client->setAddress(m_addr);
        m_client->setPort(m_port);
        m_client->connectToHost();
    }
}

void MTempClient::on_actionLogout_triggered(){

    m_client->disconnectFromHost();
}

void MTempClient::notifyConnected(){

    m_auth = true;
    enableWindow();
}

void MTempClient::notifyError(QAbstractSocket::SocketError){

    QMessageBox::critical(this, "Errore", m_client->lastError());
    m_auth = false;
    disableWindow();
    enableActions();
}

void MTempClient::notifyDisconnected(){

    m_auth = false;
    disableWindow();
    enableActions();
}

void MTempClient::rxHandler(MClient::BoardAnswer answer){

    QString     str;

    if(answer == MClient::BoardAnswer::Fail){
        m_client->bufferClear();
        notifyFailure();
        m_currentComm = NOCOMM;
        return;
    }
    if(answer == MClient::BoardAnswer::Error){
        m_client->bufferClear();
        notifyError();
        m_currentComm = NOCOMM;
        return;
    }

    str = m_client->dataReceived();

    str.remove(SEP + QString(_MTEMP_BOARD_OK));

    switch (m_currentComm) {
        case TIMEGET:
            ui->dateTimeEdit->setDateTime(parseTimeget(str));
            enableWindow();
            break;
        case TIMESET:
            QMessageBox::information(this, this->windowTitle(), "Ora impostata correttamente.");
            enableWindow();
            break;
        case ROOMSTAT:
            m_currentRoom->update(str);
            enableWindow();
            break;
        case ROOMSET:
            m_client->bufferClear();
            QThread::msleep(250);
            updateRequestHandler(static_cast<Room::RoomNumber>(m_currentRoom->roomNumber()));
            return;
            break;
        default:
            break;
    }
    m_client->bufferClear();
    m_currentComm = NOCOMM;


}

void MTempClient::notifyFailure(){

    QMessageBox::critical(this, this->windowTitle(), "Errore centralina.");
    m_client->disconnectFromHost();
}

void MTempClient::notifyError(){

    QMessageBox::critical(this, this->windowTitle(), "Errore nel login: username o password errati");
    m_client->disconnectFromHost();
}

void MTempClient::disableActions(){

    ui->actionLogin->setEnabled(false);
    ui->actionConfigura->setEnabled(false);
    ui->actionLogout->setEnabled(true);
}

void MTempClient::enableActions(){

    ui->actionLogin->setEnabled(true);
    ui->actionConfigura->setEnabled(true);
    ui->actionLogout->setEnabled(false);
}

void MTempClient::disableWindow(){

    ui->dateTimeEdit->setEnabled(false);
    ui->timeSetButton->setEnabled(false);
    ui->timeRefreshButton->setEnabled(false);

    for(int i = 0; i < 8; i++){
        m_rooms[i].disable();
    }

}

void MTempClient::enableWindow(){

    ui->dateTimeEdit->setEnabled(true);
    ui->timeSetButton->setEnabled(true);
    ui->timeRefreshButton->setEnabled(true);

    for(int i = 0; i < 8; i++){
        m_rooms[i].enable();
    }
}

void MTempClient::setCurrentRoom(Room::RoomNumber room){

    m_currentRoom = &(m_rooms[static_cast<quint8>(room)]);
}

void MTempClient::timeget(){

    /*
     *  FORMATO STRINGA TIMEGET
     *  (CLIENT)        username*password*[TIMEGET]
     *  (SERVER)        (AA*MM*GG*WD*HH*MM*SS*[OK] || [FAIL] || [ERROR])
     */
    disableWindow();
    m_currentComm = TIMEGET;
    m_client->waitFor(_MTEMP_BOARD_OK);
    m_client->write(USRPSW + QString(_MTEMP_TIMEGET));
}

void MTempClient::timeset(){

    /*
     *  FORMATO STRINGA TIMESET
     *  (CLIENT)        username*password*AA*MM*GG*WD*HH*MM*SS*[TIMESET]
     */
    QString str;
    QDateTime curr = ui->dateTimeEdit->dateTime();
    int y = curr.date().year() - 2000;
    int m = curr.date().month();
    int d = curr.date().day();
    int w = (curr.date().dayOfWeek() == 7 ? 1 : (1 + curr.date().dayOfWeek()));
    int hh = curr.time().hour();
    int mm = curr.time().minute();

    str += (QString::number(y)  + SEP);
    str += (QString::number(m)  + SEP);
    str += (QString::number(d)  + SEP);
    str += (QString::number(w)  + SEP);
    str += (QString::number(hh) + SEP);
    str += (QString::number(mm) + SEP);
    str += (QString::number(0)  + SEP);

    disableWindow();
    m_currentComm = TIMESET;

    m_client->waitFor(_MTEMP_BOARD_OK);
    m_client->write(USRPSW + str + QString(_MTEMP_TIMESET));
}

void MTempClient::roomstat(){
    /*
     *  FORMATO STRINGA ROOMSTAT
     *  (CLIENT)    username*password*R*[ROOMSTAT]
     *  (SERVER)    (R*NAME*ADDRESS*RELAYOUT*STATE*ISFORCEDON*ISFORCEDOFF*TT*[OK] || [FAIL] || [ERROR])
     */
    disableWindow();
    m_currentComm = ROOMSTAT;

    m_client->waitFor(_MTEMP_BOARD_OK);
    m_client->write(USRPSW + QString::number(m_currentRoom->roomNumber()) + SEP + QString(_MTEMP_ROOMSTAT));
}

void MTempClient::roomset(QString name, quint8 addr, quint32 relayOut, GuiRoom::RoomMode mode){
    /*
     *  FORMATO STRINGA ROOMSET
     *  (CLIENT)    username*password*R*NAME*ADDRESS*RELAYOUT*FORCEON*FORCEOFF*AUTO*[ROOMSET]
     *  (SERVER)    ([OK] || [FAIL] || [ERROR])
     */
    QString str;

    disableWindow();
    m_currentComm = ROOMSET;

    str += (QString::number(m_currentRoom->roomNumber()) + SEP);
    str += (name + SEP);
    str += (QString::number(addr) + SEP);
    str += (QString::number(relayOut) + SEP);

    switch(mode){
        case GuiRoom::Auto:
            str += (QString(_MTEMP_DISABLED) + SEP);
            str += (QString(_MTEMP_DISABLED) + SEP);
            str += (QString(_MTEMP_ENABLED)  + SEP);
            break;
        case GuiRoom::ForcedOn:
            str += (QString(_MTEMP_ENABLED)  + SEP);
            str += (QString(_MTEMP_DISABLED) + SEP);
            str += (QString(_MTEMP_DISABLED) + SEP);
            break;
        case GuiRoom::ForcedOff:
            str += (QString(_MTEMP_DISABLED) + SEP);
            str += (QString(_MTEMP_ENABLED)  + SEP);
            str += (QString(_MTEMP_DISABLED) + SEP);
            break;
    }

    m_client->waitFor(_MTEMP_BOARD_OK);
    m_client->write(USRPSW + str + QString(_MTEMP_ROOMSET));
}

QDateTime MTempClient::parseTimeget(const QString &str){

    QDate date;
    QTime time;
    QDateTime res;
    QStringList list = str.split("*");
    date.setDate(2000 + list[0].toInt(), list[1].toInt(), list[2].toInt());
    time.setHMS(list[4].toInt(), list[5].toInt(), list[6].toInt());

    res.setTime(time);
    res.setDate(date);

    return res;
}

void MTempClient::on_timeRefreshButton_clicked(){

    timeget();
}

void MTempClient::on_timeSetButton_clicked(){

    timeset();
}

void MTempClient::updateRequestHandler(Room::RoomNumber num){

    setCurrentRoom(num);
    roomstat();
}

void MTempClient::forceOnRequestHandler(Room::RoomNumber num){

    setCurrentRoom(num);
    roomset(m_currentRoom->roomName(),
            m_currentRoom->sensorAddress(),
            m_currentRoom->relayOut(),
            GuiRoom::ForcedOn);
}

void MTempClient::forceOffRequestHandler(Room::RoomNumber num){

    setCurrentRoom(num);
    roomset(m_currentRoom->roomName(),
            m_currentRoom->sensorAddress(),
            m_currentRoom->relayOut(),
            GuiRoom::ForcedOff);
}

void MTempClient::forceAutoRequestHandler(Room::RoomNumber num){

    setCurrentRoom(num);
    roomset(m_currentRoom->roomName(),
            m_currentRoom->sensorAddress(),
            m_currentRoom->relayOut(),
            GuiRoom::Auto);
}


