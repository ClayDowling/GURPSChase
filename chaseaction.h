#ifndef CHASEACTION_H
#define CHASEACTION_H


class ChaseAction
{
public:

    virtual bool isPursuerAction() = 0;
    virtual bool isQuarryAction() = 0;
    virtual bool canCauseWipeout();
    virtual bool isScaledByPenalty();
    virtual void setPenalty(int);
    virtual int chaseBonus();
    virtual bool isStaticManeuver();

};

#endif // CHASEACTION_H
