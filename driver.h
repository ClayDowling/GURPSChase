#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <vector>
#include "serializable.h"
#include "skill.h"

using namespace std;

class Driver : public Serializable
{
public:
    Driver();

    virtual void fromJson(Json::Value& parent);
    virtual Json::Value& toJson();

    virtual string getName();
    virtual void setName(string name);

    virtual int getDX();
    virtual void setDX(int dx);

    virtual int skillCount();
    virtual Skill& getSkill(int index);
    virtual int getSkillLevel(string name);

private:
    string name;
    int dx;
    vector<Skill> skills;
};

#endif // DRIVER_H
