#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "citybikeswidget.h"

#include <QGridLayout>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CityBikesWidget *mainwidget = new CityBikesWidget(this->centralWidget());
    adjustSize();
    setFixedSize(1024,768);
    mainwidget->show();
    //this->setCentralWidget(mainwidget);

//    url = new QLineEdit("URL here");
//    button = new QPushButton("Click to get");

//    layout = new QGridLayout(this);
//    layout->addWidget(url, 0,0);
//    layout->addWidget(button,0,1);

//    request = new JSONrequest(this);
//    connect(button,SIGNAL(clicked()), this, SLOT(clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

