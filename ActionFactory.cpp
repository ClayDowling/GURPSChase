#include "ActionFactory.h"

unique_ptr<ChaseAction> ActionFactory::create(QJsonObject &source) {
    unique_ptr<ChaseAction> p1(new ChaseAction);

    p1->name = source["name"].toString();
    p1->chaseBonus = source["bonus"].toInt();
    p1->canCauseWipeout = source["wipeout"].toBool();
    p1->isScaledByPenalty = source["scaled"].toBool();
    p1->pursuerAction = source["pursuer"].toBool();
    p1->quarryAction = source["quarry"].toBool();
    p1->penalty = source["penalty"].toInt();
    p1->staticManeuver = source["static"].toBool();

    return p1;
}