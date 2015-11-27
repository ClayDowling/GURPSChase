#include <gtest/gtest.h>
#include "vehicle.h"
#include "driver.h"
#include "skill.h"

class DriverVehicleTest : public testing::Test {

public:
    Driver driver;
    Vehicle vehicle;
    Skill motorcycleSkill;
    Skill runningSkill;
    Skill carSkill;

    const QString DRIVING_MOTORCYCLE = "Driving (Motorcycle)";
    const QString DRIVING_CAR = "Driving (Automobile)";
    const QString RUNNING = "Running";

    DriverVehicleTest() {

        motorcycleSkill.setName(DRIVING_MOTORCYCLE);
        motorcycleSkill.setLevel(14);

        runningSkill.setName(RUNNING);
        runningSkill.setLevel(12);

        carSkill.setName(DRIVING_CAR);
        carSkill.setLevel(13);

        driver.setMove(6);
        driver.setDX(10);

        vehicle.setManeuver(7);
        vehicle.setMaxSpeed(130);
        vehicle.setSkill(DRIVING_MOTORCYCLE);
    }

};

TEST_F(DriverVehicleTest, getVehicle_afterSetVehicle_returnsVehicle)
{
    driver.setVehicle(&vehicle);
    ASSERT_EQ(driver.getVehicle(), &vehicle);
}

TEST_F(DriverVehicleTest, getVehicle_withoutVehicleSet_returnsNull)
{
    ASSERT_FALSE(driver.getVehicle());
}

TEST_F(DriverVehicleTest, getMove_withoutVehicle_returnsDriverSpeed)
{
    ASSERT_EQ(6, driver.getMove());
}

TEST_F(DriverVehicleTest, getMove_withVehicle_returnsVehicleSpeed)
{
    driver.setVehicle(&vehicle);
    ASSERT_EQ(130, driver.getMove());
}

TEST_F(DriverVehicleTest, getEffectiveSkill_withoutSkillOrVehicle_returnsDx)
{
    // This is somebody running, but without running skill
    ASSERT_EQ(10, driver.getEffectiveSkill());
}

TEST_F(DriverVehicleTest, getEffectiveSkill_withRunningAndNoVehicle_returnsSkillLevel)
{
    driver.setSkill(runningSkill);
    ASSERT_EQ(12, driver.getEffectiveSkill());
}

TEST_F(DriverVehicleTest, getEffectiveSkill_withVehicleButNotSkill_returnsDxMinusFive)
{
    driver.setVehicle(&vehicle);
    ASSERT_EQ(5, driver.getEffectiveSkill());
}

TEST_F(DriverVehicleTest, getEffectiveSkill_withVehicleAndSkill_returnsSkill)
{
    driver.setVehicle(&vehicle);
    driver.setSkill(motorcycleSkill);
    ASSERT_EQ(14, driver.getEffectiveSkill());
}

TEST_F(DriverVehicleTest, getSpeedBonus_withoutVehicleAndSpeedFour_returnsZero)
{
    driver.setMove(4);
    ASSERT_EQ(0, driver.getSpeedBonus());
}

TEST_F(DriverVehicleTest, getSpeedBonus_withoutVehicleAndSpeedFive_returnsTwo)
{
    driver.setMove(5);
    ASSERT_EQ(2, driver.getSpeedBonus());
}

TEST_F(DriverVehicleTest, getSpeedBonus_withoutVehicleAndSpeedSix_returnsThree)
{
    driver.setMove(6);
    ASSERT_EQ(3, driver.getSpeedBonus());
}

TEST_F(DriverVehicleTest, getSpeedBonus_withVehicleAndSpeedFifteen_returnsThree)
{
    driver.setVehicle(&vehicle);
    vehicle.setMaxSpeed(15);
    ASSERT_EQ(3, driver.getSpeedBonus());
}

TEST_F(DriverVehicleTest, getSpeedBonus_withVehicleAndSpeedTwenty_returnsFour)
{
    driver.setVehicle(&vehicle);
    vehicle.setMaxSpeed(20);
    ASSERT_EQ(4, driver.getSpeedBonus());
}

TEST_F(DriverVehicleTest, getSpeedBonus_withVehicleAndSpeedThirty_returnsFive)
{
    driver.setVehicle(&vehicle);
    vehicle.setMaxSpeed(30);
    ASSERT_EQ(5, driver.getSpeedBonus());
}
