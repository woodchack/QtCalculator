#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    private slots:
    void numbers();
    void on_pushButton_point_clicked();
    void operations();
    void mathoper();

    void on_pushButton_equal_clicked();
    void on_pushButton_AC_clicked();
};
#endif // MAINWINDOW_H
