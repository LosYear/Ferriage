#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QPainter>
#include "ldir.h"
#include <QTextStream>
#include <QByteArray>

#include "libs/quazip/quazip.h"
#include "libs/quazip/quazipfile.h"


void MainWindow::initVector( int n ){
    // Initializing vector
    rules.resize(n);
    for ( int i = 0; i < n; i++){
        rules[i].resize(n);
        for ( int j = 0; j < n ; j++){
            rules[i][j] = 1;
        }
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    edits = new Edits(3);
    edits->ShowEdits(ui->centralWidget, 10, 140, 200, 20, 30);
    cDir = new lDir(edits);
}

MainWindow::~MainWindow()
{
    QDir dir(QCoreApplication::applicationDirPath() + "/tmp");
    cDir->delDir(&dir);
    delete cDir;
    delete edits;
    delete ui;
}

void MainWindow::on_toolButton_clicked()
{
    QFileDialog* openDialog = new QFileDialog;
    QString fileName;
    fileName=openDialog->getOpenFileName(this,"Choose your destiny!","/",tr("Image Files(*.png *.jpg *bmp)"));
    ui->background->setText(fileName);
    QPixmap* pix = new QPixmap(fileName);
    *pix = pix->scaled(800,600,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->picture->setPixmap(*pix);
    ui->picture->adjustSize();
}

void MainWindow::on_selectButton_clicked()
{
    QDir dir(QCoreApplication::applicationDirPath() + "/tmp");
    cDir->delDir(&dir);
    for(int i = 0; i < ui->spinBox->value(); i++)
    {
        QFileDialog* openDialog = new QFileDialog;
        QString fileName;
        fileName = openDialog->getOpenFileName(this,"123","/",tr("Image Files(*.png *.jpg *bmp)"));
        edits->setText(i, fileName);
        delete openDialog;
    }
    cDir->createTmpDir();
}

void MainWindow::on_spinBox_valueChanged(int )
{
    edits->NewAmount(ui->spinBox->value());
    edits->ShowEdits(ui->centralWidget, 10, 140, 200, 20, 30);
}

void MainWindow::on_actionReadyClicked_triggered()
{
    initVector(ui->spinBox->value());
    QString text = ui->plainTextEdit->toPlainText();
    text = text.simplified();

    // Filling Vector of Rules
    int a,b;
    a = -1;
    b = -1;
    bool isA = true;
    for (int i = 0; i < text.length(); i++){
        QChar tmp = text[i];
        if( tmp != ' ' && tmp != '!' && tmp.isDigit()){
            if (( tmp.digitValue() > ui->spinBox->value() ) || ( tmp.digitValue() < 0 )){
                QMessageBox* errMSG = new QMessageBox;
                errMSG->setText(QString::fromLocal8Bit("#0001 Номер объекта слишком велик"));
                errMSG->show();
                return;
            }
            else{
                if (isA){
                    a = tmp.digitValue();
                    isA = false;
                }
                else {
                    b = tmp.digitValue();
                    isA = true;

                    rules[a-1][b-1] = 0;
                    rules[b-1][a-1] = 0;

                }
            }
        }
    }

    //Writing Rules into file
    QFile fRules ( QCoreApplication::applicationDirPath() + "/tmp/rules" );
    if (!fRules.open(QIODevice::WriteOnly | QIODevice::Text)){
         QMessageBox* errMSG = new QMessageBox;
         errMSG->setText(QString::fromLocal8Bit("#0002 Ошибка при записи в файл. Проверьте имеет ли программа права, на запись в данную дерикторию"));
         errMSG->show();
         return;
    }
    QTextStream tsRules(&fRules);
    for ( int i = 0; i < ui->spinBox->value(); i++){
        for ( int j = 0; j < ui->spinBox->value(); j++){
            tsRules << rules[i][j] << " ";
        }
        tsRules << "\n";

    }
    tsRules.flush();
    fRules.flush();
    fRules.close();

    //Copying files
    cDir->cpyFiles(ui->background->text());

    //Writing Info
    QFile fInfo( QCoreApplication::applicationDirPath() + "/tmp/info" );
    if (!fInfo.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox* errMSG = new QMessageBox;
        errMSG->setText(QString::fromLocal8Bit("#0003 Ошибка при записи в файл. Проверьте имеет ли программа права, на запись в данную дерикторию"));
        errMSG->show();
        return;
    }
    QTextStream tsInfo(&fInfo);
    tsInfo << QString::number(ui->spinBox->value()) + "\n\"" + ui->name->text() + "\"\n";
    tsInfo.flush();
    fInfo.flush();
    fInfo.close();

    // Compressing Zip with QuaZip

    QFileDialog* saveDialog = new QFileDialog;
    QString fileName;
    fileName = saveDialog->getSaveFileName(this,QString::fromLocal8Bit("Выберите имя файла"),"/",QString::fromLocal8Bit("Файл заданий Ferriage(*.fer)"));

    QFile zipFile(fileName);
    QuaZip zip(&zipFile);

    if(!zip.open(QuaZip::mdCreate)) {
      qWarning("testCreate(): zip.open(): %d", zip.getZipError());
      return;
    }

    QDir tmpDir( QCoreApplication::applicationDirPath() + "/tmp");
    QFileInfoList files = tmpDir.entryInfoList();
    QFile inFile;
    QuaZipFile outFile(&zip);
    char c;

    foreach (QFileInfo file, files) {
        inFile.setFileName(file.fileName());
        if( !inFile.open(QIODevice::ReadOnly)){
            qWarning("testCreate(): inFile.open(): %s", inFile.errorString().toLocal8Bit().constData());
            break;
        }
        if( !outFile.open(QIODevice::WriteOnly, QuaZipNewInfo(inFile.fileName(),inFile.fileName()))){
            qWarning("testCreate(): outFile.open(): %d", outFile.getZipError());
            break;
        }
        qint64 len = file.size();
        qint64 pos = 0;
        while ( inFile.getChar(&c) && outFile.putChar(c) ){
            char buf[4096];
            qint64 l = inFile.read(buf,4096);
            if( l < 0 ){
                qWarning("read(): %s", inFile.errorString().toUtf8().constData());
                break;
            }
            if ( l == 0 )
                break;
            if ( outFile.write(buf,1) != l){
                qWarning("write(): %d", outFile.getZipError());
                break;
            }
            pos += 1;
            if ( pos % 1048576 == 0){
                qDebug("%.1f", (float) pos / len * 100.0f);
            }

        }
        if (outFile.getZipError() != UNZ_OK){
            qWarning("testCreate(): outFile.putChar(): %d", outFile.getZipError());
            break;
        }
        outFile.close();
        if ( outFile.getZipError()!= UNZ_OK ){
            qWarning("testCreate(): outFile.close(): %d", outFile.getZipError());
            break;
        }
        inFile.close();

    }
    zip.close();
    if ( zip.getZipError() != 0){
       qWarning("testCreate(): zip.close(): %d", zip.getZipError());
       return;
    }

}


/*
    //Compresing Zip
    QFileDialog* saveDialog = new QFileDialog;
    QString fileName;
    fileName = saveDialog->getSaveFileName(this,QString::fromLocal8Bit("Выберите имя файла"),"/",QString::fromLocal8Bit("Файл заданий Ferriage(*.fer)"));

    QZipWriter* zip = new QZipWriter(fileName);
    if( zip->status() != QZipWriter::NoError){
        QMessageBox* errMSG = new QMessageBox;
        errMSG->setText(QString::fromLocal8Bit("#0004 Ошибка при записи в файл. Проверьте имеет ли программа права, на запись в данную дерикторию"));
        errMSG->show();
        return;
    }
    zip->setCompressionPolicy(QZipWriter::AutoCompress);
    for( int i = 0; i < ui->spinBox->value(); i++){
        QString file_name = QString("%1.obj").arg(i);
        QString file_path = QCoreApplication::applicationDirPath() + "/tmp/" + QString::number(i) + ".obj";
        QFile file(file_path);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox* errMSG = new QMessageBox;
            errMSG->setText(QString::fromLocal8Bit("#0005 Ошибка при создании архива."));
            errMSG->show();
            return;
        }

        zip->setCreationPermissions(QFile::permissions(file_path));
        zip->addFile(file_name, file.readAll());
        zip->close();
    }
    zip->close();
    delete zip;

}

void MainWindow::on_buttonUnPack_clicked()
{
    QString text = "";
    QFileDialog* openDialog = new QFileDialog;
    QString fileName = openDialog->getOpenFileName(this,QString::fromLocal8Bit("Выберите имя файла"),"/",QString::fromLocal8Bit("Файл заданий Ferriage(*.fer)"));
    QZipReader *zip = new QZipReader(fileName);
    if (zip->exists()) {
        // вывод информации об архиве
        text += "Number of items in the zip archive =" + zip->count();
        foreach (QZipReader::FileInfo info, zip->fileInfoList()) {
            if(info.isFile)
                text += "File:" + info.filePath + info.size;
            else if (info.isDir)
                text += "Dir:" + info.filePath;
            else
                text += "SymLink:" + info.filePath;
        }

        // распаковка архива по указанному пути
        zip->extractAll("./");
    }
    QMessageBox MSG;
    MSG.setText(text);
    MSG.show();
    return;
}*/
