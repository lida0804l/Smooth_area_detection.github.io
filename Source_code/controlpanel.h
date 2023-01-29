#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QDialog>
#include <lidascene.h>

namespace Ui {
class ControlPanel;
}

class ControlPanel : public QDialog
{
    Q_OBJECT

public:
    explicit ControlPanel(QWidget *parent = nullptr);
    ~ControlPanel();


    int rowSize;
    int colSize;
    float Nonsmoothness;
    LidaScene* scene;
    void set_config();

private slots:
    void on_lineEdit_rowSize_editingFinished();

    void on_lineEdit_colSize_editingFinished();

    void on_lineEdit_Nonsmoothness_editingFinished();

    void on_horizontalScrollBar_rowSize_valueChanged(int value);

    void on_horizontalScrollBar_colSize_valueChanged(int value);

    void on_horizontalScrollBar_Nonsmoothness_valueChanged(int value);

private:
    Ui::ControlPanel *ui;
};

#endif // CONTROLPANEL_H
