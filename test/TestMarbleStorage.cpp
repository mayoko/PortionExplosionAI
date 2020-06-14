#include <vector>
#include <map>
#include "../src/state/MarbleStorage.hpp"
#include "gtest/gtest.h"

TEST(MarbleStorageTest, get) {
    // create 1x1 matrix
    std::vector<std::vector<MarbleColor> > marbleMap(1, std::vector<MarbleColor>(1));
    marbleMap[0][0] = MarbleColor::RED;
    const MarbleStorage marbleStorage(marbleMap);
    EXPECT_EQ(MarbleColor::NONE, marbleStorage.get(-1, 0));
    EXPECT_EQ(MarbleColor::NONE, marbleStorage.get(0, -1));
    EXPECT_EQ(MarbleColor::NONE, marbleStorage.get(0, 2));
    EXPECT_EQ(MarbleColor::NONE, marbleStorage.get(3, 0));
    EXPECT_EQ(MarbleColor::RED, marbleStorage.get(0, 0));
}