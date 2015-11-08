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

    string getName();

private:
    string name;
};

#endif // SKILL_H
