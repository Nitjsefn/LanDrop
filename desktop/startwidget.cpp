#include "startwidget.h"
#include "ui_startwidget.h"
#include "mainwindow.h"
#include "filechoosewidget.h"

StartWidget::StartWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartWidget)
{
    ui->setupUi(this);
}

StartWidget::~StartWidget()
{
    delete ui;
}

void StartWidget::on_chooseSendButton_clicked()
{
    MainWindow::nextWidget(new FileChooseWidget);
}


void StartWidget::on_chooseReceiveButton_clicked()
{

}

