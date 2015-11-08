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

