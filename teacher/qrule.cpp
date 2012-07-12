#include "qrule.h"

QRule::QRule(QString object1, QString object2, QString rule)
{
    this->object1 = object1;
    this->object2 = object2;
    this->rule = rule;
    this->advanced = "";
}

QRule::QRule(QString object1, QString object2, QString rule, QString advanced)
{
    this->object1 = object1;
    this->object2 = object2;
    this->rule = rule;
    this->advanced = advanced;
}
