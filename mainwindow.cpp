#include "mainwindow.h"
#include "./ui_mainwindow.h"

double first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, &QPushButton::released, this, &MainWindow::numbers);
    connect(ui->pushButton_1, &QPushButton::released, this, &MainWindow::numbers);
    connect(ui->pushButton_2, &QPushButton::released, this, &MainWindow::numbers);
    connect(ui->pushButton_3, &QPushButton::released, this, &MainWindow::numbers);
    connect(ui->pushButton_4, &QPushButton::released, this, &MainWindow::numbers);
    connect(ui->pushButton_5, &QPushButton::released, this, &MainWindow::numbers);
    connect(ui->pushButton_6, &QPushButton::released, this, &MainWindow::numbers);
    connect(ui->pushButton_7, &QPushButton::released, this, &MainWindow::numbers);
    connect(ui->pushButton_8, &QPushButton::released, this, &MainWindow::numbers);
    connect(ui->pushButton_9, &QPushButton::released, this, &MainWindow::numbers);
    connect(ui->pushButton_plusminus, &QPushButton::released, this, &MainWindow::operations);
    connect(ui->pushButton_plus, &QPushButton::released, this, &MainWindow::mathoper);
    connect(ui->pushButton_minus, &QPushButton::released, this, &MainWindow::mathoper);
    connect(ui->pushButton_multiply, &QPushButton::released, this, &MainWindow::mathoper);
    connect(ui->pushButton_divide, &QPushButton::released, this, &MainWindow::mathoper);
    connect(ui->pushButton_percent, &QPushButton::released, this, &MainWindow::operations);

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numbers()
{
    QPushButton *button = static_cast<QPushButton*>(sender());
    double numbers;
    QString new_label;

    if(ui->label->text().contains(".") && button->text() == "0")
    {
        new_label = ui->label->text() + button->text();
    } else
    {

    numbers = (ui->label->text()+ button->text()).toDouble();
    new_label = QString::number(numbers, 'g', 15);
    }
    ui->label->setText(new_label);
}

void MainWindow::on_pushButton_point_clicked()
{
    if(!(ui->label->text().contains('.')))
    {
       ui->label->setText(ui->label->text() + ".");
    }
}

void MainWindow::operations()
{
    QPushButton *button = static_cast<QPushButton*>(sender());
    double numbers;
    QString new_label;

    if(button->text() == "+/-")
    {
        numbers = (ui->label->text().toDouble());
        numbers *= -1;
        new_label = QString::number(numbers, 'g', 15);
        ui->label->setText(new_label);
    } else if((button->text() == "%"))
    {
        numbers = (ui->label->text().toDouble());
        numbers *= 0.01;
        new_label = QString::number(numbers, 'g', 15);
        ui->label->setText(new_label);
    }
}

void MainWindow::mathoper()
{
    QPushButton *button = static_cast<QPushButton*>(sender());

    first = ui->label->text().toDouble();

    ui->label->setText("");

    button->setChecked(true);


}


void MainWindow::on_pushButton_equal_clicked()
{
    double labelNum, second;
    QString label;

    second = ui->label->text().toDouble();

    if(ui->pushButton_plus->isChecked())
    {
        labelNum = first + second;
        label = QString::number(labelNum, 'g', 15);
        ui->label->setText(label);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked())
    {
        labelNum = first - second;
        label = QString::number(labelNum, 'g', 15);
        ui->label->setText(label);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_multiply->isChecked())
    {
        labelNum = first * second;
        label = QString::number(labelNum, 'g', 15);
        ui->label->setText(label);
        ui->pushButton_multiply->setChecked(false);
    }
    else if(ui->pushButton_divide->isChecked())
    {
        if(second == 0)
        {
            ui->label->setText("0");
        }
        else{
        labelNum = first / second;
        label = QString::number(labelNum, 'g', 15);
        ui->label->setText(label);
        ui->pushButton_divide->setChecked(false);
        }


    }
}


void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);

    ui->label->setText("");

}

