#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QListWidgetItem>
#include <math.h>
#include <QListWidget>



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
    void on_pushButton_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QStringList list;
    QStringList list1;
    int wiersz;

};
#endif // MAINWINDOW_H
