#ifndef VEHICLE_H
#define VEHICLE_H

#include <QString>
#include "serializable.h"

using namespace std;

class Vehicle : public Serializable
{
public:
    Vehicle();

    virtual QJsonObject& toJson();
    virtual void fromJson(const QJsonObject &parent);

    virtual int getMaxSpeed();
    virtual void setMaxSpeed(int);

    virtual int getManeuver();
    virtual void setManeuver(int);

    virtual QString getName();
    virtual void setName(QString name);

    virtual QString getSkill();
    virtual void setSkill(QString skill);

private:
    int maxSpeed;
    int maneuver;
    QString name;
    QString skill;
};

#endif // VEHICLE_H
