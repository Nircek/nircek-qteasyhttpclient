#ifndef NIRCEK_QTEASYHTTPCLIENT_CPP
#define NIRCEK_QTEASYHTTPCLIENT_CPP
#include <QObject>
#include <QApplication>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QTimer>
#include <QEventLoop>
#include <QNetworkReply>

QString qteasyhttpclient(QString uri,QObject *parent=nullptr){
    //inspired by https://github.com/bidstack/bidstack-http/
    QNetworkAccessManager *qnam = new QNetworkAccessManager();
    QNetworkRequest networkRequest(uri);
    networkRequest.setRawHeader(QString("Accept").toUtf8(),
                                QString("text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8").toUtf8());
    QNetworkReply *networkReply;
    networkReply = qnam->get(networkRequest);
    QTimer timer(parent);
    QEventLoop loop(parent);
    QObject::connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    QObject::connect(qnam, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
    timer.setSingleShot(true);
    timer.start(5000);
    loop.exec();
    if (timer.isActive()) {
        timer.stop();
    } else {
        networkReply->abort();
        return QString("/500");
    }
    QObject::disconnect(networkReply, SIGNAL(finished()), &loop, SLOT(quit()));
    int status=networkReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    if(status==0)status=110;
    if((status>=200)&&(status<300))
    return networkReply->readAll();
    return QString("/%1").arg(status);
}
#endif // NIRCEK__QTEASYHTTPCLIENT
