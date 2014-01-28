#ifndef JSONREQUEST_H
#define JSONREQUEST_H
#define URL_PRE_2012 = "https://graph.facebook.com/fql?q=SELECTeid%20FROM%20event%20WHERE%20eid%20IN%20(SELECT%20eid%20FROM%20event_member%20WHERE%20uid%20=%20me()%20AND%20start_time%20%3C%201325376000)&access_token="
#include <QWidget>

class QNetworkReply;


class JSONrequest : public QWidget
{
    Q_OBJECT
public:
    JSONrequest(QWidget *parent);
    void get(QString urlText);

private:
    void getAttendeeCount(QString fbEventid);


private slots:
    void finished(QNetworkReply * reply);

signals:
    void output(QString s);

};

#endif // JSONREQUEST_H
