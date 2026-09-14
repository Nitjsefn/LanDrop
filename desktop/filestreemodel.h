#ifndef FILESTREEMODEL_H
#define FILESTREEMODEL_H

#include <QStandardItemModel>

class FilesTreeModel
{
public:
    QStandardItemModel treeModel;

    FilesTreeModel();
    void appendFileOrDir(QString);

private:
    bool exists(QString &);
};

#endif // FILESTREEMODEL_H
