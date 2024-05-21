/********************************************************************************
** Form generated from reading UI file 'headligths.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEADLIGTHS_H
#define UI_HEADLIGTHS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Headligths
{
public:
    QLabel *tesla;
    QLabel *label_4;
    QLabel *label_3;
    QPushButton *left;
    QPushButton *right;
    QPushButton *back;
    QPushButton *pushButton;

    void setupUi(QDialog *Headligths)
    {
        if (Headligths->objectName().isEmpty())
            Headligths->setObjectName(QString::fromUtf8("Headligths"));
        Headligths->resize(1045, 736);
        Headligths->setWindowTitle(QString::fromUtf8("Dialog"));
        tesla = new QLabel(Headligths);
        tesla->setObjectName(QString::fromUtf8("tesla"));
        tesla->setGeometry(QRect(130, 50, 861, 461));
        tesla->setStyleSheet(QString::fromUtf8("image: url(:/assets/teslaCar.png); border: none;"));
        label_4 = new QLabel(Headligths);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(260, 220, 281, 211));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../AirController/assets/pressed-bg-up.png")));
        label_3 = new QLabel(Headligths);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(550, 200, 281, 211));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../AirController/assets/pressed-bg-down.png")));
        left = new QPushButton(Headligths);
        left->setObjectName(QString::fromUtf8("left"));
        left->setGeometry(QRect(100, 570, 191, 81));
        left->setStyleSheet(QString::fromUtf8("border: none;\n"
"image: url(:/assets/left.png);\n"
""));
        right = new QPushButton(Headligths);
        right->setObjectName(QString::fromUtf8("right"));
        right->setGeometry(QRect(820, 560, 191, 81));
        right->setStyleSheet(QString::fromUtf8("border: none;\n"
"image: url(:/assets/right.png);\n"
""));
        back = new QPushButton(Headligths);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(10, 20, 51, 41));
        back->setStyleSheet(QString::fromUtf8("image: url(:/assets/back.png);\n"
"border: none;\n"
""));
        pushButton = new QPushButton(Headligths);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(500, 550, 161, 41));
        tesla->raise();
        label_4->raise();
        label_3->raise();
        right->raise();
        left->raise();
        back->raise();
        pushButton->raise();

        retranslateUi(Headligths);

        QMetaObject::connectSlotsByName(Headligths);
    } // setupUi

    void retranslateUi(QDialog *Headligths)
    {
        tesla->setText(QString());
        label_4->setText(QString());
        label_3->setText(QString());
        left->setText(QString());
        right->setText(QString());
        back->setText(QString());
        pushButton->setText(QCoreApplication::translate("Headligths", "Turn off lights", nullptr));
        (void)Headligths;
    } // retranslateUi

};

namespace Ui {
    class Headligths: public Ui_Headligths {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEADLIGTHS_H
