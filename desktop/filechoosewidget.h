#ifndef FILECHOOSEWIDGET_H
#define FILECHOOSEWIDGET_H

#include <QWidget>

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

private:
    Ui::FileChooseWidget *ui;
};

#endif // FILECHOOSEWIDGET_H
