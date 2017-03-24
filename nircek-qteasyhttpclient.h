#ifndef NIRCEKQTEASYHTTPCLIENT_H
#define NIRCEKQTEASYHTTPCLIENT_H
#include <QObject>
#include <QApplication>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QTimer>
#include <QEventLoop>
#include <QNetworkReply>
namespace GitHub {
    namespace Nircek {
        QString qteasyhttpclient(QString uri,QObject *parent=nullptr);
    }
}
#endif // NIRCEKQTEASYHTTPCLIENT_H
