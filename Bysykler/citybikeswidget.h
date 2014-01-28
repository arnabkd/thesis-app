#ifndef CITYBIKESWIDGET_H
#define CITYBIKESWIDGET_H

#include <QWidget>
class QLineEdit;
class QPushButton;
class QGridLayout;
class JSONrequest;
class QPlainTextEdit;

class CityBikesWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CityBikesWidget(QWidget *parent = 0);
    
private:
    QLineEdit       * url;
    QPushButton     * getButton;
    QPushButton     * clearButton;
    QGridLayout     * layout;
    QPlainTextEdit  * console;

    JSONrequest * request;

private slots:
    void clicked();
};

#endif // CITYBIKESWIDGET_H
