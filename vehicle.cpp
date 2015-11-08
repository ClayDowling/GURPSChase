#include <iostream>
#include "vehicle.h"

Vehicle::Vehicle() : maneuver(0), maxSpeed(0), name(""), skill("")
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
    (*root)["skill"] = skill;

    return *root;
}

void Vehicle::fromJson(Json::Value &parent)
{
    maxSpeed = parent["maxSpeed"].asInt();
    maneuver = parent["maneuver"].asInt();
    name = parent["name"].asString();
    skill = parent["skill"].asString();
}

string Vehicle::getName()
{
    return name;
}

void Vehicle::setName(string name)
{
    this->name = name;
}

string Vehicle::getSkill()
{
    return skill;
}

void Vehicle::setSkill(string skill)
{
    this->skill = skill;
}
