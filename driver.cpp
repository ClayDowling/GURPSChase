#include <QJsonArray>
#include "driver.h"

Driver::Driver() : name(""), dx(0), speed(0.0)
{

}

QString Driver::getName()
{
    return name;
}

void Driver::setName(QString name)
{
    this->name = name;
}

void Driver::fromJson(const QJsonObject &parent)
{
    name = parent["name"].toString();
    dx = parent["DX"].toInt();
    speed = parent["speed"].toDouble();
    QJsonArray arrskill = parent["skills"].toArray();
    for(int i=0; i < arrskill.size(); ++i) {
        Skill newSkill;
        newSkill.fromJson(arrskill[i].toObject());
        skills.push_back(newSkill);
    }

}

QJsonObject& Driver::toJson()
{
    QJsonObject *root = new QJsonObject();
    (*root)["name"] = name;
    (*root)["DX"] = dx;
    (*root)["speed"] = speed;

    QJsonArray skillsArray;
    for(auto skill : skills) {
        skillsArray.append(skill.toJson());
    }
    (*root)["skills"] = skillsArray;
    return *root;
}

int Driver::skillCount()
{
    return skills.size();
}

Skill& Driver::getSkill(int index)
{
    if (index < skills.size()) {
        return skills[index];
    } else {
        return *(new Skill());
    }
}

int Driver::getSkillLevel(QString name)
{
    for(Skill sp : skills) {
        if (sp.getName() == name) {
            return sp.getLevel();
        }
    }
    return -1;
}

void Driver::setSkill(Skill &skill)
{
    for(Skill& sp : skills) {
        if (sp.getName() == skill.getName()) {
            sp.setLevel(skill.getLevel());
            return;
        }
    }

    skills.push_back(skill);
}

int Driver::getDX()
{
    return dx;
}

void Driver::setDX(int dx)
{
    this->dx = dx;
}

double Driver::getSpeed()
{
    return speed;
}

void Driver::setSpeed(double speed)
{
    this->speed = speed;
}
