#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imageviewer.h"
#include "util.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete v;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    if (v != NULL) {
        delete v;
    }
    v = new ImageViewer();
    v->setImage(fileName);
    v->show();
    const int width = ui->lineEdit->text().toInt();
    const int height = ui->lineEdit_2->text().toInt();
    ui->textEdit->setText(QString::fromStdString(toASCII(fileName.toStdString(), width, height)));
}
