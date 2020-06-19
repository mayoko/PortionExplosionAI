#include "../src/state/MarbleColor.hpp"
#include "../src/action/ActionCreator.hpp"
#include "TestUtil.hpp"
#include "gtest/gtest.h"

TEST(MoveTest, professorHelp) {
    State state = getDefaultState();
    Action action = ActionCreator::createProfessorHelpAction(2, 1);
    state.move(action);
    EXPECT_EQ(MarbleColor::NONE, state.getMarbleStorage().get(4, 1));
}
