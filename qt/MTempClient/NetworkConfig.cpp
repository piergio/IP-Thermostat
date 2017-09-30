#include "NetworkConfig.h"
#include "ui_NetworkConfig.h"

NetworkConfig::NetworkConfig(QWidget *parent) : QDialog(parent), ui(new Ui::NetworkConfig){
    /*  espressione regolare per la password                                                        */
    QRegExp passRx("[0-9a-zA-Z]+");
    /*  espressione regolare per la porta                                                           */
    QRegExp portRx("^(?:6553[0-5]|655[0-2][0-9]|65[0-4][0-9]{2}|6[0-4][0-9]{3}|[1-5][0-9]{4}|[1-9][0-9]{1,3}|[1-9])$");
    /*  espressione regolare per l'indirizzo ip                                                     */
    QRegExp addrRx("(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[0-9][0-9]|[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[0-9][0-9]|[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[0-9][0-9]|[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[0-9][0-9]|[0-9])");
    /*  validator per password                                                                      */
    QRegExpValidator * passValidator = new QRegExpValidator(passRx, this);
    /*  validator per porta                                                                         */
    QRegExpValidator * portValidator = new QRegExpValidator(portRx, this);
    /*  validator per ip                                                                            */
    QRegExpValidator * addrValidator = new QRegExpValidator(addrRx, this);
    /*  stringa per pattern regexp per controllo campi                                              */
    QString rxPattern = "[\[]| |[\]]";
    /*  setto il pattern                                                                            */
    m_rx.setPattern(rxPattern);
    /*  setto come non case sensitive                                                               */
    m_rx.setCaseSensitivity(Qt::CaseInsensitive);
    /*  completamento interfaccia                                                                   */
    ui->setupUi(this);
    /*  imposto il titolo                                                                           */
    this->setWindowTitle("Configura Rete");
    /*  imposto le icone                                                                            */
    this->setWindowIcon(QIcon(":/ico/img/Settings-52.png"));
    /*  imposto il validator per la password1                                                       */
    ui->password1LineEdit->setValidator(passValidator);
    /*  imposto il validator per la password2                                                       */
    ui->password2LineEdit->setValidator(passValidator);
    /*  imposto il validator per la porta                                                           */
    ui->boardPortLineEdit->setValidator(portValidator);
    /*  imposto il validatore per l'ip                                                              */
    ui->boardIPLineEdit->setValidator(addrValidator);
    /*  fisso la lunghezza massima per il nome della rete                                           */
    ui->netNameLineEdit->setMaxLength(_MTEMP_SSID_LENGTH - 1);
    /*  fisso la lunghezza massima per la chiave di rete                                            */
    ui->netKeyLineEdit->setMaxLength(_MTEMP_SSID_KEY_LENGTH - 1);
    /*  fisso la lunghezza massima per l'username                                                   */
    ui->usernameLineEdit->setMaxLength(_MTEMP_USERNAME_LENGTH - 1);
    /*  fisso la lunghezza massima per la porta                                                     */
    ui->boardPortLineEdit->setMaxLength(5);
    /*  fisso la lunghezza massima per la password1                                                 */
    ui->password1LineEdit->setMaxLength(_MTEMP_USER_KEY_LENGTH - 1);
    /*  fisso la lunghezza massima per la password2                                                 */
    ui->password2LineEdit->setMaxLength(_MTEMP_USER_KEY_LENGTH - 1);
    /*  creo il loader per l'attesa                                                                 */
    m_loader = new Loader(this->windowTitle(), this);
    /*  nascondo il loader                                                                          */
    m_loader->hide();
    /*  creo il client                                                                              */
    m_client = new MClient(this);
    /*  imposto l'indirizzo di connessione                                                          */
    m_client->setAddress(_MTEMP_STANDARD_AP_IP);
    /*  imposto la porta                                                                            */
    m_client->setPort(_MTEMP_STANDARD_AP_PORT);

    /*  connetto i segnali                                                                          */
    connect(m_client, SIGNAL(connected())   ,
            this, SLOT(notifyConnected())   );
    /*  connetto i segnali                                                                          */
    connect(m_client, SIGNAL(disconnected()),
            this, SLOT(notifyDisconnected()));
    /*  connetto i segnali                                                                          */
    connect(m_client, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(notifyError(QAbstractSocket::SocketError)));
    /*  connetto i segnali                                                                          */
    connect(m_client, SIGNAL(answerReceived(MClient::BoardAnswer)),
            this, SLOT(rxHandler(MClient::BoardAnswer)));
    /*  imposto la stringa per il controllo password                                                */
    ui->passwordNotifierLabel->setText("La password è obbligatoria.");
}

NetworkConfig::~NetworkConfig(){

    delete ui;
}

void NetworkConfig::on_netKeyShowChecbox_clicked(bool checked){

    if(checked){
        ui->netKeyLineEdit->setEchoMode(QLineEdit::Normal);
    }else{
        ui->netKeyLineEdit->setEchoMode(QLineEdit::Password);
    }
}

void NetworkConfig::on_netNameLineEdit_textChanged(const QString &arg1){



    if(arg1.contains(m_rx)){
        QMessageBox::critical(this,
                              "Errore",
                              QString("Il nome della rete non può contenere ") +
                              QString("[, ], o spazi vuoti."));
        ui->netNameLineEdit->clear();
        return;
    }
    m_networkName = arg1;
    checkAll();
}

void NetworkConfig::on_netKeyLineEdit_textChanged(const QString &arg1){

    if(arg1.contains(m_rx)){
        QMessageBox::critical(this,
                              "Errore",
                              QString("La chiave di rete non può contenere ")  +
                              QString("[, ], o spazi vuoti."));
        ui->netKeyLineEdit->clear();
        return;
    }
    m_networkKey = arg1;
    checkAll();
}

void NetworkConfig::on_boardIPLineEdit_textChanged(const QString &arg1){

    m_boardIP = arg1;
    checkAll();
}

void NetworkConfig::on_usernameLineEdit_textChanged(const QString &arg1){

    if(arg1.contains(m_rx)){
        QMessageBox::critical(this,
                              "Errore",
                              QString("Il nome utente non può contenere ") +
                              QString("[, ], o spazi vuoti."));
        ui->usernameLineEdit->clear();
        return;
    }
    m_username = arg1;
    checkAll();
}

void NetworkConfig::on_password1LineEdit_textChanged(const QString &arg1){

    if(arg1.contains(m_rx)){
        QMessageBox::critical(this,
                              "Errore",
                              QString("La password non può contenere ")    +
                              QString("[, ], o spazi vuoti."));
        ui->password1LineEdit->clear();
        return;
    }
    m_password1 = arg1;
    /*  controllo password uguali o no                                                              */
    if(m_password1 != m_password2){
        ui->passwordNotifierLabel->setText("Le password non coincidono.");
    }else if(m_password1.isEmpty() || m_password2.isEmpty()){
        ui->passwordNotifierLabel->setText("La password è obbligatoria.");
    }else{
        ui->passwordNotifierLabel->setText("Le password coincidono.");
    }
    checkAll();
}

void NetworkConfig::on_password2LineEdit_textChanged(const QString &arg1){

    if(arg1.contains(m_rx)){
        QMessageBox::critical(this,
                              "Errore",
                              QString("La password non può contenere ")    +
                              QString("[, ], o spazi vuoti."));
        ui->password2LineEdit->clear();
        return;
    }
    m_password2 = arg1;
    /*  controllo password uguali o no                                                              */
    if(m_password1 != m_password2){
        ui->passwordNotifierLabel->setText("Le password non coincidono.");
    }else if(m_password1.isEmpty() || m_password2.isEmpty()){
        ui->passwordNotifierLabel->setText("La password è obbligatoria.");
    }else{
        ui->passwordNotifierLabel->setText("Le password coincidono.");
    }
    checkAll();
}

void NetworkConfig::on_boardPortLineEdit_textChanged(const QString &arg1){

    m_boardPort = arg1.toUInt();
    checkAll();

}

void NetworkConfig::on_clearButton_clicked(){

    clear();
}

void NetworkConfig::on_abortButton_clicked(){

    this->close();
}

void NetworkConfig::on_configureButton_clicked(){
    /*  provo a connettermi                                                                         */
    m_client->connectToHost();
    /*  mostro il loader                                                                            */
    m_loader->show();
    /*  imposto il messaggio                                                                        */
    m_loader->setMessage("Provo a connettermi alla centralina");
}

void NetworkConfig::notifyConnected(){
    /*  imposto il messaggio nel loader                                                             */
    m_loader->setMessage("Connesso alla centralina");
    /*  invio la configurazione                                                                     */
    sendConf();
}

void NetworkConfig::notifyError(QAbstractSocket::SocketError){

    QMessageBox::critical(this, "Errore", m_client->lastError());
    m_loader->hide();
}

void NetworkConfig::notifyDisconnected(){

    m_loader->setMessage("Disconnesso dalla centralina");
    m_loader->hide();
    this->close();
}

void NetworkConfig::rxHandler(MClient::BoardAnswer answer){

    QSettings setting;
    /*  controllo la risposta                                                                       */
    switch(answer){
        /*  se ho ricevuto l'ok                                                                     */
        case MClient::BoardAnswer::TokenReceived:
            /*  notifico l'ok                                                                       */
            QMessageBox::information(this, this->windowTitle(), "Centralina configurata correttamente.");

            setting.setValue(_MTEMP_PORT, m_boardPort);
            setting.setValue(_MTEMP_USER, m_username);
            setting.setValue(_MTEMP_PASS, m_password1);
            qDebug() << m_password1;
            break;
        /*  se ho ricevuto fail o error                                                             */
        case MClient::BoardAnswer::Error:
        case MClient::BoardAnswer::Fail:
            /*  notifico l'errore                                                                   */
            QMessageBox::critical(this, this->windowTitle(), "Errore nella configurazione della centralina.");
            break;
    }
    /*  mi disconnetto                                                                              */
    m_client->disconnectFromHost();
}


void NetworkConfig::clear(){

    ui->netNameLineEdit->clear();
    ui->netKeyLineEdit->clear();
    ui->boardIPLineEdit->clear();
    ui->boardPortLineEdit->clear();
    ui->usernameLineEdit->clear();
    ui->password1LineEdit->clear();
    ui->password2LineEdit->clear();
}

void NetworkConfig::checkAll(){

    if(!m_networkName.isEmpty()     &&
       !m_networkKey.isEmpty()      &&
       !m_boardIP.isEmpty()         &&
       (m_boardPort != 0)           &&
       !m_username.isEmpty()        &&
       !m_password1.isEmpty()       &&
       (m_password1 == m_password2)){
        ui->configureButton->setEnabled(true);
    }else{
        ui->configureButton->setEnabled(false);
    }
}

void NetworkConfig::sendConf(){
    QString str;
    /*  accodo il nome della rete                                                                   */
    str += m_networkName;
    /*  accodo il separatore                                                                        */
    str += _MTEMP_SEP;
    /*  accodo la chiave di rete                                                                    */
    str += m_networkKey;
    /*  accodo il separatore                                                                        */
    str += _MTEMP_SEP;
    /*  accodo l'indirizzo della scheda                                                             */
    str += m_boardIP;
    /*  accodo il separatore                                                                        */
    str += _MTEMP_SEP;
    /*  accodo la porta                                                                             */
    str += QString::number(m_boardPort);
    /*  accodo il separatore                                                                        */
    str += _MTEMP_SEP;
    /*  accodo l'username                                                                           */
    str += m_username;
    /*  accodo il separatore                                                                        */
    str += _MTEMP_SEP;
    /*  accodo la password                                                                          */
    str += m_password1;
    /*  accodo il separatore                                                                        */
    str += _MTEMP_SEP;
    /*  accodo il comando                                                                           */
    str += _MTEMP_CONF;
    /*  setto la stringa per l'ok                                                                   */
    m_client->waitFor(_MTEMP_BOARD_OK);
    /*  mando la configurazione                                                                     */
    m_client->write(str);
}



