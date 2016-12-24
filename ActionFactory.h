#ifndef GURPSCHASE_ACTIONFACTORY_H
#define GURPSCHASE_ACTIONFACTORY_H

#include <memory>
#include <QtCore/QJsonObject>

using namespace std;

#include "chaseaction.h"

class ActionFactory {
public:
    static unique_ptr<ChaseAction> create(QJsonObject& source);
};

#endif //GURPSCHASE_ACTIONFACTORY_H
