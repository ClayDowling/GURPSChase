#ifndef CHASEACTION_H
#define CHASEACTION_H

#include <qstring.h>

struct ChaseAction
{
    QString name;
    bool pursuerAction;
    bool quarryAction;
    bool canCauseWipeout;
    bool isScaledByPenalty;
    int penalty;
    int chaseBonus;
    bool staticManeuver;
};

#endif // CHASEACTION_H
