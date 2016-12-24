#include "chaseaction.h"

bool ChaseAction::isPursuerAction() {
    return false;
}

bool ChaseAction::isQuarryAction() {
    return false;
}

bool ChaseAction::canCauseWipeout()
{
    return false;
}

bool ChaseAction::isScaledByPenalty()
{
    return false;
}

void ChaseAction::setPenalty(int)
{
    // Nothing doing
}

int ChaseAction::chaseBonus()
{
    return 0;
}

bool ChaseAction::isStaticManeuver()
{
    return false;
}
