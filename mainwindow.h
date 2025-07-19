#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>  // ✅ Required for QListWidgetItem*

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void rollDice();
    void on_listWidget_itemClicked(QListWidgetItem *item);  // ✅ Correct slot

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

