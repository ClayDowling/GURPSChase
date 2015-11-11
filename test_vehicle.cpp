#include <QJsonDocument>
#include <gtest/gtest.h>

#include "vehicle.h"

using namespace std;

class VehicleBasicSetup : public testing::Test {
public:
    Vehicle vehicle;

    void SetUp() {
        QJsonObject root = QJsonDocument::fromJson("{\"maxSpeed\": 35, \"maneuver\": 5, \"name\": \"Test Vehicle\", \"skill\": \"Driving\" }").object();
        vehicle.fromJson(root);
    }

};

TEST_F(VehicleBasicSetup, CanReadMaxSpeed)
{
    ASSERT_EQ(35, vehicle.getMaxSpeed());
}

TEST_F(VehicleBasicSetup, CanWriteMaxSpeed)
{
    QJsonObject output = vehicle.toJson();

    ASSERT_EQ(35, output["maxSpeed"].toInt());
}

TEST_F(VehicleBasicSetup, CanReadManeuver)
{
    ASSERT_EQ(5, vehicle.getManeuver());
}

TEST_F(VehicleBasicSetup, CanWriteManeuver)
{
    QJsonObject output = vehicle.toJson();
    ASSERT_EQ(5, output["maneuver"].toInt());
}

TEST_F(VehicleBasicSetup, CanReadName)
{
    ASSERT_EQ("Test Vehicle", vehicle.getName());
}

TEST_F(VehicleBasicSetup, CanWriteName)
{
    QJsonObject output = vehicle.toJson();
    ASSERT_EQ("Test Vehicle", output["name"].toString());
}

TEST_F(VehicleBasicSetup, nameDefaultsToBlank)
{
    Vehicle localvehicle;
    ASSERT_EQ("", localvehicle.getName());
}

TEST_F(VehicleBasicSetup, setName_withSerenity_getNameReturnsSerenity)
{
    vehicle.setName("Serenity");
    ASSERT_EQ("Serenity", vehicle.getName());
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

TEST_F(VehicleBasicSetup, SkillDefaultsToBlank)
{
    Vehicle localvehicle;
    ASSERT_EQ("", localvehicle.getSkill());
}

TEST_F(VehicleBasicSetup, setSkill_whenFlying_getSkillReturnsFlying)
{
    vehicle.setSkill("Flying");
    ASSERT_EQ("Flying", vehicle.getSkill());
}

TEST_F(VehicleBasicSetup, CanReadSkill)
{
    ASSERT_EQ("Driving", vehicle.getSkill())   ;
}

TEST_F(VehicleBasicSetup, CanWriteSkill)
{
    QJsonObject output = vehicle.toJson();
    ASSERT_EQ("Driving", output["skill"].toString());
}
