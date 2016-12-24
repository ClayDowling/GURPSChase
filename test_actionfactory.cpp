#include <gtest/gtest.h>
#include "ActionFactory.h"

class ActionFactoryTest : public testing::Test {
public:
    QJsonObject defaultJson;
    QJsonObject aJson;

    virtual void SetUp() {
        defaultJson["name"] = "My Action";
        defaultJson["pursuer"] = true;
        defaultJson["quarry"] = false;
        defaultJson["wipeout"] = false;
        defaultJson["scaled"] = false;
        defaultJson["penalty"] = 0;
        defaultJson["bonus"] = 0;
        defaultJson["static"] = true;

        aJson["name"] = "Alternate Action";
        aJson["pursuer"] = false;
        aJson["quarry"] = true;
        aJson["wipeout"] = true;
        aJson["scaled"] = true;
        aJson["penalty"] = 7;
        aJson["bonus"] = 12;
        aJson["static"] = false;

    }
};

TEST_F(ActionFactoryTest, create_givenJsonObject_yieldsMatchingChaseAction)
{
    auto action = ActionFactory::create(defaultJson);

    ASSERT_EQ("My Action", action->name.toStdString());
    ASSERT_EQ(true, action->pursuerAction);
    ASSERT_EQ(false, action->quarryAction);
    ASSERT_EQ(false, action->canCauseWipeout);
    ASSERT_EQ(false, action->isScaledByPenalty);
    ASSERT_EQ(0, action->penalty);
    ASSERT_EQ(0, action->chaseBonus);
    ASSERT_EQ(true, action->staticManeuver);

}

TEST_F(ActionFactoryTest, create_givenAlternateJsonObject_yieldsMatchingChaseAction)
{
    auto action = ActionFactory::create(aJson);

    ASSERT_EQ("Alternate Action", action->name.toStdString());
    ASSERT_EQ(false, action->pursuerAction);
    ASSERT_EQ(true, action->quarryAction);
    ASSERT_EQ(true, action->canCauseWipeout);
    ASSERT_EQ(true, action->isScaledByPenalty);
    ASSERT_EQ(7, action->penalty);
    ASSERT_EQ(12, action->chaseBonus);
    ASSERT_EQ(false, action->staticManeuver);
}

