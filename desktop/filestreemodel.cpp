#include "filestreemodel.h"

#include <QStandardItem>
#include <QFileIconProvider>
#include <QUrl>

#include <filesystem>

namespace fs = std::filesystem;

FilesTreeModel::FilesTreeModel()
{
}

void FilesTreeModel::appendFiles(QString & multiplePathsText)
{
    QStringList pathTextSplitted = multiplePathsText.split('\n');
    for(QString & pathText : pathTextSplitted)
    {
        appendOneFile(pathText);
    }
}

bool FilesTreeModel::exists(QString & pathText)
{
    for(size_t i = 0; i < treeModel.rowCount(); i++)
    {
        QStandardItem *existingStandardItem = (QStandardItem *)treeModel.item(i);
        if(existingStandardItem->text() == pathText)
        {
            return true;
        }
    }

    return false;
}

void FilesTreeModel::appendFiles(QList<QUrl> & urls)
{
    for(QUrl & url : urls)
    {
        QString pathText = url.toString();
        appendOneFile(pathText);
    }
}

void FilesTreeModel::appendOneFile(QString & pathText)
{
    // QString pathPrefix = "file://";
    // if(pathText.startsWith(pathPrefix))
    // {
    //     pathText = pathText.last(pathText.length() - pathPrefix.length());
    // }

    if(exists(pathText))
    {
        return;
    }

    const std::string pathString = pathText.toStdString();
    QFileIconProvider iconProv;

    QStandardItem *item = new QStandardItem(pathText);
    if(fs::is_directory(pathString) == true)
    {
        item->setIcon(iconProv.icon(QFileIconProvider::Folder));
    }
    else
    {
        item->setIcon(iconProv.icon(QFileIconProvider::File));
    }
    treeModel.appendRow(item);
}

void FilesTreeModel::removeItem(QModelIndex & index)
{
    treeModel.removeRow(index.row());
}
