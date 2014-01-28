#include "citybikeswidget.h"
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QDebug>
#include <QTextEdit>
#include <QPlainTextEdit>
#include "jsonrequest.h"

CityBikesWidget::CityBikesWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(1024,768);
    url = new QLineEdit("URL here");
    getButton = new QPushButton("Get");
    clearButton = new QPushButton("Clear");
    console = new QPlainTextEdit();
    console->setReadOnly(true);
    request = new JSONrequest(this);

    layout = new QGridLayout(this);
    layout->addWidget(url, 0,0);
    layout->addWidget(getButton,0,1);
    layout->addWidget(clearButton,0,2);
    layout->addWidget(console, 1,0);

    //Connect signals
    connect(getButton,SIGNAL(clicked()), this, SLOT(clicked()));
    connect(clearButton, SIGNAL(clicked()), console, SLOT(clear()));
    connect(request, SIGNAL(output(QString)), console, SLOT(appendPlainText(QString)));
}

void CityBikesWidget::clicked()
{
    request->get(url->text());
}

