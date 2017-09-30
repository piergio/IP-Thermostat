#ifndef MT_CLIENT_H
#define MT_CLIENT_H

#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <QHostInfo>

class MClient : public QObject{

        Q_OBJECT
        Q_PROPERTY(QString address READ address WRITE setAddress NOTIFY addressChanged)
        Q_PROPERTY(quint16 port READ port WRITE setPort NOTIFY portChanged)

    public:

        enum BoardAnswer{
            Fail,
            Error,
            TokenReceived
        };

        explicit MClient(QObject *parent = 0);
        ~MClient();
        QString address() const;
        quint16 port() const;


    signals:
        void addressChanged(QString newAddress);
        void portChanged(quint16 newPort);
        void connected();
        void disconnected();
        void error(QAbstractSocket::SocketError lastError);
        void answerReceived(MClient::BoardAnswer res);
        void dataSended();

    public slots:
        Q_INVOKABLE bool connectToHost();
        Q_INVOKABLE bool disconnectFromHost();
        Q_INVOKABLE bool write(const QString & str);
        Q_INVOKABLE bool waitFor(const QString & str);
        Q_INVOKABLE QString dataReceived() const;
        Q_INVOKABLE void bufferClear();
        Q_INVOKABLE QString lastError() const;
                    bool setAddress(const QString & addr);
                    bool setPort(const quint16 & port);
    private slots:
        void connectedBouncer();
        void diconnectedBouncer();
        void errorBouncer(const QAbstractSocket::SocketError err);
        void rxHandler();
        void txHandler(qint64 bytes);

    private:
        QTcpSocket * m_sock;
        QString      m_addr;
        quint16      m_port;
        QString      m_buffer;
        QString      m_keyword;
        bool         m_state;
        quint32      m_dataLen;
};

#endif // MT_CLIENT_H
