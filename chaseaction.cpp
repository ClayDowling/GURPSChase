#include "chaseaction.h"

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
