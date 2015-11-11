#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <QJsonObject>

class Serializable {

public:
    virtual void fromJson(const QJsonObject& parent) = 0;
    virtual QJsonObject& toJson() = 0;
};

#endif // SERIALIZABLE_H

