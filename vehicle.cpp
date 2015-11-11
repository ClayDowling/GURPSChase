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

QJsonObject& Vehicle::toJson()
{
    QJsonObject *root = new QJsonObject;
    (*root)["name"] = name;
    (*root)["maxSpeed"] = maxSpeed;
    (*root)["maneuver"] = maneuver;
    (*root)["skill"] = skill;

    return *root;
}

void Vehicle::fromJson(const QJsonObject &parent)
{
    maxSpeed = parent["maxSpeed"].toInt();
    maneuver = parent["maneuver"].toInt();
    name = parent["name"].toString();
    skill = parent["skill"].toString();
}

QString Vehicle::getName()
{
    return name;
}

void Vehicle::setName(QString name)
{
    this->name = name;
}

QString Vehicle::getSkill()
{
    return skill;
}

void Vehicle::setSkill(QString skill)
{
    this->skill = skill;
}
