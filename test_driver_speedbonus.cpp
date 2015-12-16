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
    static vector<tuple<int, int>> generate() {
        vector<tuple<int,int>> bonus;
        bonus.push_back(make_tuple(2,20));
        bonus.push_back(make_tuple(3,30));

        return bonus;
    }
};

TEST_P(SpeedBonusTest, withVehicle)
{
    int maxSpeed;
    int expectedBonus;

    maxSpeed = get<0>(GetParam());
    expectedBonus = get<1>(GetParam());

    driver.setVehicle(&vehicle);
    vehicle.setMaxSpeed(maxSpeed);
    ASSERT_EQ(expectedBonus, driver.getSpeedBonus());
}

INSTANTIATE_TEST_CASE_P(SpeedTest, SpeedBonusTest, testing::ValuesIn(BonusGenerator::generate()));
