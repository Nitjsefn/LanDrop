#include "filechoosewidget.h"
#include "ui_filechoosewidget.h"
#include "mainwindow.h"

#include <QDragEnterEvent>
#include <QMimeData>
#include <QDropEvent>
#include <QFileDialog>

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
    filesTreeModel.appendFiles(text);
    qDebug() << text;
}

void FileChooseWidget::on_addFButton_clicked()
{

    QList<QUrl> urls = QFileDialog::getOpenFileUrls();
    filesTreeModel.appendFiles(urls);
}


void FileChooseWidget::on_removeButton_clicked()
{
    QModelIndex index = ui->treeView->currentIndex();
    if(index.isValid() == false)
    {
        return;
    }
    filesTreeModel.removeItem(index);
}


void FileChooseWidget::on_addDButton_clicked()
{
    QUrl url = QFileDialog::getExistingDirectoryUrl();
    QString path = url.toString();
    filesTreeModel.appendOneFile(path);
}

