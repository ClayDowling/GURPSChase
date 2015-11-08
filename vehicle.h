#ifndef VEHICLE_H
#define VEHICLE_H

#include "serializable.h"

class Vehicle : public Serializable
{
public:
    Vehicle();

    virtual Json::Value& toJson();
    virtual void fromJson(Json::Value &parent);

    virtual int getMaxSpeed();
    virtual void setMaxSpeed(int);

    virtual int getManeuver();
    virtual void setManeuver(int);

private:
    int maxSpeed;
    int maneuver;
};

#endif // VEHICLE_H
