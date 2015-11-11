#include "skill.h"

Skill::Skill() : name(""), level(0)
{

}

void Skill::fromJson(const QJsonObject &parent)
{
    name = parent["name"].toString();
    level = parent["level"].toInt();
}

QJsonObject &Skill::toJson()
{
    QJsonObject *root = new QJsonObject();
    (*root)["name"] = name;
    (*root)["level"] = level;
    return *root;
}

QString Skill::getName()
{
    return name;
}

void Skill::setName(QString name)
{
    this->name = name;
}

int Skill::getLevel()
{
    return level;
}

void Skill::setLevel(int level)
{
    this->level = level;
}
