#include "../src/state/Portion.hpp"
#include "../src/state/MarbleColor.hpp"
#include "gtest/gtest.h"

TEST(PortionTest, addSameColorMarbleTest) {
    std::map<MarbleColor, int> targetPortionMap;
    targetPortionMap[MarbleColor::BLACK] = 2;
    Portion portion(PortionType::FALL_IN_LOVE, targetPortionMap);
    {
        const int result = portion.addMarble(MarbleColor::BLACK);
        EXPECT_EQ(0, result);
        EXPECT_EQ(1, portion.get(MarbleColor::BLACK));
    }
    {
        const int result = portion.addMarble(MarbleColor::BLACK);
        EXPECT_EQ(0, result);
        EXPECT_EQ(2, portion.get(MarbleColor::BLACK));
    }
    {
        const int result = portion.addMarble(MarbleColor::BLACK);
        EXPECT_EQ(-1, result);
    }
}

TEST(PortionTest, addInvalidMarbleTest) {
    std::map<MarbleColor, int> targetPortionMap;
    targetPortionMap[MarbleColor::BLACK] = 3;
    Portion portion(PortionType::FALL_IN_LOVE, targetPortionMap);
    const int result = portion.addMarble(MarbleColor::BLUE);
    EXPECT_EQ(-1, result);
}

TEST(PortionTest, removeSameColorMarbleTest) {
    std::map<MarbleColor, int> targetPortionMap;
    targetPortionMap[MarbleColor::BLACK] = 2;
    Portion portion(PortionType::FALL_IN_LOVE, targetPortionMap);
    portion.addMarble(MarbleColor::BLACK);
    {
        const int result = portion.removeMarble(MarbleColor::BLACK);
        EXPECT_EQ(0, result);
        EXPECT_EQ(0, portion.get(MarbleColor::BLACK));
    }
    {
        const int result = portion.removeMarble(MarbleColor::BLACK);
        EXPECT_EQ(-1, result);
    }
}

TEST(PortionTest, removeInvalidMarbleTest) {
    std::map<MarbleColor, int> targetPortionMap;
    targetPortionMap[MarbleColor::BLACK] = 3;
    Portion portion(PortionType::FALL_IN_LOVE, targetPortionMap);
    const int result = portion.removeMarble(MarbleColor::BLUE);
    EXPECT_EQ(-1, result);
}