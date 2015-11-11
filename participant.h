#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "driver.h"
#include "vehicle.h"

class Participant
{
public:
    Participant();

    Driver driver;
    Vehicle vehicle;

};

#endif // PARTICIPANT_H
