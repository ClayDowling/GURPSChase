#include <gtest/gtest.h>
#include "participant.h"

class ParticipantSetup : public testing::Test
{
    Participant participant;
    Driver driver;
    Vehicle vehicle;

    virtual void SetUp()
    {
        driver.setDX(12);

        vehicle.setManeuver(3);
        vehicle.setMaxSpeed(120);
    }
};
