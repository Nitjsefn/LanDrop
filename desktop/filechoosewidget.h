#ifndef FILECHOOSEWIDGET_H
#define FILECHOOSEWIDGET_H

#include <QWidget>
#include <QStandardItemModel>

#include "filestreemodel.h"

namespace Ui {
class FileChooseWidget;
}

class FileChooseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FileChooseWidget(QWidget *parent = nullptr);
    ~FileChooseWidget();

private slots:
    void on_cancelButton_clicked();

    void on_addFButton_clicked();

    void on_removeButton_clicked();

    void on_addDButton_clicked();

private:
    Ui::FileChooseWidget *ui;
    FilesTreeModel filesTreeModel;

    void dragEnterEvent(QDragEnterEvent* ev);
    void dropEvent(QDropEvent *ev);
};

#endif // FILECHOOSEWIDGET_H
