#ifndef DRIVER_H
#define DRIVER_H

#include <QString>
#include <QVector>
#include "serializable.h"
#include "skill.h"

using namespace std;

class Driver : public Serializable
{
public:
    Driver();

    virtual void fromJson(const QJsonObject& parent);
    virtual QJsonObject& toJson();

    virtual QString getName();
    virtual void setName(QString name);

    virtual int getDX();
    virtual void setDX(int dx);

    virtual int skillCount();
    virtual Skill& getSkill(int index);
    virtual int getSkillLevel(QString name);
    virtual void setSkill(Skill& skill);

private:
    QString name;
    int dx;
    QVector<Skill> skills;
};

#endif // DRIVER_H
