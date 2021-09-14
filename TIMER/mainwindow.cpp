#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDateTime> //used for time display
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(myfunction()));
    timer->start(1000); //for every one second time is incrementing
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myfunction()
{
//    qDebug() << "UPDATE..";
    QTime time=QTime::currentTime(); //used variable time to save current time in hh:mm:ss format
    QString time_text = time.toString("hh : mm : ss"); //converting time to string
    if ((time.second() % 2) == 0) {
        time_text[3] = ' ';
        time_text[8] = ' ';
    }
    ui -> label_date_time->setText(time_text); //displaying the time in label by using setText
}

