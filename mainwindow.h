#ifndef MAINWINDOW_hpp
#define MAINWINDOW_hpp

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QImage>
#include <ctime>
#include <cstdlib>
#include <QMessageBox>
#include <QPainter>
#include <random>
#include <stdexcept>


#include "vmf.h"
#include "pgf.h"
#include "functions.h"
#include "drawing.h"
#include "accuracy.h"
#include "noise.h"
#include "imgquality.h"

//QT_CHARTS_USE_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonLoad_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_filterButton_clicked();

    void on_btnSaveCorr_clicked();

    void on_btnSaveFix_clicked();

    void on_btnSaveMap_clicked();

    void on_btnShowMap_clicked();

    void on_loadCorr_clicked();

    void on_loadFixed_clicked();

private:
    Ui::MainWindow *ui;
    QImage raw, corrupted,fixed_img;
    VMF fixed;
    PGF fixedPGF;
    QPainter painter;
    Drawing drawing;


};

#endif //MAINWINDOW_hpp
