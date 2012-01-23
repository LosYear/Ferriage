#include "ldir.h"
#include "qstring.h"
#include "qdir.h"
#include "qcoreapplication.h"
#include "qfile.h"
#include "edits.h"

#include "qmessagebox.h"

lDir::lDir(Edits* gEdits)
{
    pEdits = gEdits;
}

void lDir::cpyFiles(QString background){
    // Копирование фон
    if( background != ""){
        QFile tmpBack(background);
        tmpBack.copy(QCoreApplication::applicationDirPath() + "/tmp/" + "background.obj");
    }
    // Копирование файлов "спрайтов"

    int nFiles = pEdits->getAmount();
    for( int i = 0; i < nFiles; i++){
        if (pEdits->getText(i) != ""){
            QFile file(pEdits->getText(i));
            file.copy(QCoreApplication::applicationDirPath() + "/tmp/" + QString::number(i) + ".obj");
        }
        else
        {
            QMessageBox errMSG;
            errMSG.setText("Error! File not exist or field is empty");
            errMSG.show();
        }
    }

}

// Удаление директории
int lDir::delDir(QDir* dir){
    int res = 0;
    //Получаем список каталогов
    QStringList lstDirs  = dir->entryList(QDir::Dirs | QDir::AllDirs | QDir::NoDotAndDotDot);
    //Получаем список файлов
    QStringList lstFiles = dir->entryList(QDir::Files);

    //Удаляем файлы
    foreach (QString entry, lstFiles)
    {
        QString entryAbsPath = dir->absolutePath() + "/" + entry;
        QFile::remove(entryAbsPath);
    }

    //Для папок делаем рекурсивный вызов
    foreach (QString entry, lstDirs)
    {
        QString entryAbsPath = dir->absolutePath() + "/" + entry;
        delDir(&QDir(entryAbsPath));
    }

    //Удаляем обрабатываемую папку
    if (!QDir().rmdir(dir->absolutePath()))
    {
        res = 1;
    }
    return res;
}

// Создание временной папки
void lDir::createTmpDir(){
    QString dirName = "tmp";
    QDir dir(QCoreApplication::applicationDirPath());
    dir.mkdir(dirName);
}
