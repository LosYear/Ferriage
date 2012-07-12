#ifndef QRULE_H
#define QRULE_H

#include <QString>

class QRule
{
public:
    QRule(QString object1, QString object2, QString rule);
    QRule(QString object1, QString object2, QString rule, QString advanced);
private:
    // ����� ��������
    QString object1;
    QString object2;

    // �������� �������
    QString rule;

    // �������������� �������
    QString advanced;


};

#endif // QRULE_H
