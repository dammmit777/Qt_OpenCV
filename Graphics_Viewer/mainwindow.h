#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPixmap>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QFileInfo>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QMainWindow>

#include <QDebug>

#include "qcustomgraphicseffect.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);


private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
};

#endif // MAINWINDOW_H
