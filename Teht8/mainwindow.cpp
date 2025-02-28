#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label->setStyleSheet("font: bold 16px;"
                             "padding: 5px;"
                             "text-align: center;");

    ui->label->setText("Choose Gamemode.");
    ui->label->adjustSize();
    ui->Player1Bar->setValue(0);
    ui->Player2Bar->setValue(0);

    connect(ui->P1Switch,&QPushButton::clicked,this,&MainWindow::SwitchClickHandler);
    connect(ui->P2Switch,&QPushButton::clicked,this,&MainWindow::SwitchClickHandler);
    connect(ui->Blitz,&QPushButton::clicked,this,&MainWindow::ModeClickHandler);
    connect(ui->Bullet,&QPushButton::clicked,this,&MainWindow::ModeClickHandler);
    connect(ui->Start,&QPushButton::clicked,this,&MainWindow::RunClickHandler);
    connect(ui->Stop,&QPushButton::clicked,this,&MainWindow::RunClickHandler);

    pQTimer = new QTimer(this);
    connect(pQTimer,&QTimer::timeout,this,&MainWindow::timeout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeout()
{
    if (currentPlayer == 1 && player1Time > 0){
        player1Time--;
        updateProgressBar();
    } else if (currentPlayer == 2 && player2Time > 0){
        player2Time--;
        updateProgressBar();
    }

    if (player1Time == 0 || player2Time == 0){
        pQTimer->stop();
        if (player1Time == 0){
            setGameInfoText("Player 2 Wins!", 1);
        } else {
            setGameInfoText("Palyer 1 Wins!", 1);
        }
    }
}

void MainWindow::updateProgressBar()
{
    if (currentPlayer == 1){
        ui->Player1Bar->setValue(player1Time);
    } else {
        ui->Player2Bar->setValue(player2Time);
    }
}

void MainWindow::setGameInfoText(QString text, short n)
{
    if (n == 1){
        ui->label->setStyleSheet("font: bold 20px;"
                                 "text-align: center;"
                                 "padding: 5px;");
    } else {
        ui->label->setStyleSheet("font: bold 16px;"
                                 "text-align: center;"
                                 "padding: 5px;");
    }

    ui->label->setText(text);
    ui->label->adjustSize();
}

void MainWindow::SwitchClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug()<< "Button name:" << name;

    if (currentPlayer == 1 && name == "P1Switch"){
        player1Time = ui->Player1Bar->value();
        setGameInfoText("Player 2 turn", 0);
        currentPlayer = 2;
    } else if (currentPlayer == 2 && name == "P2Switch"){
        player2Time = ui->Player2Bar->value();
        setGameInfoText("Player 1 turn", 0);
        currentPlayer = 1;
    }
}

void MainWindow::ModeClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug()<< "Button name:" << name;

    if (name == "Bullet"){
        player1Time = player2Time = gameTime = 120;
        setGameInfoText("120s Chosen", 0);
    } else {
        player1Time = player2Time = gameTime = 300;
        setGameInfoText("5min Chosen", 0);
    }

    ui->Player1Bar->setMaximum(player1Time);
    ui->Player2Bar->setMaximum(player2Time);
    ui->Player1Bar->setValue(player1Time);
    ui->Player2Bar->setValue(player2Time);
}

void MainWindow::RunClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug()<< "Button name:" << name;

    if (name == "Start"){
        currentPlayer = 1;
        if (player1Time > 0 && player2Time > 0){
            pQTimer->start(1000);
            setGameInfoText("Game Started!", 1);
        } else {
            setGameInfoText("Choose gamemode", 0);
        }

    } else {
        pQTimer->stop();
        setGameInfoText("Game Stoped!", 1);
    }
}
