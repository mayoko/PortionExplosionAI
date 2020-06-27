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
    EXPECT_EQ(true, state.isAskedProfessorHelp());
}

TEST(isValidTest, professorHelp) {
    State state = getDefaultState();
    Action action = ActionCreator::createProfessorHelpAction(5, 1);
    EXPECT_EQ(false, state.isValidMove(action));
    action = ActionCreator::createProfessorHelpAction(2, 1);
    EXPECT_EQ(true, state.isValidMove(action));
    state.setAskedProfessorHelp(true);
    EXPECT_EQ(false, state.isValidMove(action));
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
    EXPECT_EQ(true, state.isPickedMarble());
}

TEST(isValidTest, pickMarble) {
    State state = getDefaultState();
    // assume that the explosion will happen
    Action action = ActionCreator::createProfessorHelpAction(5, 1);
    EXPECT_EQ(false, state.isValidMove(action));
    action = ActionCreator::createPickMarbleAction(3, 1);
    EXPECT_EQ(true, state.isValidMove(action));
    state.setPickedMarble(true);
    EXPECT_EQ(false, state.isValidMove(action));
}

TEST(rewindTimePortion, validMove) {
    State state = getDefaultState();
    const PortionType targetPortionType = PortionType::FALL_IN_LOVE;
    std::map<PortionType, int> usedPortions;
    usedPortions[targetPortionType] = 1;
    state.setUsedPortions(usedPortions);
    Action action = ActionCreator::createRewindTimePortionAction(targetPortionType);
    state.move(action);
    EXPECT_EQ(1, state.getAvailablePortion(targetPortionType));
    EXPECT_EQ(0, state.getUsedPortion(targetPortionType));
}

TEST(rewindTimePortion, invalidMove) {
    State state = getDefaultState();
    const PortionType targetPortionType = PortionType::FALL_IN_LOVE;
    std::map<PortionType, int> usedPortions;
    state.setUsedPortions(usedPortions);
    Action action = ActionCreator::createRewindTimePortionAction(targetPortionType);
    state.move(action);
    EXPECT_EQ(0, state.getAvailablePortion(targetPortionType));
    EXPECT_EQ(0, state.getUsedPortion(targetPortionType));
}

TEST(isValidTest, rewindTimePortionValid) {
    State state = getDefaultState();
    const PortionType targetPortionType = PortionType::FALL_IN_LOVE;
    std::map<PortionType, int> usedPortions;
    usedPortions[targetPortionType] = 1;
    state.setUsedPortions(usedPortions);
    std::map<PortionType, int> availablePortions;
    availablePortions[PortionType::REWIND_TIME] = 1;
    state.setAvailablePortions(availablePortions);
    Action action = ActionCreator::createRewindTimePortionAction(targetPortionType);
    EXPECT_EQ(true, state.isValidMove(action));
    availablePortions[PortionType::REWIND_TIME] = 0;
    state.setAvailablePortions(availablePortions);
    EXPECT_EQ(false, state.isValidMove(action));
}

TEST(isValidTest, rewindTimePortionInvalid) {
    State state = getDefaultState();
    std::map<PortionType, int> availablePortions;
    availablePortions[PortionType::REWIND_TIME] = 1;
    state.setAvailablePortions(availablePortions);
    const PortionType targetPortionType = PortionType::FALL_IN_LOVE;
    std::map<PortionType, int> usedPortions;
    state.setUsedPortions(usedPortions);
    Action action = ActionCreator::createRewindTimePortionAction(targetPortionType);
    EXPECT_EQ(false, state.isValidMove(action));
}

TEST(isValidTest, rewindTimePortionWithRewindPortion) {
    State state = getDefaultState();
    std::map<PortionType, int> availablePortions;
    availablePortions[PortionType::REWIND_TIME] = 1;
    state.setAvailablePortions(availablePortions);
    const PortionType targetPortionType = PortionType::REWIND_TIME;
    std::map<PortionType, int> usedPortions;
    state.setUsedPortions(usedPortions);
    Action action = ActionCreator::createRewindTimePortionAction(targetPortionType);
    EXPECT_EQ(false, state.isValidMove(action));
}

TEST(MoveTest, wisdomPortion) {
    State state = getDefaultState();
    std::map<PortionType, int> availablePortions;
    availablePortions[PortionType::WISDOM] = 2;
    state.setAvailablePortions(availablePortions);
    Action action = ActionCreator::createWisdomPortionAction(2, 1);
    state.move(action);
    EXPECT_EQ(MarbleColor::NONE, state.getMarbleStorage().get(4, 1));
    EXPECT_EQ(1, state.getMarblePosession(MarbleColor::YELLOW));
    EXPECT_EQ(0, state.getMarblePosession(MarbleColor::BLACK));
    EXPECT_EQ(1, state.getAvailablePortion(PortionType::WISDOM));
}

TEST(isValidTest, wisdomPortion) {
    State state = getDefaultState();
    std::map<PortionType, int> availablePortions;
    availablePortions[PortionType::WISDOM] = 1;
    state.setAvailablePortions(availablePortions);
    Action action = ActionCreator::createWisdomPortionAction(5, 1);
    EXPECT_EQ(false, state.isValidMove(action));
    action = ActionCreator::createWisdomPortionAction(3, 1);
    EXPECT_EQ(true, state.isValidMove(action));
    availablePortions[PortionType::WISDOM] = 0;
    state.setAvailablePortions(availablePortions);
    EXPECT_EQ(false, state.isValidMove(action));
}

TEST(MoveTest, datingPortion) {
    State state = getDefaultState();
    std::map<PortionType, int> availablePortions;
    availablePortions[PortionType::DATING] = 2;
    state.setAvailablePortions(availablePortions);
    Action action = ActionCreator::createDatingPortionAction(2, 1);
    state.move(action);
    EXPECT_EQ(MarbleColor::NONE, state.getMarbleStorage().get(4, 1));
    EXPECT_EQ(MarbleColor::NONE, state.getMarbleStorage().get(3, 1));
    EXPECT_EQ(1, state.getMarblePosession(MarbleColor::YELLOW));
    EXPECT_EQ(1, state.getMarblePosession(MarbleColor::BLACK));
    EXPECT_EQ(0, state.getMarblePosession(MarbleColor::RED));
    EXPECT_EQ(1, state.getAvailablePortion(PortionType::DATING));
}

TEST(isValidTest, datingPortion) {
    State state = getDefaultState();
    state.setMarbleStorage(getTestLongMarbleStorage());
    std::map<PortionType, int> availablePortions;
    availablePortions[PortionType::DATING] = 1;
    state.setAvailablePortions(availablePortions);
    Action action = ActionCreator::createDatingPortionAction(9, 0);
    // because picking position is outside
    EXPECT_EQ(false, state.isValidMove(action));
    action = ActionCreator::createDatingPortionAction(0, 0);
    // because marbles picked are the same color
    EXPECT_EQ(false, state.isValidMove(action));
    action = ActionCreator::createDatingPortionAction(2, 0);
    EXPECT_EQ(true, state.isValidMove(action));
    availablePortions[PortionType::DATING] = 0;
    state.setAvailablePortions(availablePortions);
    EXPECT_EQ(false, state.isValidMove(action));
}

TEST(isValidTest, exchangeMarbleWithPool) {
    const auto validTest = [](const MarbleColor fromColor, const MarbleColor toColor, const MarbleColor actionFromColor, const MarbleColor actionToColor, const int exchangeNum) -> bool {
        State state = getDefaultState();
        state.setExchangeNum(exchangeNum);
        std::map<MarbleColor, int> marblePossession;
        marblePossession[fromColor] = 1;
        state.setMarblePosessions(marblePossession);
        std::map<MarbleColor, int> myMarblePool;
        myMarblePool[toColor] = 1;
        state.setMyMarblePool(myMarblePool);
        const Action action = ActionCreator::createExchangeMarbleWithPoolAction(actionFromColor, actionToColor);
        return state.isValidMove(action);
    };
    EXPECT_EQ(false, validTest(MarbleColor::NONE, MarbleColor::RED, MarbleColor::BLACK, MarbleColor::RED, 0));
    EXPECT_EQ(false, validTest(MarbleColor::RED, MarbleColor::NONE, MarbleColor::RED, MarbleColor::BLACK, 0));
    EXPECT_EQ(false, validTest(MarbleColor::RED, MarbleColor::BLACK, MarbleColor::RED, MarbleColor::BLUE, 0));
    EXPECT_EQ(false, validTest(MarbleColor::RED, MarbleColor::BLACK, MarbleColor::RED, MarbleColor::BLACK, 10));
    EXPECT_EQ(true, validTest(MarbleColor::RED, MarbleColor::BLACK, MarbleColor::RED, MarbleColor::BLACK, 0));
}

TEST(MoveTest, exchangeMarbleWithPool) {
    State state = getDefaultState();
    const MarbleColor possessionColor = MarbleColor::RED;
    const MarbleColor poolColor = MarbleColor::BLACK;
    state.setExchangeNum(0);
    std::map<MarbleColor, int> marblePossession;
    marblePossession[possessionColor] = 1;
    state.setMarblePosessions(marblePossession);
    std::map<MarbleColor, int> myMarblePool;
    myMarblePool[poolColor] = 1;
    state.setMyMarblePool(myMarblePool);
    const Action action = ActionCreator::createExchangeMarbleWithPoolAction(possessionColor, poolColor);
    state.move(action);
    EXPECT_EQ(0, state.getMarblePosession(MarbleColor::RED));
    EXPECT_EQ(1, state.getMarblePosession(MarbleColor::BLACK));
    EXPECT_EQ(1, state.getMyMarblePool(MarbleColor::RED));
    EXPECT_EQ(0, state.getMyMarblePool(MarbleColor::BLACK));
}