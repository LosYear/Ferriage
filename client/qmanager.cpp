#include "QMessageBox.h"
#include "qfile.h"
#include "QTextStream"
#include "qmanager.h"
#include <QJson/Parser>
#include <QVariantMap>
QManager::QManager(QWidget *parent)
{
    this->objects = 0;
    this->raft = 0;
    this->sprites = 0;
    this->active = 0;

    this->setParent(parent);

    this->steps = 0;
}

void QManager::loadObjects(QString dir, QLabel* image)
{
    // �������� ��������
    this->loadImages(dir, image);
//    �������� ������
    this->loadRules(dir);
}

void QManager::spriteClicked(int n)
{
    this->setActive(n);
}
void QManager::raftClicked()
{
    this->setActive(-1);
}

void QManager::setSprites(int spritesNumber)
{
    this->sprites = spritesNumber;
}

int QManager::getSprites()
{
    return this->sprites;
}

void QManager::setParent(QWidget *parent)
{
    this->parent = parent;
}

void QManager::loadImages(QString dir, QLabel* image)
{
    QJson::Parser parser;

    // ��������� ���� ����
    QFile fInfo( dir + "/info" );
    if (!fInfo.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox* errMSG = new QMessageBox;
        errMSG->setText(QString::fromLocal8Bit("#0003 ������ ��� ������ �����"));
        errMSG->show();
        return;
    }

    QVariantMap info =  parser.parse(&fInfo).toMap();

    this->setSprites(info["sprites_number"].toInt());

    QVariantMap jSprites = info["sprites"].toMap();

    this->setMaxActive(info["maxActive"].toInt());

    // ��������� �������� ��������
    QPixmap** pixmaps;

    this->objects = new QSprite*[this->getSprites()];
    pixmaps = new QPixmap*[this->getSprites()];

    for ( int i = 0; i<sprites; i++){
        QString name = jSprites[QString::number(i)].toString();

        QString path = dir+"/"+name;
        pixmaps[i] = new QPixmap(path);
        this->objects[i] = new QSprite("", this->parent);
        this->objects[i]->setPixmap(*pixmaps[i]);
        this->objects[i]->setGeometry(50, 100*i+150, pixmaps[i]->width(),
                                pixmaps[i]->height());
        this->objects[i]->adjustSize();
        this->objects[i]->setNumber(i);
        //
       this->objects[i]->raise();
        //
        this->objects[i]->show();
        this->objects[i]->setOldX(this->objects[i]->x());
        this->objects[i]->setOldY(this->objects[i]->y());

        // ������ ����������, �����, ...
        this->objects[i]->setSide(0);
        this->objects[i]->setActive(0);

        // ��������� �����
        connect(this->objects[i], SIGNAL(clicked(int)), this, SLOT(spriteClicked(int)));
    }

    //this->setActive(0);

    // �������� ����
    QString bg = info["background"].toString();
    QPixmap* pix = new QPixmap(dir+"/"+bg);
    *pix = pix->scaled(800,600);
    image->setPixmap(*pix);
    image->adjustSize();

    // �������� �����
    QString rft = info["raft"].toString();
    this->raft = new QRaft("", this->parent);
    QPixmap* raftPix = new QPixmap(dir+"/"+rft);
    this->raft->setPixmap(*raftPix);
    this->raft->move(150,objects[this->sprites-1]->y() + 100);
    this->raft->setSide(0);
    this->raft->show();

    this->raft->setMovable(info["isMovable"].toBool());
    this->raft->setObserver(info["isMovable"].toBool());

    connect(this->raft, SIGNAL(clicked()), this, SLOT(raftClicked()));

    // ��������� ������
    fInfo.flush();
    fInfo.close();

    this->task = info["task"].toString();

    QMessageBox msg;
    msg.setText(info["task"].toString());
    msg.exec();

}

void QManager::loadRules(QString dir)
{
    // �������� ������
    QFile fRules( dir + "/rules" );
    if (!fRules.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox* errMSG = new QMessageBox;
        errMSG->setText(QString::fromLocal8Bit("#0003 ������ ��� ������ �����"));
        errMSG->show();
        return;
    }

    QTextStream tsRules(&fRules);

    this->rules.resize(sprites);
    for ( int i = 0; i < sprites; i++){
        this->rules[i].resize(sprites);
        for ( int j = 0; j < sprites ; j++){
            int tmp = 0;
            tsRules>>tmp;
            this->rules[i][j] = tmp;
        }
    }
}

void QManager::setActive(int n)
{
    if (this->getActiveCount() < this->maxActive || n == -1 || (n >= 0 && this->objects[n]->getActive())){
        // ���� ����������� ��������� ���������
        if (n >= 0){
            if ( this->objects[n]->getSide() == this->raft->getSide())
            {
                // ��������� �������� ������
                this->objects[n]->setActive(true);
                this->objects[n]->setOldX(this->objects[n]->x());
                this->objects[n]->setOldY(this->objects[n]->y());

                this->objects[n]->setGeometry( this->raft->x() + 30,
                                               this->raft->y() + 5,
                                               this->objects[n]->width(),
                                               this->objects[n]->height());
                // ���� ������� ��������
                if ( this->raft->getActive()){
                    this->raft->setActive(false);
                }
            }
        }
        else
        {
            // ��������� ��������� ��������
            if (this->raft->getMovable()){
                for ( int i = 0; i < this->sprites; i++){
                    if ( this->objects[i]->getActive() ){
                        this->objects[i]->setActive(false);

                        this->objects[i]->setGeometry( this->objects[i]->getOldX(),
                                                       this->objects[i]->getOldY(),
                                                       this->objects[i]->width(),
                                                       this->objects[i]->height());
                    }
                }
                this->raft->setActive(true);
            }
        }
    }
    else
    {
        // ������� ����� �������� �������
        /* @TODO:
          * ��������� ��� �� ��� �����������
        */
    }
}

int QManager::getActive()
{
    return this->active;
}

bool QManager::changeSide(int side)
{
    if( this->getActiveCount() < 1 && this->raft->getActive() == false){
        QMessageBox msg;
        msg.setText(QString::fromLocal8Bit("�������� ���� �� ���� �������� ������"));
        msg.exec();

        return true;
    }

    if ( side == 0 ){
        // �� ����� �������
        if ( this->raft->getMovable()){
            // ���� ��� ��������
            if ( this->raft->getObserver()){
                // ���� �����������
                if ( this->raft->getActive()){
                    for ( int i = 0; i < this->sprites; i++){
                        for ( int j = 0; j < this->sprites; j++){
                            if( this->objects[i]->getSide() == 1 && this->objects[j]->getSide() == 1){
                                if (this->rules[i][j] == 0){
                                    return false;
                                }
                            }
                        }
                    }
                    // �������

                    this->raft->setSide(0);
                    this->raft->move( this->raft->x() - 400,  this->raft->y());
                    this->steps++;

                    list.push_back(QString::fromLocal8Bit("<-- ����"));

                    return true;
                }
                else{
                // ��������� �����, �� �������� ���������
                    for ( int i =0; i < this->sprites; i++){
                        for ( int j = 0; j < this->sprites; j++){
                            if (this->objects[i]->getSide() == 1 && this->objects[j]->getSide() == 1){
                                if ( this->objects[i]->getActive() == false && this->objects[j]->getActive() == false){
                                    if ( this->rules[i][j] == 0){
                                        return false;
                                    }
                                }
                            }
                        }
                    }
                    // �������
                    QString bracket = "";

                    for ( int i = 0; i < this->sprites; i++){
                        if ( this->objects[i]->getActive()){
                            this->objects[i]->setSide(0);
                            this->objects[i]->move(this->objects[i]->x() - 500,
                                                  this->objects[i]->getOldY());
                            this->objects[i]->setOldX(this->objects[i]->x());
                            this->objects[i]->setOldY(this->objects[i]->y());
                            this->objects[i]->setActive(false);
                            bracket += QString::number(i) + " ";
                        }
                    }

                    this->raft->setSide(0);
                    this->raft->move(this->raft->x() - 400, this->raft->y());
                    this->steps++;

                    this->list.push_back(QString::fromLocal8Bit("<-- ������(�) { ") + bracket+"}");

                    return true;

                }
            }
            else{
                // ���� �� �����������
                // ��������� �����, �� �������� ���������
                for ( int i =0; i < this->sprites; i++){
                    for ( int j = 0; j < this->sprites; j++){
                        if (this->objects[i]->getSide() == 1 && this->objects[j]->getSide() == 1){
                            if ( this->objects[i]->getActive() == false && this->objects[j]->getActive() == false){
                                if ( this->rules[i][j] == 0){
                                    return false;
                                }
                            }
                        }
                    }
                }

                // ��������� �����, � �������� ������������
                for ( int i = 0; i < this->sprites; i++ ){
                    for ( int j = 0; j < this->sprites; j++){
                        if ( (this->objects[i]->getSide() == 0 && this->objects[j]->getSide() == 0)
                             || this->objects[i]->getActive() || this->objects[j]->getActive() ){
                            if ( this->rules[i][j] == 0){
                                return false;
                            }
                        }
                    }
                }
                // �������

                QString bracket = "";

                for ( int i = 0; i < this->sprites; i++){
                    if ( this->objects[i]->getActive()){
                        this->objects[i]->setSide(0);
                        this->objects[i]->move(this->objects[i]->x() - 500,
                                              this->objects[i]->getOldY());
                        this->objects[i]->setOldX(this->objects[i]->x());
                        this->objects[i]->setOldY(this->objects[i]->y());
                        this->objects[i]->setActive(false);
                        bracket += QString::number(i) + " ";
                    }
                }

                this->raft->setSide(0);
                this->raft->move(this->raft->x() - 400, this->raft->y());
                this->steps++;

                this->list.push_back(QString::fromLocal8Bit("<-- ������(�) { ") + bracket+"}");

                return true;
            }
        }
        else {
            // ���� �� ����� ��� ��������
            // ��������� �����, �� �������� ���������
            for ( int i =0; i < this->sprites; i++){
                for ( int j = 0; j < this->sprites; j++){
                    if (this->objects[i]->getSide() == 1 && this->objects[j]->getSide() == 1){
                        if ( this->objects[i]->getActive() == false && this->objects[j]->getActive() == false){
                            if ( this->rules[i][j] == 0){
                                return false;
                            }
                        }
                    }
                }
            }

            // ��������� �����, � �������� ������������
            for ( int i = 0; i < this->sprites; i++ ){
                for ( int j = 0; j < this->sprites; j++){
                    if ( (this->objects[i]->getSide() == 0 && this->objects[j]->getSide() == 0)
                         || this->objects[i]->getActive() || this->objects[j]->getActive() ){
                        if ( this->rules[i][j] == 0){
                            return false;
                        }
                    }
                }
            }
            // �������

            QString bracket = "";

            for ( int i = 0; i < this->sprites; i++){
                if ( this->objects[i]->getActive()){
                    this->objects[i]->setSide(0);
                    this->objects[i]->move(this->objects[i]->x() - 500,
                                          this->objects[i]->getOldY());
                    this->objects[i]->setOldX(this->objects[i]->x());
                    this->objects[i]->setOldY(this->objects[i]->y());
                    this->objects[i]->setActive(false);
                    bracket += QString::number(i) + " ";
                }
            }

            this->raft->setSide(0);
            this->raft->move(this->raft->x() - 400, this->raft->y());
            this->steps++;
            this->list.push_back(QString::fromLocal8Bit("<-- ������(�) { ") + bracket+"}");

            return true;

        }
    }
    else {
        // �� ������
        if ( this->raft->getMovable()){
            // ���� ��� ��������
            if ( this->raft->getObserver()){
                // ���� �����������
                if ( this->raft->getActive()){
                    for ( int i = 0; i < this->sprites; i++){
                        for ( int j = 0; j < this->sprites; j++){
                            if( this->objects[i]->getSide() == 0 && this->objects[j]->getSide() == 0){
                                if (this->rules[i][j] == 0){
                                    return false;
                                }
                            }
                        }
                    }
                    // �������

                    this->raft->setSide(1);
                    this->raft->move( this->raft->x() + 400,  this->raft->y());
                    this->steps++;

                    list.push_back(QString::fromLocal8Bit("���� -->"));

                    return true;
                }
                else{
                // ��������� �����, �� �������� ���������
                    for ( int i =0; i < this->sprites; i++){
                        for ( int j = 0; j < this->sprites; j++){
                            if (this->objects[i]->getSide() == 0 && this->objects[j]->getSide() == 0){
                                if ( this->objects[i]->getActive() == false && this->objects[j]->getActive() == false){
                                    if ( this->rules[i][j] == 0){
                                        return false;
                                    }
                                }
                            }
                        }
                    }
                    // �������

                    QString bracket = "";

                    for ( int i = 0; i < this->sprites; i++){
                        if ( this->objects[i]->getActive()){
                            this->objects[i]->setSide(1);
                            this->objects[i]->move(this->objects[i]->x() + 500,
                                                  this->objects[i]->getOldY());
                            this->objects[i]->setOldX(this->objects[i]->x());
                            this->objects[i]->setOldY(this->objects[i]->y());
                            this->objects[i]->setActive(false);
                            bracket += QString::number(i) + " ";
                        }
                    }

                    this->raft->setSide(1);
                    this->raft->move(this->raft->x() + 400, this->raft->y());
                    this->steps++;

                    this->list.push_back(QString::fromLocal8Bit("������(�) { ") + bracket + "} -->");

                    return true;

                }
            }
            else{
                // ���� �� �����������
                // ��������� �����, �� �������� ���������
                for ( int i =0; i < this->sprites; i++){
                    for ( int j = 0; j < this->sprites; j++){
                        if (this->objects[i]->getSide() == 0 && this->objects[j]->getSide() == 0){
                            if ( !this->objects[i]->getActive() && !this->objects[j]->getActive()){
                                if ( this->rules[i][j] == 0){
                                    return false;
                                }
                            }
                        }
                    }
                }

                // ��������� �����, � �������� ������������
                for ( int i = 0; i < this->sprites; i++ ){
                    for ( int j = 0; j < this->sprites; j++){
                        if ( (this->objects[i]->getSide() == 1 && this->objects[j]->getSide() == 1)
                             || this->objects[i]->getActive() || this->objects[j]->getActive() ){
                            if ( this->rules[i][j] == 0){
                                return false;
                            }
                        }
                    }
                }
                // �������

                QString bracket = "";

                for ( int i = 0; i < this->sprites; i++){
                    if ( this->objects[i]->getActive()){
                        this->objects[i]->setSide(0);
                        this->objects[i]->move(this->objects[i]->x() + 500,
                                              this->objects[i]->getOldY());
                        this->objects[i]->setOldX(this->objects[i]->x());
                        this->objects[i]->setOldY(this->objects[i]->y());
                        this->objects[i]->setActive(false);
                        bracket += QString::number(i) + " ";
                    }
                }

                this->raft->setSide(0);
                this->raft->move(this->raft->x() + 400, this->raft->y());
                this->steps++;
                this->list.push_back(QString::fromLocal8Bit("������(�) { ") + bracket + "} -->");

                return true;
            }
        }
        else {
            // ���� �� ����� ��� ��������
            // ��������� �����, �� �������� ���������
            for ( int i =0; i < this->sprites; i++){
                for ( int j = 0; j < this->sprites; j++){
                    if (this->objects[i]->getSide() == 0 && this->objects[j]->getSide() == 0){
                        if ( !this->objects[i]->getActive() && !this->objects[j]->getActive()){
                            if ( this->rules[i][j] == 0){
                                return false;
                            }
                        }
                    }
                }
            }

            // ��������� �����, � �������� ������������
            for ( int i = 0; i < this->sprites; i++ ){
                for ( int j = 0; j < this->sprites; j++){
                    if ( (this->objects[i]->getSide() == 1 && this->objects[j]->getSide() == 1)
                         || this->objects[i]->getActive() || this->objects[j]->getActive() ){
                        if ( this->rules[i][j] == 0){
                            return false;
                        }
                    }
                }
            }
            // �������

            QString bracket = "";

            for ( int i = 0; i < this->sprites; i++){
                if ( this->objects[i]->getActive()){
                    this->objects[i]->setSide(0);
                    this->objects[i]->move(this->objects[i]->x() + 500,
                                          this->objects[i]->getOldY());
                    this->objects[i]->setOldX(this->objects[i]->x());
                    this->objects[i]->setOldY(this->objects[i]->y());
                    this->objects[i]->setActive(false);
                    bracket += QString::number(i) + " ";
                }
            }

            this->raft->setSide(0);
            this->raft->move(this->raft->x() + 400, this->raft->y());
            this->steps++;

            this->list.push_back(QString::fromLocal8Bit("������(�) { ") + bracket + "} -->");

            return true;

        }
    }
}

void QManager::setMaxActive(int active)
{
    this->maxActive = active;
}

int QManager::getActiveCount()
{
    int result = 0;
    for ( int i = 0; i < this->sprites; i++){
        if (this->objects[i]->getActive()){
            result++;
        }
    }
    return result;
}

int QManager::getSteps()
{
    return this->steps;
}

QStringList QManager::getList()
{
    return this->list;
}

