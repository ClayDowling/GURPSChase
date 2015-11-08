#include <sstream>
#include <gtest/gtest.h>
#include "skill.h"

class BasicSkillTest : public testing::Test
{
public:
    Skill skill;

    virtual void SetUp()
    {
        istringstream in("{\"name\": \"Driving\", \"level\": 12}");
        Json::Value root;

        in >> root;
        skill.fromJson(root);
    }
};

TEST_F(BasicSkillTest, NameDefaultsToBlank)
{
    Skill localskill;
    ASSERT_EQ("", localskill.getName());
}

TEST_F(BasicSkillTest, CanReadName)
{
    ASSERT_EQ("Driving", skill.getName());
}

TEST_F(BasicSkillTest, CanWriteName)
{
    Json::Value output = skill.toJson();
    ASSERT_EQ("Driving", output["name"].asString());
}

TEST_F(BasicSkillTest, CanSetName)
{
    skill.setName("Flying");
    ASSERT_EQ("Flying", skill.getName());
}

TEST_F(BasicSkillTest, LevelDefaultsToZero)
{
    Skill localskill;
    ASSERT_EQ(0, localskill.getLevel());
}

TEST_F(BasicSkillTest, CanReadLevel)
{
    ASSERT_EQ(12, skill.getLevel());
}

TEST_F(BasicSkillTest, CanSetLevel)
{
    skill.setLevel(22);
    ASSERT_EQ(22, skill.getLevel());
}
