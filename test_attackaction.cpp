#include <gtest/gtest.h>
#include "attackaction.h"

class AttackActionTest : public testing::Test {
public:
    AttackAction action;
};


TEST_F(AttackActionTest, isPursurerActionReturnsTrue)
{
    ASSERT_TRUE(action.isPursuerAction());
}

TEST_F(AttackActionTest, isQuarryActionReturnsTrue)
{
    ASSERT_TRUE(action.isQuarryAction());
}

TEST_F(AttackActionTest, isStaticActionReturnsTrue)
{
    ASSERT_TRUE(action.isStaticAction());
}
