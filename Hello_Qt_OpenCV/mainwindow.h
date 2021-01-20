#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QCloseEvent>
#include <QSettings>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

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
    void closeEvent(QCloseEvent *event);
private slots:
    void on_inputPushButton_pressed();

    void on_outputPushButton_pressed();

private:
    Ui::MainWindow *ui;

    void loadSettings();
    void saveSettings();
};

#endif // MAINWINDOW_H
