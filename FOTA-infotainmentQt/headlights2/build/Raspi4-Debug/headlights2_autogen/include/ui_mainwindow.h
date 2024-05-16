/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *tesla;
    QLabel *label_4;
    QPushButton *back;
    QLabel *label_3;
    QPushButton *pushButton;
    QSlider *horizontalSlider;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1059, 779);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tesla = new QLabel(centralwidget);
        tesla->setObjectName(QString::fromUtf8("tesla"));
        tesla->setGeometry(QRect(150, 110, 781, 461));
        tesla->setStyleSheet(QString::fromUtf8("image: url(:/assets/teslaCar.png); border: none;"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(250, 240, 281, 211));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../AirController/assets/pressed-bg-up.png")));
        back = new QPushButton(centralwidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(10, 10, 31, 31));
        back->setStyleSheet(QString::fromUtf8("image: url(:/assets/back.png);\n"
"border: none;\n"
""));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(530, 280, 281, 211));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../AirController/assets/pressed-bg-down.png")));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(810, 320, 141, 91));
        pushButton->setStyleSheet(QString::fromUtf8("border: none;\n"
"image: url(:/assets/switch.png);\n"
";"));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(270, 550, 511, 61));
        horizontalSlider->setStyleSheet(QString::fromUtf8("color: rgb(224, 27, 36);"));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(270, 290, 281, 211));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../AirController/assets/pressed-bg-down.png")));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(550, 240, 281, 211));
        label_6->setPixmap(QPixmap(QString::fromUtf8("../AirController/assets/pressed-bg-up.png")));
        MainWindow->setCentralWidget(centralwidget);
        tesla->raise();
        label_4->raise();
        back->raise();
        label_3->raise();
        pushButton->raise();
        label_6->raise();
        label_5->raise();
        horizontalSlider->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1059, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        tesla->setText(QString());
        label_4->setText(QString());
        back->setText(QString());
        label_3->setText(QString());
        pushButton->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
