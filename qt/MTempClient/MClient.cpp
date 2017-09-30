#include "MClient.h"
#include "MTempDefs.h"

MClient::MClient(QObject *parent) : QObject(parent), m_sock(NULL), m_addr(), m_port(0), m_state(false), m_dataLen(0){
    /*  nulla da commentare                                                                         */
    m_sock = new QTcpSocket(this);
    /*  connetto i segnali della socket                                                             */
    connect(m_sock, SIGNAL(connected())         ,
            this  , SLOT(connectedBouncer())    );
    connect(m_sock, SIGNAL(disconnected())      ,
            this, SLOT(diconnectedBouncer())    );
    connect(m_sock, SIGNAL(readyRead())         ,
            this, SLOT(rxHandler())             );
    connect(m_sock, SIGNAL(bytesWritten(qint64) ),
            this, SLOT(txHandler(qint64))       );
    connect(m_sock, SIGNAL(error(QAbstractSocket::SocketError))   ,
            this, SLOT(errorBouncer(QAbstractSocket::SocketError)));
}

MClient::~MClient(){
    /*  se la socket è allocata                                                                     */
    if(m_sock){
        /*  la chiudo                                                                               */
        m_sock->close();
        /*  e libero la memoria                                                                     */
        delete m_sock;
    }
}

QString MClient::address() const{
    /*  nulla da commentare                                                                         */
    return m_addr;
}

quint16 MClient::port() const{
    /*  nulla da commentare                                                                         */
    return m_port;
}

bool MClient::connectToHost(){

    /*  chiudo la socket                                                                            */
    m_sock->close();
    /*  provo a connettermi                                                                         */
    m_sock->connectToHost(m_addr, m_port);
    return true;
}

bool MClient::disconnectFromHost(){
    /*  se non sono connesso                                                                        */
    if(!m_state){
        /*  ritorno false                                                                           */
        return false;
    }
    /*  mi disconnetto                                                                              */
    m_sock->disconnectFromHost();
    /*  ritorno true                                                                                */
    return true;
}

bool MClient::write(const QString &str){
    /*  se non sono connesso                                                                        */
    if(!m_state){
        /*  ritorno false                                                                           */
        return false;
    }
    /*  imposto la dimensione del dato                                                              */
    m_dataLen = str.toLocal8Bit().size();
    /*  scrivo sulla socket                                                                         */
    m_sock->write(str.toLocal8Bit());
    /*  ritorno true                                                                                */
    return true;
}

bool MClient::waitFor(const QString &str){
    /*  se non sono connesso                                                                        */
    if(!m_state){
        /*  ritorno false                                                                           */
        return false;
    }
    /*  imposto la keyword                                                                          */
    m_keyword = str;
    /*  ritorno true                                                                                */
    return true;
}

QString MClient::dataReceived() const{
    /*  ritorno il buffer                                                                           */
    return m_buffer;
}

void MClient::bufferClear(){
    /*  pulisco il buffer                                                                           */
    m_buffer.clear();
}

QString MClient::lastError() const{
    /*  ritorno l'ultimo errore                                                                     */
    return m_sock->errorString();
}

bool MClient::setAddress(const QString &addr){
    /*  se l'indirizzo è diverso da quello precedente                                               */
    if(m_addr != addr){
        /*  cambio l'indirizzo                                                                      */
        m_addr = addr;
        /*  ed emetto il segnale                                                                    */
        emit addressChanged(addr);
        /*  ritorno true                                                                            */
        return true;
    }
    /*  altrimenti ritorno false                                                                    */
    return false;
}

bool MClient::setPort(const quint16 &port){
    /*  se la porta è diverso da quella precedente                                                  */
    if(m_port != port){
        /*  cambio la porta                                                                         */
        m_port = port;
        /*  ed emetto il segnale                                                                    */
        emit portChanged(port);
        /*  ritorno true                                                                            */
        return true;
    }
    /*  altrimenti ritorno false                                                                    */
    return false;
}

void MClient::connectedBouncer(){
    /*  imposto il flag di connessione                                                              */
    m_state = true;
    /*  emetto il segnale                                                                           */
    emit connected();
}

void MClient::diconnectedBouncer(){
    /*  imposto il flag di connessione                                                              */
    m_state = false;
    /*  emetto il segnale                                                                           */
    emit disconnected();
}

void MClient::errorBouncer(const QAbstractSocket::SocketError err){
    /*  rimbalzo il segnale                                                                         */
    emit error(err);
}

void MClient::rxHandler(){
    /*  accodo quanto ricevuto al buffer                                                            */
    m_buffer += m_sock->readAll();
    qDebug() << m_buffer;
    /*  se il buffer contiene la keyword                                                            */
    if(m_buffer.contains(m_keyword)){
        /*  emetto il segnale                                                                       */
        emit answerReceived(TokenReceived);
    /*  se invece contiene la stringa che indica il fallimento dell'operazione                      */
    }else if(m_buffer.contains(_MTEMP_BOARD_FAIL)){
        emit answerReceived(Fail);
    /*  se invece contiene la stringa di errore del login                                           */
    }else if(m_buffer.contains(_MTEMP_BOARD_ERROR)){
        emit answerReceived(Error);
    }
}

void MClient::txHandler(qint64 bytes){
    /*  decremento il contatore dei bytes                                                           */
    m_dataLen -= bytes;
    /*  se ho finito di inviare                                                                     */
    if(!m_dataLen){
        /*  emetto il segnale                                                                       */
        emit dataSended();
    }
}


