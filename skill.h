#ifndef SKILL_H
#define SKILL_H

#include <string>
#include "serializable.h"

using namespace std;

class Skill : public Serializable
{
public:
    Skill();

    virtual void fromJson(Json::Value &parent);
    virtual Json::Value& toJson();

    virtual string getName();
    virtual void setName(string);
    virtual int getLevel();
    virtual void setLevel(int level);

private:
    string name;
    int level;
};

#endif // SKILL_H
