#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    QStringList acceptFileTypes;
    acceptFileTypes.append("jpg");
    acceptFileTypes.append("png");
    acceptFileTypes.append("bmp");

    if(event->mimeData()->hasUrls() &&
            event->mimeData()->urls().count() == 1)
    {
        QFileInfo file(event->mimeData()->urls().at(0).toLocalFile());
        if(acceptFileTypes.contains(file.suffix().toLower()))
        {
            event->acceptProposedAction();
        }
    }
}


void MainWindow::dropEvent(QDropEvent *event)
{
    QFileInfo file(event->mimeData()->urls().at(0).toLocalFile());
    if(pixmap.load(file.absoluteFilePath()))
    {
        ui->label->setPixmap(pixmap.scaled(ui->label->size(),
                                           Qt::KeepAspectRatio,
                                           Qt::SmoothTransformation));
    }
    else
    {
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("The image file cannot be read!"));
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    if(!pixmap.isNull())
    {
        ui->label->setPixmap(pixmap.scaled(ui->label->width()-5,
                                           ui->label->height()-5,
                                           Qt::KeepAspectRatio,
                                           Qt::SmoothTransformation));
    }
}
