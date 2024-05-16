/********************************************************************************
** Form generated from reading UI file 'headlights.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEADLIGHTS_H
#define UI_HEADLIGHTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Headlights
{
public:
    QWidget *centralwidget;
    QPushButton *right;
    QPushButton *pushButton;
    QLabel *label_3;
    QLabel *tesla;
    QLabel *label_4;
    QPushButton *left;
    QPushButton *back;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Headlights)
    {
        if (Headlights->objectName().isEmpty())
            Headlights->setObjectName(QString::fromUtf8("Headlights"));
        Headlights->resize(1059, 749);
        centralwidget = new QWidget(Headlights);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        right = new QPushButton(centralwidget);
        right->setObjectName(QString::fromUtf8("right"));
        right->setGeometry(QRect(660, 540, 191, 81));
        right->setStyleSheet(QString::fromUtf8("border: none;\n"
"image: url(:/assets/right.png);\n"
";"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(470, 550, 141, 91));
        pushButton->setStyleSheet(QString::fromUtf8("border: none;\n"
"image: url(:/assets/switch.png);\n"
";"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(530, 290, 281, 211));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../AirController/assets/pressed-bg-down.png")));
        tesla = new QLabel(centralwidget);
        tesla->setObjectName(QString::fromUtf8("tesla"));
        tesla->setGeometry(QRect(160, 110, 781, 461));
        tesla->setStyleSheet(QString::fromUtf8("image: url(:/assets/teslaCar.png); border: none;"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(250, 240, 281, 211));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../AirController/assets/pressed-bg-up.png")));
        left = new QPushButton(centralwidget);
        left->setObjectName(QString::fromUtf8("left"));
        left->setGeometry(QRect(220, 550, 191, 81));
        left->setStyleSheet(QString::fromUtf8("border: none;\n"
"image: url(:/assets/left.png);\n"
""));
        back = new QPushButton(centralwidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 10, 31, 31));
        back->setStyleSheet(QString::fromUtf8("image: url(:/assets/back.png);\n"
"border: none;\n"
""));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(250, 290, 281, 211));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../AirController/assets/pressed-bg-down.png")));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(550, 230, 281, 211));
        label_6->setPixmap(QPixmap(QString::fromUtf8("../AirController/assets/pressed-bg-up.png")));
        Headlights->setCentralWidget(centralwidget);
        tesla->raise();
        label_6->raise();
        right->raise();
        pushButton->raise();
        label_3->raise();
        label_4->raise();
        left->raise();
        back->raise();
        label_5->raise();
        menubar = new QMenuBar(Headlights);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1059, 22));
        Headlights->setMenuBar(menubar);
        statusbar = new QStatusBar(Headlights);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Headlights->setStatusBar(statusbar);

        retranslateUi(Headlights);

        QMetaObject::connectSlotsByName(Headlights);
    } // setupUi

    void retranslateUi(QMainWindow *Headlights)
    {
        Headlights->setWindowTitle(QCoreApplication::translate("Headlights", "Headlights", nullptr));
        right->setText(QString());
        pushButton->setText(QString());
        label_3->setText(QString());
        tesla->setText(QString());
        label_4->setText(QString());
        left->setText(QString());
        back->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Headlights: public Ui_Headlights {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEADLIGHTS_H
