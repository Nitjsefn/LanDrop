#include "filechoosewidget.h"
#include "ui_filechoosewidget.h"
#include "mainwindow.h"

FileChooseWidget::FileChooseWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FileChooseWidget)
{
    ui->setupUi(this);
}

FileChooseWidget::~FileChooseWidget()
{
    delete ui;
}

void FileChooseWidget::on_cancelButton_clicked()
{
    MainWindow::prevWidget();
}

