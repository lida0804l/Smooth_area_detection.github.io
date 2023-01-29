#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QLabel>
#include <lidaimage.h>
#include <lidascene.h>
#include <iostream>
#include <math.h>
#include <controlpanel.h>
#include <fstream>

using namespace std;

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
    void on_actionload_triggered();

//    void on_actiontest_triggered();

    void on_actionControl_panel_triggered();

    void on_actionsave_as_csv_triggered();

private:
    Ui::MainWindow *ui;

    LidaImage* input;

    LidaScene* scene;
    ControlPanel* controlPanel;
    QGraphicsPixmapItem* pixmap_item;

//    FourierTransform* freq;

    void showImage(QImage*);

    static LidaImage* QImage2LidaImage(QImage* input);
    static QImage* LidaImage2QImage(LidaImage* input);
};
#endif // MAINWINDOW_H
