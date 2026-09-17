#ifndef FILESTREEMODEL_H
#define FILESTREEMODEL_H

#include <QStandardItemModel>
#include <QTreeView>

class FilesTreeModel
{
public:
    QStandardItemModel treeModel;
    QTreeView *treeView;

    FilesTreeModel();
    void appendFiles(QString &);
    void appendFiles(QList<QUrl> &);
    void appendOneFile(QString &);
    void removeItem(QModelIndex &);

private:
    bool exists(QString &);
};

#endif // FILESTREEMODEL_H
