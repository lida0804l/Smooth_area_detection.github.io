#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Nonsmooth detect - Area selection");

    input = 0;
//    image = new QImage();

    scene = new LidaScene();
    pixmap_item = new QGraphicsPixmapItem();

    controlPanel = new ControlPanel(this);   //-- Modaless
    controlPanel->scene = scene;
    controlPanel->setWindowTitle("Control Panel");

    QLabel *Name = new QLabel(this);
    Name->setText("by Ethan(Li-Ta) Chen");
    ui->statusbar->addPermanentWidget(Name);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionload_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(NULL, "Load Image", 0, "Image Files(*.jpg *.bmp *.png *tif)");
    if(!(fileName.isNull())){
        if(input != 0){
            delete input;
            cout << "image contained" << endl;
        }
        QImage* image = new QImage();
        image->load(fileName);
    //    scene->image = image;
        *image = image->convertToFormat(QImage::Format_RGB888);
        input = MainWindow::QImage2LidaImage(image);
        scene->lidaimage = input;
        MainWindow::showImage(image);
        delete image;
    }
}

void MainWindow::showImage(QImage* imageDisplay)
{
    pixmap_item->setPixmap(QPixmap::fromImage(*imageDisplay));

    QList<QGraphicsItem *> itemList = scene->items();
    if(itemList.contains(pixmap_item))
    {
        scene->removeItem(pixmap_item);
    }
    scene->pixmap_item = pixmap_item;
    scene->addItem(pixmap_item);
    scene->setSceneRect(pixmap_item->boundingRect());
    ui->graphicsView->setScene(scene);
}

LidaImage *MainWindow::QImage2LidaImage(QImage *input)
{
    LidaImage* output = new LidaImage(input->height(), input->width());
    for (int x = 0; x < input->height(); x++) {
        for (int y = 0; y < input->width(); y++) {
            int r = input->pixelColor(y,x).red();
            int g = input->pixelColor(y,x).green();
            int b = input->pixelColor(y,x).blue();
            output->matrix3D[0][x][y] = r;
            output->matrix3D[1][x][y] = g;
            output->matrix3D[2][x][y] = b;
        }
    }
    return output;
}

QImage *MainWindow::LidaImage2QImage(LidaImage *input)
{
    QImage* output = new QImage(input->col, input->row, QImage::Format_RGB888);
    for (int x = 0; x < output->height(); x++) {
        for (int y = 0; y < output->width(); y++) {
            int r = input->matrix3D[0][x][y];
            int g = input->matrix3D[1][x][y];
            int b = input->matrix3D[2][x][y];
            output->setPixel(y,x,qRgb(r,g,b));
        }
    }
    return output;
}

//void MainWindow::on_actiontest_triggered()
//{
////    scene->nonSmooth_detect_update();
////    cout << std::log2(5) << endl;
//    cout << this->controlPanel->rowSize << " " << this->controlPanel->colSize << " " << this->controlPanel->Nonsmoothness << endl;
//}

void MainWindow::on_actionControl_panel_triggered()
{
    controlPanel->set_config();
    controlPanel->show();
}

void MainWindow::on_actionsave_as_csv_triggered()
{
    QString savepath = QFileDialog::getSaveFileName(NULL, "Save detected rect", NULL, "Excel (*.csv)");
    ofstream outFile;
    outFile.open((savepath.toStdString()).c_str());

//    int rect_step_row = input->row / this->controlPanel->rowSize;
//    int rect_step_col = input->col / this->controlPanel->colSize;

//    float histogram[256];
//    for (int x = 0; (x+rect_step_row) < input->row; x += rect_step_row) {
//        for (int y = 0; (y+rect_step_col) < input->col; y += rect_step_col) {
//            for (int i = 0; i < 256; i++) {
//                histogram[i] = 0;
//            }

//            for (int i = 0; i < rect_step_row; i++) {
//                for (int j = 0; j < rect_step_col; j++) {
//                    int I = (input->matrix3D[0][x+i][y+j] + input->matrix3D[1][x+i][y+j] + input->matrix3D[2][x+i][y+j])/3;
////                    cout << I << " ";
//                    histogram[I]++;
//                }
//            }


//            float Entropy = 0;
//            for (int i = 0; i < 256; i++) {
//                if(histogram[i] > 0.00001){
//                    histogram[i] /= (rect_step_row * rect_step_col);
//                    Entropy += histogram[i] * std::log2(histogram[i]);
//                }
//            }
//            Entropy *= (-1);
////            cout << Entropy << " ";

//            if(Entropy < this->controlPanel->Nonsmoothness){
//                outFile << y << "," << x << "," << rect_step_col << "," << rect_step_row << endl;
//            }
//        }
//    }

    for (int i = 0; i < this->scene->rect_stacks.size(); i++) {
        QGraphicsRectItem* rect = this->scene->rect_stacks.at(i);
        outFile << rect->rect().x() << "," << rect->rect().y() << "," << rect->rect().width() << "," << rect->rect().height() << endl;
    }
    outFile.close();
}
