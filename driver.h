#ifndef DRIVER_H
#define DRIVER_H

#include <QString>
#include <QVector>
#include "serializable.h"
#include "skill.h"
#include "vehicle.h"

using namespace std;

class Driver : public Serializable
{
public:
    Driver();

    virtual void fromJson(const QJsonObject& parent);
    virtual QJsonObject& toJson();

    virtual QString getName();
    virtual void setName(const QString name);

    virtual int getDX();
    virtual void setDX(int dx);

    virtual double getMove();
    virtual void setMove(int move);

    virtual int skillCount();
    virtual Skill& getSkill(int index);
    virtual int getSkillLevel(QString name);
    virtual void setSkill(Skill& skill);

    virtual Vehicle* getVehicle();
    virtual void setVehicle(Vehicle*);

    virtual int getEffectiveSkill();
    virtual int getSpeedBonus();

protected:

    virtual int getEffectiveRunningSkill();
    virtual int getEffectiveVehicleSkill();

    virtual int getSpeedBonusRunning(int);
    virtual int getSpeedBonusVehicle();

private:
    QString name;
    int dx;
    double move;
    QVector<Skill> skills;

    Vehicle *vehicle;
};

#endif // DRIVER_H
