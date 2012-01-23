#ifndef LDIR_H
#define LDIR_H
#include "qdir.h"
#include "edits.h"

class lDir
{
private:
    Edits* pEdits;
public:
    lDir(Edits* gEdits);
    int delDir(QDir* dir);
    void createTmpDir();
    void cpyFiles(QString background);

};

#endif // LDIR_H
