#ifndef SKILL_H
#define SKILL_H

#include <QString>
#include "serializable.h"

class Skill : public Serializable
{
public:
    Skill();

    virtual void fromJson(const QJsonObject &parent);
    virtual QJsonObject& toJson();

    virtual QString getName();
    virtual void setName(QString);
    virtual int getLevel();
    virtual void setLevel(int level);

private:
    QString name;
    int level;
};

#endif // SKILL_H
