#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "serializable.h"

using namespace std;

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

    virtual string getName();

private:
    int maxSpeed;
    int maneuver;
    string name;
};

#endif // VEHICLE_H
