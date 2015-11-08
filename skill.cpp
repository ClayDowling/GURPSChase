#include "skill.h"

Skill::Skill() : name(""), level(0)
{

}

void Skill::fromJson(Json::Value &parent)
{
    name = parent["name"].asString();
    level = parent["level"].asInt();
}

Json::Value& Skill::toJson()
{
    Json::Value *root = new Json::Value();
    (*root)["name"] = name;
    return *root;
}

string Skill::getName()
{
    return name;
}

void Skill::setName(string name)
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
