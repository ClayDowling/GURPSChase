#include <sstream>
#include <gtest/gtest.h>
#include "driver.h"

class BasicDriverTest : public testing::Test
{
public:
    Driver driver;

    virtual void SetUp()
    {
        istringstream in("{\"name\": \"Speed Racer\", \"skills\": [{\"name\": \"Driving\", \"level\": 12}, {\"name\": \"Flying\", \"level\": 14}]}");
        Json::Value root;

        in >> root;
        driver.fromJson(root);
    }
};

TEST_F(BasicDriverTest, NameDefaultsToBlank)
{
    Driver localdriver;
    ASSERT_EQ("", localdriver.getName());
}

TEST_F(BasicDriverTest, CanSetName)
{
    driver.setName("A. J. Foyt");
    ASSERT_EQ("A. J. Foyt", driver.getName());
}

TEST_F(BasicDriverTest, CanReadName)
{
    ASSERT_EQ("Speed Racer", driver.getName());
}

TEST_F(BasicDriverTest, CanWriteName)
{
    Json::Value output = driver.toJson();
    ASSERT_EQ("Speed Racer", output["name"].asString());
}

TEST_F(BasicDriverTest, skillCount_whenTwoSkillsPresent_returnsTwo)
{
    ASSERT_EQ(2, driver.skillCount());
}

TEST_F(BasicDriverTest, getSkill_whenIndexIsGreaterThanSkillSize_returnsEmptySkill)
{
    ASSERT_EQ("", driver.getSkill(10).getName());
    ASSERT_EQ(0, driver.getSkill(10).getLevel());
}

TEST_F(BasicDriverTest, getSkill_whenIndexIsZero_returnsDrivingSkill)
{
    Skill driving = driver.getSkill(0);
    ASSERT_EQ("Driving", driving.getName());
    ASSERT_EQ(12, driving.getLevel());
}

TEST_F(BasicDriverTest, getSkill_whenInexIsOne_returnsFlyingSkill)
{
    Skill flying = driver.getSkill(1);
    ASSERT_EQ("Flying", flying.getName());
    ASSERT_EQ(14, flying.getLevel());
}

TEST_F(BasicDriverTest, getSkillLevel_whenSkillNameIsDriving_returnsTwelve)
{
    ASSERT_EQ(12, driver.getSkillLevel("Driving"));
}

TEST_F(BasicDriverTest, getSkillLevel_whenSkillNameIsFlying_returnsFourteen)
{
    ASSERT_EQ(14, driver.getSkillLevel("Flying"));
}

TEST_F(BasicDriverTest, CanWriteSkills)
{
    Json::Value output = driver.toJson();
    Json::Value skills = output["skills"];
    ASSERT_EQ(2, skills.size());

    Json::Value skill1 = skills[0];
    Json::Value skill2 = skills[1];

    ASSERT_EQ("Driving", skill1["name"].asString());
    ASSERT_EQ("Flying", skill2["name"].asString());

}
