#include "driver.h"

#include <iostream>

using namespace std;

Driver::Driver() : name("")
{

}

string Driver::getName()
{
    return name;
}

void Driver::setName(string name)
{
    this->name = name;
}

void Driver::fromJson(Json::Value &parent)
{
    name = parent["name"].asString();
    Json::Value arrskill = parent["skills"];
    for(int i=0; i < arrskill.size(); ++i) {
        Skill newSkill;
        newSkill.fromJson(arrskill[i]);
        skills.push_back(newSkill);
    }

}

Json::Value& Driver::toJson()
{
    Json::Value *root = new Json::Value();
    (*root)["name"] = name;
    Json::Value skillsarray;

    for(auto skill : skills) {
        (*root)["skills"].append(skill.toJson());
    }
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

int Driver::getSkillLevel(string name)
{
    for(Skill sp : skills) {
        if (sp.getName() == name) {
            return sp.getLevel();
        }
    }
    return -1;
}
