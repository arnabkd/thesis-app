#include "jsonrequest.h"
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QDebug>


JSONrequest::JSONrequest(QWidget *parent) : QWidget(parent)
{
}

void JSONrequest::get(QString urlText)
{
    //Setup network manager and connect to reply slot
    QNetworkAccessManager *nam = new QNetworkAccessManager();
    connect(nam, SIGNAL(finished(QNetworkReply *)),
            this,SLOT(finished(QNetworkReply *)));

    nam->get(QNetworkRequest(QUrl(urlText)));
}

void JSONrequest::getAttendeeCount(QString fbEventid)
{
  //SELECT eid, attending_count  FROM event WHERE eid = 133735783393884
    QNetworkAccessManager *nam = new QNetworkAccessManager();
    connect(nam, SIGNAL(finished(QNetworkReply *)),
            this,SLOT(finished(QNetworkReply *)));

    QString url = "https://graph.facebook.com/fql?q=";
    QString query = "SELECT eid FROM event WHERE eid=" + fbEventid;
    QString token = "&accesstoken=CAAT9264KOJkBALB9QEuokBeYeqBPvYiqxlmb62t1VRIfvdcazLrIrCpqeWL20HHGE1RGcCwq2rZBBV876ZBZBoLNBBTHvvwpPsV4IZCX2i7XcUaZAHZCaGF1qTsH9YQAfXZA7FlzUxzOVyMI9jLPgLhyKlZBNclfEb4qHtDCw9cNESwKZBIXddsz05OdxoPKGkU0ZD";
    nam->get(QNetworkRequest(QUrl(url+query+token)));
}

void JSONrequest::finished(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        QString response = QString(reply->readAll());
        //qDebug() << response;
        //qDebug() << "finished response";
        emit output(response);
    }
    else
    {
        //qDebug() << "error";
        //qDebug() << reply->errorString();
        emit output(reply->errorString());
    }
}



