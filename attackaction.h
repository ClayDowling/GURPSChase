#ifndef ATTACKACTION_H
#define ATTACKACTION_H

#include "chaseaction.h"

class AttackAction : public ChaseAction
{
public:
    virtual bool isPursuerAction();
    virtual bool isQuarryAction();
    virtual bool isStaticAction();
};

#endif // ATTACKACTION_H
