#include "filechoosewidget.h"
#include "ui_filechoosewidget.h"
#include "mainwindow.h"

#include <QDragEnterEvent>
#include <QMimeData>
#include <QDropEvent>

FileChooseWidget::FileChooseWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FileChooseWidget)
{
    ui->setupUi(this);
    ui->treeView->setModel(&(filesTreeModel.treeModel));
}

FileChooseWidget::~FileChooseWidget()
{
    delete ui;
}

void FileChooseWidget::on_cancelButton_clicked()
{
    MainWindow::prevWidget();
}

void FileChooseWidget::dragEnterEvent(QDragEnterEvent *ev)
{
    if(ev->mimeData()->hasText())
    {
        ev->acceptProposedAction();
    }
}

void FileChooseWidget::dropEvent(QDropEvent *ev)
{
    if(ev->mimeData()->hasText() == false)
    {
        return;
    }
    QString text = ev->mimeData()->text();
    filesTreeModel.appendFileOrDir(text);
    qDebug() << text;
}
