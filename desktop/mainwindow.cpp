#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "startwidget.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::mainWindow = this;

    int idx = ui->stackedWidget->addWidget(new StartWidget(ui->stackedWidget));
    ui->stackedWidget->setCurrentIndex(idx);
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow* MainWindow::mainWindow;

void MainWindow::nextWidget(QWidget *widget)
{
    int idx = MainWindow::mainWindow->ui->stackedWidget->addWidget(widget);
    MainWindow::mainWindow->ui->stackedWidget->setCurrentIndex(idx);
}

void MainWindow::prevWidget()
{
    QWidget *current = MainWindow::mainWindow->ui->stackedWidget->currentWidget();
    MainWindow::mainWindow->ui->stackedWidget->removeWidget(current);
    delete current;
}
