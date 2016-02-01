#include <gtest/gtest.h>

#include "chaseaction.h"

class DefaultChaseAction : public ChaseAction {
public:
    virtual bool isPursuerAction() {
        return false;
    }

    virtual bool isQuarryAction() {
        return false;
    }
};

class DefaultActionTest : public testing::Test
{
public:
    DefaultChaseAction action;
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
