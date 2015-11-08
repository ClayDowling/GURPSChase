#include <iostream>
#include "vehicle.h"

Vehicle::Vehicle() : maneuver(0), maxSpeed(0), name("")
{

}

int Vehicle::getMaxSpeed()
{
    return maxSpeed;
}

void Vehicle::setMaxSpeed(int newSpeed)
{
    maxSpeed = newSpeed;
}

int Vehicle::getManeuver()
{
    return maneuver;
}

void Vehicle::setManeuver(int newManeuver)
{
    maneuver = newManeuver;
}

Json::Value& Vehicle::toJson()
{
    Json::Value *root = new Json::Value;
    (*root)["name"] = name;
    (*root)["maxSpeed"] = maxSpeed;
    (*root)["maneuver"] = maneuver;

    return *root;
}

void Vehicle::fromJson(Json::Value &parent)
{
    maxSpeed = parent["maxSpeed"].asInt();
    maneuver = parent["maneuver"].asInt();
    name = parent["name"].asString();
}

string Vehicle::getName()
{
    return name;
}
