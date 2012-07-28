#include "qrule.h"

QRule::QRule(QString object1, QString object2, QString rule)
{
    this->object1 = object1;
    this->object2 = object2;
    this->rule = rule;
    this->adv_rule = "";
    this->adv_obj = "";
}

QRule::QRule(QString object1, QString object2, QString rule, QString adv_rule, QString adv_obj)
{
    this->object1 = object1;
    this->object2 = object2;
    this->rule = rule;
    this->adv_rule = adv_rule;
    this->adv_obj = adv_obj;
}

QString QRule::getObject1()
{
    return this->object1;
}


QString QRule::getAdvObject()
{
    return this->adv_obj;
}


QString QRule::getAdvRule()
{
    return this->adv_rule;
}


QString QRule::getRule()
{
    return this->rule;
}


QString QRule::getObject2()
{
    return this->object2;
}
