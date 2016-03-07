#include "imageviewer.h"
#include "ui_imageviewer.h"

ImageViewer::ImageViewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImageViewer)
{
    ui->setupUi(this);
}

ImageViewer::~ImageViewer()
{
    delete ui;
}

void ImageViewer::setImage(const QString &fileName)
{
    ui->label->setPixmap(QPixmap(fileName));
    this->setWindowTitle(fileName);
}
