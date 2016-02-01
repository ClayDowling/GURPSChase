#include <tuple>
#include <gtest/gtest.h>

#include "driver.h"
#include "vehicle.h"

using namespace std;

class SpeedBonusTest : public ::testing::TestWithParam<tuple<int,int> > {

public:
    Driver driver;
    Vehicle vehicle;

};

class BonusGenerator {
public:
    static vector<tuple<int, int>> generate() {
        vector<tuple<int,int>> bonus;
        bonus.push_back(make_tuple(3,15));
        bonus.push_back(make_tuple(4,20));
        bonus.push_back(make_tuple(5,30));
        bonus.push_back(make_tuple(6,40));
        bonus.push_back(make_tuple(7,60));
        bonus.push_back(make_tuple(8,100));
        bonus.push_back(make_tuple(9,140));
        bonus.push_back(make_tuple(10,200));

        return bonus;
    }
};

TEST_P(SpeedBonusTest, withVehicle)
{
    int maxSpeed;
    int expectedBonus;

    expectedBonus = get<0>(GetParam());
    maxSpeed = get<1>(GetParam());

    driver.setVehicle(&vehicle);
    vehicle.setMaxSpeed(maxSpeed);
    ASSERT_EQ(expectedBonus, driver.getSpeedBonus());
}

INSTANTIATE_TEST_CASE_P(SpeedTest, SpeedBonusTest, testing::ValuesIn(BonusGenerator::generate()));
