#include <gtest/gtest.h>

#include "chaseaction.h"

class DefaultActionTest : public testing::Test
{
public:
    ChaseAction action;
};

TEST_F(DefaultActionTest, isPursuerActionIsFalse) {
    ASSERT_FALSE(action.isPursuerAction());
}

TEST_F(DefaultActionTest, isQuarryActionIsFalse) {
    ASSERT_FALSE(action.isQuarryAction());
}

TEST_F(DefaultActionTest, canCauseWipeoutIsFalse) {
    ASSERT_FALSE(action.canCauseWipeout());
}

TEST_F(DefaultActionTest, isScaledByPenaltyIsFalse) {
    ASSERT_FALSE(action.isScaledByPenalty());
}

TEST_F(DefaultActionTest, chaseBonusIsZero) {
    ASSERT_EQ(0, action.chaseBonus());
}

TEST_F(DefaultActionTest, isStaticManeuverReturnsFalse) {
    ASSERT_FALSE(action.isStaticManeuver());
}
