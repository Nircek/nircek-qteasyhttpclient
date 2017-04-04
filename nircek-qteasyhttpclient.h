#ifndef NIRCEKQTEASYHTTPCLIENT_H
#define NIRCEKQTEASYHTTPCLIENT_H
/*
You must add this lines to your .pro file:
QT+=network
QT+=widgets
*/
#include <QObject>
#include <QApplication>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QTimer>
#include <QEventLoop>
#include <QNetworkReply>
#include <QLoggingCategory>
namespace GitHub {
    namespace Nircek {
        QString qteasyhttpclient(QString uri,QObject *parent=nullptr);
    }
}
#endif // NIRCEKQTEASYHTTPCLIENT_H
