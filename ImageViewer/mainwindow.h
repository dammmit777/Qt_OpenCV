#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPixmap>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QFileInfo>
#include <QMessageBox>
#include <QResizeEvent>
#include <QMainWindow>

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
    void resizeEvent(QResizeEvent *event);

private:
    Ui::MainWindow *ui;
    QPixmap pixmap;
};

#endif // MAINWINDOW_H
