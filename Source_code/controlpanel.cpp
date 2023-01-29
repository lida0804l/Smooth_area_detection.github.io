#include "controlpanel.h"
#include "ui_controlpanel.h"

ControlPanel::ControlPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControlPanel)
{
    ui->setupUi(this);
}

ControlPanel::~ControlPanel()
{
    delete ui;
}

void ControlPanel::set_config()
{
    ui->lineEdit_rowSize->setText(QString("50"));
    ui->lineEdit_colSize->setText(QString("100"));
    ui->lineEdit_Nonsmoothness->setText(QString("2.5"));

    ui->horizontalScrollBar_rowSize->setRange(5,200);
    ui->horizontalScrollBar_colSize->setRange(5,200);
    ui->horizontalScrollBar_Nonsmoothness->setRange(0, 5000);
    ui->horizontalScrollBar_rowSize->setValue(50);
    ui->horizontalScrollBar_colSize->setValue(100);
    ui->horizontalScrollBar_Nonsmoothness->setValue(2500);
}

void ControlPanel::on_lineEdit_rowSize_editingFinished()
{
    ui->horizontalScrollBar_rowSize->setValue(ui->lineEdit_rowSize->text().toInt());
}

void ControlPanel::on_lineEdit_colSize_editingFinished()
{
    ui->horizontalScrollBar_colSize->setValue(ui->lineEdit_colSize->text().toInt());
}

void ControlPanel::on_lineEdit_Nonsmoothness_editingFinished()
{
    ui->horizontalScrollBar_Nonsmoothness->setValue(ui->lineEdit_Nonsmoothness->text().toFloat() * 1000);
}

void ControlPanel::on_horizontalScrollBar_rowSize_valueChanged(int value)
{
    ui->lineEdit_rowSize->setText(QString::number(value));
    this->rowSize = ui->lineEdit_rowSize->text().toInt();

    int rect_nums_row = ui->lineEdit_rowSize->text().toInt();
    int rect_nums_col = ui->lineEdit_colSize->text().toInt();
    float Entropy_thresh = ui->lineEdit_Nonsmoothness->text().toFloat();
    this->scene->nonSmooth_detect_update(rect_nums_row, rect_nums_col, Entropy_thresh);
}

void ControlPanel::on_horizontalScrollBar_colSize_valueChanged(int value)
{
    ui->lineEdit_colSize->setText(QString::number(value));
    this->colSize = ui->lineEdit_colSize->text().toInt();

    int rect_nums_row = ui->lineEdit_rowSize->text().toInt();
    int rect_nums_col = ui->lineEdit_colSize->text().toInt();
    float Entropy_thresh = ui->lineEdit_Nonsmoothness->text().toFloat();
    this->scene->nonSmooth_detect_update(rect_nums_row, rect_nums_col, Entropy_thresh);
}

void ControlPanel::on_horizontalScrollBar_Nonsmoothness_valueChanged(int value)
{
    ui->lineEdit_Nonsmoothness->setText(QString::number(value/1000.0));
    this->Nonsmoothness = ui->lineEdit_Nonsmoothness->text().toFloat();

    int rect_nums_row = ui->lineEdit_rowSize->text().toInt();
    int rect_nums_col = ui->lineEdit_colSize->text().toInt();
    float Entropy_thresh = ui->lineEdit_Nonsmoothness->text().toFloat();
    this->scene->nonSmooth_detect_update(rect_nums_row, rect_nums_col, Entropy_thresh);
}
