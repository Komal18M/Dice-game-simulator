#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the push button signal to the rollDice slot
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::rollDice);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rollDice()
{
    int dice1 = QRandomGenerator::global()->bounded(1, 7); // 1 to 6
    int dice2 = QRandomGenerator::global()->bounded(1, 7);

    QString result = QString("You rolled:\nDice 1: %1\nDice 2: %2\nTotal: %3")
                         .arg(dice1)
                         .arg(dice2)
                         .arg(dice1 + dice2);

    QMessageBox::information(this, "Dice Roll Result", result);
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QMessageBox::information(this, "Item Clicked", "You clicked: " + item->text());
}
