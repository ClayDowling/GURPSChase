#include <QJsonDocument>
#include <QJsonArray>

#include <gtest/gtest.h>
#include "driver.h"

class BasicDriverTest : public testing::Test
{
public:
    Driver driver;

    virtual void SetUp()
    {
        QJsonObject root = QJsonDocument::fromJson("{\"name\": \"Speed Racer\", \"DX\": 12, \"move\": 5, \"skills\": [{\"name\": \"Driving\", \"level\": 12}, {\"name\": \"Flying\", \"level\": 14}]}").object();
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
    QJsonObject output = driver.toJson();
    ASSERT_EQ("Speed Racer", output["name"].toString());
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

TEST_F(BasicDriverTest, setSkill_whenBoatingAndTwoExistingSkills_getSkillCountReturns3)
{
    EXPECT_EQ(2, driver.skillCount());
    Skill newskill;
    newskill.setName("Boating");
    newskill.setLevel(8);
    driver.setSkill(newskill);

    ASSERT_EQ(3, driver.skillCount());
}

TEST_F(BasicDriverTest, setSkill_whenDrivingOfSevenAndExistingDrivingIsTwelve_getSkillLevelDrivingReturnsSeven)
{
    EXPECT_EQ(2, driver.skillCount());
    EXPECT_EQ(12, driver.getSkillLevel("Driving"));
    Skill newskill;
    newskill.setName("Driving");
    newskill.setLevel(7);
    driver.setSkill(newskill);

    ASSERT_EQ(2, driver.skillCount());
    ASSERT_EQ(7, driver.getSkillLevel("Driving"));
}

TEST_F(BasicDriverTest, CanWriteSkills)
{
    QJsonObject output = driver.toJson();
    QJsonArray skills = output["skills"].toArray();
    ASSERT_EQ(2, skills.size());

    QJsonObject skill1 = skills[0].toObject();
    QJsonObject skill2 = skills[1].toObject();

    ASSERT_EQ("Driving", skill1["name"].toString());
    ASSERT_EQ("Flying", skill2["name"].toString());

}

TEST_F(BasicDriverTest, DxDefaultsToZero)
{
    Driver localDriver;
    ASSERT_EQ(0, localDriver.getDX());
}

TEST_F(BasicDriverTest, CanSetDX)
{
    driver.setDX(14);
    ASSERT_EQ(14, driver.getDX());
}

TEST_F(BasicDriverTest, CanReadDX)
{
    ASSERT_EQ(12, driver.getDX());
}

TEST_F(BasicDriverTest, CanWriteDX)
{
    QJsonObject output = driver.toJson();
    ASSERT_EQ(12, output["DX"].toInt());
}

TEST_F(BasicDriverTest, moveDefaultsToZero)
{
    Driver localDriver;
    ASSERT_EQ(0, localDriver.getMove());
}

TEST_F(BasicDriverTest, setmove_whenPassedSix_getMoveReturnsSix)
{
    driver.setMove(6);
    ASSERT_EQ(6, driver.getMove());
}

TEST_F(BasicDriverTest, CanReadMove)
{
    ASSERT_EQ(5, driver.getMove());
}

TEST_F(BasicDriverTest, CanWriteMove)
{
    QJsonObject output = driver.toJson();
    ASSERT_EQ(5, output["move"].toInt());
}
