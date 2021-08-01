#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//LISTVIEW

void MainWindow::on_pushButton_3_clicked() //Przycisk do odczytu
{
    QFile file(QFileDialog::getOpenFileName(this, tr("Otwórz Plik"),"",tr("Plik tekstowy (*.txt)")));
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream stream (&file);
    QString text = stream.readAll();
    list= text.split(",");
    int a=0;
    QStringList templist;
    while(a<list.count()){
    templist.append(list[a].split(" "));
    templist.removeLast();
    templist.removeLast();
    templist.last().append(",");
    a++;
    }
    a=0;
    QStringList templist2;
    QString text1;
    while(a<templist.count()){
        text1.append(templist[a]);
        a++;
        if((a+1)%2==0){
        text1.append(" ");
        }
    }
    templist2= text1.split(",");
    templist2.removeLast();
    model = new QStringListModel(this);
    model->setStringList(templist2);
    ui->listView->setModel(model);

    file.close();
}
void MainWindow::on_pushButton_4_clicked() //Przycisk do zapisu
{
    QString newImie,newNazwisko,newindeks,newocena;
    newImie=ui->textEdit->toPlainText();
    newNazwisko=ui->textEdit_2->toPlainText();
    newindeks=ui->textEdit_3->toPlainText();
    newocena=ui->textEdit_4->toPlainText();
    list[wiersz]=newImie;
    list[wiersz].append(" ");
    list[wiersz].append(newNazwisko);
    list[wiersz].append(" ");
    list[wiersz].append(newindeks);
    list[wiersz].append(" ");
    list[wiersz].append(newocena);
    int a=0;
    QStringList templist;
    while(a<list.count()){
    templist.append(list[a].split(" "));
    templist.removeLast();
    templist.removeLast();
    templist.last().append(",");
    a++;
    }
    a=0;
    QStringList templist2;
    QString text1;
    while(a<templist.count()){
        text1.append(templist[a]);
        a++;
        if((a+1)%2==0){
        text1.append(" ");
        }
    }
    templist2= text1.split(",");
    templist2.removeLast();
    model = new QStringListModel(this);
    model->setStringList(templist2);
    ui->listView->setModel(model);
    QString dopliku=list[0];
    int temp=list.count();
    int b=1;
    while(b<temp){
     dopliku.append(",").append(list[b]);
     b++;
}
        QFile file(QFileDialog::getOpenFileName(this, tr("Otwórz Plik"),"",tr("Plik tekstowy (*.txt)")));
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream stream (&file);
        stream<<dopliku;
}
void MainWindow::on_listView_clicked(const QModelIndex &index) //Reakcja na kliknięcie wiersza listy
{
    wiersz=index.row();
    list1=list[wiersz].split(" ");
    ui->textEdit->setText(list1[0]);
    ui->textEdit_2->setText(list1[1]);
    ui->textEdit_3->setText(list1[2]);
    ui->textEdit_4->setText(list1[3]);
}
