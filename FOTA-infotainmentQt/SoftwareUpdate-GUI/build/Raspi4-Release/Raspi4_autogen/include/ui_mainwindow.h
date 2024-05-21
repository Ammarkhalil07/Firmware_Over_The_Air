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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *tesla;
    QPushButton *Download;
    QPushButton *close;
    QLabel *SoftUp;
    QPushButton *back;
    QPlainTextEdit *logger;
    QPushButton *wifi;
    QPushButton *noti;
    QPushButton *pushButton;
    QLabel *info;
    QLabel *waitLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1043, 736);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tesla = new QLabel(centralwidget);
        tesla->setObjectName(QString::fromUtf8("tesla"));
        tesla->setGeometry(QRect(160, 120, 721, 371));
        tesla->setStyleSheet(QString::fromUtf8("image: url(:/assets/twing.png); border: none;"));
        Download = new QPushButton(centralwidget);
        Download->setObjectName(QString::fromUtf8("Download"));
        Download->setGeometry(QRect(440, 550, 61, 61));
        Download->setStyleSheet(QString::fromUtf8("image: url(:/assets/down.png);\n"
"border: none;\n"
"hover{background:rgb(192, 191, 188)}"));
        Download->setIconSize(QSize(300, 300));
        close = new QPushButton(centralwidget);
        close->setObjectName(QString::fromUtf8("close"));
        close->setGeometry(QRect(980, 0, 41, 31));
        close->setStyleSheet(QString::fromUtf8("image: url(:/assets/close3.png);\n"
"border: none;\n"
""));
        close->setAutoExclusive(false);
        SoftUp = new QLabel(centralwidget);
        SoftUp->setObjectName(QString::fromUtf8("SoftUp"));
        SoftUp->setGeometry(QRect(60, 550, 381, 61));
        QFont font;
        font.setPointSize(24);
        font.setBold(false);
        SoftUp->setFont(font);
        SoftUp->setStyleSheet(QString::fromUtf8("color:rgb(246, 245, 244)"));
        back = new QPushButton(centralwidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(10, 10, 51, 31));
        back->setStyleSheet(QString::fromUtf8("image: url(:/assets/back.png);\n"
"border: none;\n"
""));
        logger = new QPlainTextEdit(centralwidget);
        logger->setObjectName(QString::fromUtf8("logger"));
        logger->setGeometry(QRect(820, 490, 201, 121));
        wifi = new QPushButton(centralwidget);
        wifi->setObjectName(QString::fromUtf8("wifi"));
        wifi->setGeometry(QRect(920, 0, 41, 31));
        wifi->setStyleSheet(QString::fromUtf8(" image: url(:/assets/wifi0.png)\\n; border: none; \\n"));
        noti = new QPushButton(centralwidget);
        noti->setObjectName(QString::fromUtf8("noti"));
        noti->setGeometry(QRect(860, 0, 41, 31));
        noti->setStyleSheet(QString::fromUtf8(" image: url(:/assets/not0.png)\\n; border: none; \\n"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(828, 10, 21, 20));
        info = new QLabel(centralwidget);
        info->setObjectName(QString::fromUtf8("info"));
        info->setGeometry(QRect(70, 10, 41, 31));
        info->setStyleSheet(QString::fromUtf8("image: url(:/assets/tes.png); border: none;"));
        waitLabel = new QLabel(centralwidget);
        waitLabel->setObjectName(QString::fromUtf8("waitLabel"));
        waitLabel->setGeometry(QRect(390, 570, 221, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(24);
        waitLabel->setFont(font1);
        waitLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralwidget);
        tesla->raise();
        SoftUp->raise();
        Download->raise();
        back->raise();
        close->raise();
        logger->raise();
        wifi->raise();
        noti->raise();
        pushButton->raise();
        info->raise();
        waitLabel->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1043, 22));
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
        Download->setText(QString());
        close->setText(QString());
        SoftUp->setText(QCoreApplication::translate("MainWindow", "SOFTWARE UPDATE", nullptr));
        back->setText(QString());
        wifi->setText(QString());
        noti->setText(QString());
        pushButton->setText(QString());
        info->setText(QString());
        waitLabel->setText(QCoreApplication::translate("MainWindow", "Please Wait !", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
