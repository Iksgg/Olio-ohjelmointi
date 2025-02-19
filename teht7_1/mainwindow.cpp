#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Count,&QPushButton::clicked, this, &MainWindow::handelClick);
    connect(ui->Reset,&QPushButton::clicked, this, &MainWindow::handelClick);
    count = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handelClick()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug() << "Button name: " << name;

    if (button->objectName() == "Count"){
        count++;
    }

    if (button->objectName() == "Reset"){
        count = 0;
    }

    ui->lineEdit->setText(QString::number(count));
}
