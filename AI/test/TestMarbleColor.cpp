#include "../src/state/MarbleColor.hpp"
#include "gtest/gtest.h"

TEST(MarbleColorTest, getMarbleColorFromString) {
    EXPECT_EQ(MarbleColor::NONE, getMarbleColorFromString("UNK"));
    EXPECT_EQ(MarbleColor::RED, getMarbleColorFromString("RED"));
    EXPECT_EQ(MarbleColor::BLUE, getMarbleColorFromString("BLUE"));
    EXPECT_EQ(MarbleColor::YELLOW, getMarbleColorFromString("YELLOW"));
    EXPECT_EQ(MarbleColor::BLACK, getMarbleColorFromString("BLACK"));
}