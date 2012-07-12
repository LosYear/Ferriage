#ifndef QRULE_H
#define QRULE_H

#include <QString>

class QRule
{
public:
    QRule(QString object1, QString object2, QString rule);
    QRule(QString object1, QString object2, QString rule, QString advanced);
private:
    // Имена объектов
    QString object1;
    QString object2;

    // Основное правило
    QString rule;

    // Дополнительное правило
    QString advanced;


};

#endif // QRULE_H
