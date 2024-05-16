#ifndef HEADLIGHTS_H
#define HEADLIGHTS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Headlights;
}
QT_END_NAMESPACE

class Headlights : public QMainWindow
{
    Q_OBJECT

public:
    Headlights(QWidget *parent = nullptr);
    /*******RESIZING WINDOW*****/
    void updateBackground();
    void resizeEvent(QResizeEvent *event);


    ~Headlights();
private slots:


    void on_back_clicked();

    void on_right_clicked();

    void on_left_clicked();

    void on_pushButton_clicked();
private:
    Ui::Headlights *ui;
};
#endif // HEADLIGHTS_H
