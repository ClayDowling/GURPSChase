#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <json/json.h>

class Serializable {

public:
    virtual void fromJson(Json::Value& parent) = 0;
    virtual Json::Value& toJson() = 0;
};

#endif // SERIALIZABLE_H

