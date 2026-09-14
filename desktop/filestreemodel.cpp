#include "filestreemodel.h"

#include <QStandardItem>
#include <QFileIconProvider>

#include <filesystem>

namespace fs = std::filesystem;

FilesTreeModel::FilesTreeModel()
{
}

void FilesTreeModel::appendFileOrDir(QString multiplePathsText)
{
    QStringList pathTextSplitted = multiplePathsText.split('\n');
    for(QString & pathText : pathTextSplitted)
    {
        if(exists(pathText))
        {
            continue;
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
