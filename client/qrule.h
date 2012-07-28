#ifndef QRULE_H
#define QRULE_H

#include <QString>

class QRule
{
public:
    QRule(QString object1, QString object2, QString rule);
    QRule(QString object1, QString object2, QString rule, QString adv_rule, QString adv_obj);

    QString getObject1();
    QString getObject2();
    QString getRule();
    QString getAdvRule();
    QString getAdvObject();
private:
    // Имена объектов
    QString object1;
    QString object2;

    // Основное правило
    QString rule;

    // Дополнительное правило
    QString adv_rule;
    QString adv_obj;


};

#endif // QRULE_H
