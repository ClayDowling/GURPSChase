#include <gtest/gtest.h>
#include <sstream>

#include "vehicle.h"

using namespace std;

class VehicleBasicSetup : public testing::Test {
public:
    Vehicle vehicle;

    void SetUp() {
        istringstream in("{\"maxSpeed\": 35, \"maneuver\": 5 }");

        Json::Value root;
        in >> root;

        vehicle.fromJson(root);
    }

};

TEST_F(VehicleBasicSetup, CanReadMaxSpeed)
{
    ASSERT_EQ(35, vehicle.getMaxSpeed());
}

TEST_F(VehicleBasicSetup, CanWriteMaxSpeed)
{
    Json::Value output = vehicle.toJson();

    ASSERT_EQ(35, output["maxSpeed"].asInt());
}

TEST_F(VehicleBasicSetup, CanReadManeuver)
{
    ASSERT_EQ(5, vehicle.getManeuver());
}

TEST_F(VehicleBasicSetup, CanWriteManeuver)
{
    Json::Value output = vehicle.toJson();
    ASSERT_EQ(5, output["maneuver"].asInt());
}

TEST_F(VehicleBasicSetup, CanSetMaxSpeed)
{
    vehicle.setMaxSpeed(27);
    ASSERT_EQ(27, vehicle.getMaxSpeed());
}

TEST_F(VehicleBasicSetup, CanSetManeuver)
{
    vehicle.setManeuver(76);
    ASSERT_EQ(76, vehicle.getManeuver());
}

TEST_F(VehicleBasicSetup, maneuverDefaultsToZero)
{
    Vehicle localvehicle;
    ASSERT_EQ(0, localvehicle.getManeuver());
}

TEST_F(VehicleBasicSetup, maxSpeedDefaultsToZero)
{
    Vehicle localvehicle;
    ASSERT_EQ(0, localvehicle.getMaxSpeed());
}
