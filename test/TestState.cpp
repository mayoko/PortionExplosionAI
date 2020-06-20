#include "../src/state/MarbleColor.hpp"
#include "../src/action/ActionCreator.hpp"
#include "TestUtil.hpp"
#include "gtest/gtest.h"

TEST(MoveTest, professorHelp) {
    State state = getDefaultState();
    Action action = ActionCreator::createProfessorHelpAction(2, 1);
    state.move(action);
    EXPECT_EQ(MarbleColor::NONE, state.getMarbleStorage().get(4, 1));
    EXPECT_EQ(1, state.getMarblePosession(MarbleColor::YELLOW));
    EXPECT_EQ(0, state.getMarblePosession(MarbleColor::BLACK));
}

TEST(MoveTest, pickMarble) {
    State state = getDefaultState();
    // assume that the explosion will happen
    Action action = ActionCreator::createPickMarbleAction(3, 1);
    state.move(action);
    for (int y = 2; y < 5; y++) {
        EXPECT_EQ(MarbleColor::NONE, state.getMarbleStorage().get(y, 1));
    }
    EXPECT_EQ(2, state.getMarblePosession(MarbleColor::YELLOW));
    EXPECT_EQ(1, state.getMarblePosession(MarbleColor::BLACK));
    EXPECT_EQ(0, state.getMarblePosession(MarbleColor::RED));
}