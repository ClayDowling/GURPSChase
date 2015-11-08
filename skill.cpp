#include "skill.h"

Skill::Skill() : name("")
{

}

void Skill::fromJson(Json::Value &parent)
{
    name = parent["name"].asString();
}

Json::Value& Skill::toJson()
{
    Json::Value *root = new Json::Value();
    return *root;
}

string Skill::getName()
{
    return name;
}
