#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0; i <= 9; i++){
        QPushButton* button = findChild<QPushButton*>("N"+QString::number(i));
        connect(button, &QPushButton::clicked,this,&MainWindow::numberClickHandler);
    }

    connect(ui->clear,&QPushButton::clicked,this,&MainWindow::clearAndEnterClickHandler);
    connect(ui->enter,&QPushButton::clicked,this,&MainWindow::clearAndEnterClickHandler);
    connect(ui->add,&QPushButton::clicked,this,&MainWindow::addSubMulDivClickHandler);
    connect(ui->sub,&QPushButton::clicked,this,&MainWindow::addSubMulDivClickHandler);
    connect(ui->mul,&QPushButton::clicked,this,&MainWindow::addSubMulDivClickHandler);
    connect(ui->div,&QPushButton::clicked,this,&MainWindow::addSubMulDivClickHandler);

    state = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug()<< "Button name:" << name;

    if(button){
        if(state == 1){
            QString n = name.mid(1);
            number1.append(n);

            qDebug()<< "Number:" << number1;
            ui->num1->setText(number1);
        } else if (state == 2){
            QString n = name.mid(1);
            number2.append(n);

            qDebug()<< "Number:" << number2;
            ui->num2->setText(number2);
        }
    }
}

void MainWindow::clearAndEnterClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug()<< "Button name:" << name;

    if(button){
        if (name == "clear"){
            state = 1;
            number1.clear();
            number2.clear();
            MainWindow::resetLineEdits();
            qDebug()<<"Number1:"<< number1 <<"Number2:"<< number2;
        } else if (name == "enter"){
            state = 3;
            float n1 = number1.toFloat();
            float n2 = number2.toFloat();
            qDebug()<< "Number 1 = "<< n1 <<"Number 2 = "<< n2;

            switch (operand) {
            case 0:
                result = n1 + n2;
                break;
            case 1:
                result = n1-n2;
                break;
            case 2:
                result = n1*n2;
                break;
            case 3:
                result = n1/n2;
                break;
            default:
                break;
            }
            qDebug()<< "Result = "<< result;
            ui->Result->setText(QString::number(result));
        }
    }
}

void MainWindow::addSubMulDivClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug()<< "Button name:" << name;

    if(button){
        if (state == 1){
            if (name == "add"){
                operand = 0;
            } else if (name == "sub"){
                operand = 1;
            } else if (name == "mul"){
                operand = 2;
            } else if (name == "div"){
                operand = 3;
            }
            state = 2;
        }
    }
}

void MainWindow::resetLineEdits()
{
    ui->num1->clear();
    ui->num2->clear();
    ui->Result->clear();
}
