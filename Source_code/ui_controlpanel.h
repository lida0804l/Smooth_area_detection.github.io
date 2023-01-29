/********************************************************************************
** Form generated from reading UI file 'controlpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLPANEL_H
#define UI_CONTROLPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ControlPanel
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_rowSize;
    QLabel *label_colSize;
    QLabel *label_Nonsmoothness;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_rowSize;
    QLineEdit *lineEdit_colSize;
    QLineEdit *lineEdit_Nonsmoothness;
    QVBoxLayout *verticalLayout_3;
    QScrollBar *horizontalScrollBar_rowSize;
    QScrollBar *horizontalScrollBar_colSize;
    QScrollBar *horizontalScrollBar_Nonsmoothness;

    void setupUi(QDialog *ControlPanel)
    {
        if (ControlPanel->objectName().isEmpty())
            ControlPanel->setObjectName(QString::fromUtf8("ControlPanel"));
        ControlPanel->resize(515, 112);
        verticalLayout_4 = new QVBoxLayout(ControlPanel);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_rowSize = new QLabel(ControlPanel);
        label_rowSize->setObjectName(QString::fromUtf8("label_rowSize"));
        QFont font;
        font.setPointSize(12);
        label_rowSize->setFont(font);

        verticalLayout->addWidget(label_rowSize);

        label_colSize = new QLabel(ControlPanel);
        label_colSize->setObjectName(QString::fromUtf8("label_colSize"));
        label_colSize->setFont(font);

        verticalLayout->addWidget(label_colSize);

        label_Nonsmoothness = new QLabel(ControlPanel);
        label_Nonsmoothness->setObjectName(QString::fromUtf8("label_Nonsmoothness"));
        label_Nonsmoothness->setFont(font);

        verticalLayout->addWidget(label_Nonsmoothness);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_rowSize = new QLineEdit(ControlPanel);
        lineEdit_rowSize->setObjectName(QString::fromUtf8("lineEdit_rowSize"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_rowSize->sizePolicy().hasHeightForWidth());
        lineEdit_rowSize->setSizePolicy(sizePolicy);
        lineEdit_rowSize->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lineEdit_rowSize);

        lineEdit_colSize = new QLineEdit(ControlPanel);
        lineEdit_colSize->setObjectName(QString::fromUtf8("lineEdit_colSize"));
        sizePolicy.setHeightForWidth(lineEdit_colSize->sizePolicy().hasHeightForWidth());
        lineEdit_colSize->setSizePolicy(sizePolicy);
        lineEdit_colSize->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lineEdit_colSize);

        lineEdit_Nonsmoothness = new QLineEdit(ControlPanel);
        lineEdit_Nonsmoothness->setObjectName(QString::fromUtf8("lineEdit_Nonsmoothness"));
        sizePolicy.setHeightForWidth(lineEdit_Nonsmoothness->sizePolicy().hasHeightForWidth());
        lineEdit_Nonsmoothness->setSizePolicy(sizePolicy);
        lineEdit_Nonsmoothness->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lineEdit_Nonsmoothness);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalScrollBar_rowSize = new QScrollBar(ControlPanel);
        horizontalScrollBar_rowSize->setObjectName(QString::fromUtf8("horizontalScrollBar_rowSize"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalScrollBar_rowSize->sizePolicy().hasHeightForWidth());
        horizontalScrollBar_rowSize->setSizePolicy(sizePolicy1);
        horizontalScrollBar_rowSize->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(horizontalScrollBar_rowSize);

        horizontalScrollBar_colSize = new QScrollBar(ControlPanel);
        horizontalScrollBar_colSize->setObjectName(QString::fromUtf8("horizontalScrollBar_colSize"));
        sizePolicy1.setHeightForWidth(horizontalScrollBar_colSize->sizePolicy().hasHeightForWidth());
        horizontalScrollBar_colSize->setSizePolicy(sizePolicy1);
        horizontalScrollBar_colSize->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(horizontalScrollBar_colSize);

        horizontalScrollBar_Nonsmoothness = new QScrollBar(ControlPanel);
        horizontalScrollBar_Nonsmoothness->setObjectName(QString::fromUtf8("horizontalScrollBar_Nonsmoothness"));
        sizePolicy1.setHeightForWidth(horizontalScrollBar_Nonsmoothness->sizePolicy().hasHeightForWidth());
        horizontalScrollBar_Nonsmoothness->setSizePolicy(sizePolicy1);
        horizontalScrollBar_Nonsmoothness->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(horizontalScrollBar_Nonsmoothness);


        horizontalLayout->addLayout(verticalLayout_3);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 5);

        verticalLayout_4->addLayout(horizontalLayout);


        retranslateUi(ControlPanel);

        QMetaObject::connectSlotsByName(ControlPanel);
    } // setupUi

    void retranslateUi(QDialog *ControlPanel)
    {
        ControlPanel->setWindowTitle(QApplication::translate("ControlPanel", "Dialog", nullptr));
        label_rowSize->setText(QApplication::translate("ControlPanel", "Number of rows:", nullptr));
        label_colSize->setText(QApplication::translate("ControlPanel", "Number of columns:", nullptr));
        label_Nonsmoothness->setText(QApplication::translate("ControlPanel", "Non smoothness:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControlPanel: public Ui_ControlPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLPANEL_H
