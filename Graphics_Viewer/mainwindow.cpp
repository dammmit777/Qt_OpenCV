#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setAcceptDrops(true);
    ui->graphicsView->setAcceptDrops(false);
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setInteractive(true);
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    ui->graphicsView->setRubberBandSelectionMode(
                Qt::ContainsItemShape);
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
    QPoint viewPos = ui->graphicsView->mapFromParent(event->pos());
    QPointF sceneDropPos = ui->graphicsView->mapToScene(viewPos);
    QFileInfo file(event->mimeData()->urls().at(0).toLocalFile());
    QPixmap pixmap;

    if(pixmap.load(file.absoluteFilePath()))
    {
        //scene.addPixmap(pixmap);
        QGraphicsPixmapItem *item =
                new QGraphicsPixmapItem(pixmap);
        //item->setGraphicsEffect(new QCustomGraphicsEffect(this));
        item->setPos(sceneDropPos);
        item->setFlag(QGraphicsItem::ItemIsSelectable);
        item->setAcceptedMouseButtons(Qt::LeftButton);
        scene.addItem(item);

        qDebug() << scene.items().count();
    }
    else
    {
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("The image file cannot be read!"));
    }
}
