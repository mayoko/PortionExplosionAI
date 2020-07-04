#include <vector>
#include <map>
#include "../src/state/MarbleStorage.hpp"
#include "../src/state/MarbleColor.hpp"
#include "TestUtil.hpp"
#include "gtest/gtest.h"

int getCount(const std::map<MarbleColor, int>& marbleColorMap, const MarbleColor marbleColor) {
    return marbleColorMap.count(marbleColor) ? marbleColorMap.at(marbleColor) : 0;
};

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

// valid pick test
TEST(MarbleStorageTest, pickWithoutExplosionValidMove) {
    MarbleStorage marbleStorage = getTestMarbleStorage();

    std::vector<std::pair<int, int> > indexList(4);
    indexList[0] = std::make_pair(0, 0);
    indexList[1] = std::make_pair(3, 0);
    indexList[2] = std::make_pair(1, 1);
    indexList[3] = std::make_pair(3, 1);
    const std::map<MarbleColor, int> result = marbleStorage.pickWithoutExplosionMove(indexList);
    EXPECT_EQ(1, getCount(result, MarbleColor::RED));
    EXPECT_EQ(1, getCount(result, MarbleColor::BLUE));
    EXPECT_EQ(0, getCount(result, MarbleColor::YELLOW));
    EXPECT_EQ(2, getCount(result, MarbleColor::BLACK));
    EXPECT_EQ(0, getCount(result, MarbleColor::NONE));

    std::vector<std::vector<std::string> > expectedMarbleMapString(5, std::vector<std::string>(2));
    expectedMarbleMapString[0][0] = "BLUE";
    expectedMarbleMapString[1][0] = "YELLOW";
    expectedMarbleMapString[2][0] = "YELLOW";
    expectedMarbleMapString[0][1] = "RED";
    expectedMarbleMapString[1][1] = "YELLOW";
    expectedMarbleMapString[2][1] = "YELLOW";

    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 2; x++) {
            EXPECT_EQ(getMarbleColorFromString(expectedMarbleMapString[y][x]), marbleStorage.get(y, x));
        }
    }
}

// invalid pick test
TEST(MarbleStorageTest, pickWithoutExplosionInvalidMove) {
    MarbleStorage marbleStorage = getTestMarbleStorage();

    std::vector<std::pair<int, int> > indexList(1);
    indexList[0] = std::make_pair(0, -1);
    const std::map<MarbleColor, int> result = marbleStorage.pickWithoutExplosionMove(indexList);
    EXPECT_EQ(0, getCount(result, MarbleColor::RED));
    EXPECT_EQ(0, getCount(result, MarbleColor::BLUE));
    EXPECT_EQ(0, getCount(result, MarbleColor::YELLOW));
    EXPECT_EQ(0, getCount(result, MarbleColor::BLACK));
    EXPECT_EQ(0, getCount(result, MarbleColor::NONE));
}

// valid pick test
TEST(MarbleStorageTest, pickValidMove) {
    MarbleStorage marbleStorage = getTestMarbleStorage();

    const std::map<MarbleColor, int> result = marbleStorage.pickMove(3, 0);
    EXPECT_EQ(0, getCount(result, MarbleColor::RED));
    EXPECT_EQ(0, getCount(result, MarbleColor::BLUE));
    EXPECT_EQ(2, getCount(result, MarbleColor::YELLOW));
    EXPECT_EQ(1, getCount(result, MarbleColor::BLACK));
    EXPECT_EQ(0, getCount(result, MarbleColor::NONE));

    std::vector<std::vector<std::string> > expectedMarbleMapString(5, std::vector<std::string>(2));
    expectedMarbleMapString[0][0] = "RED";
    expectedMarbleMapString[1][0] = "BLUE";
    expectedMarbleMapString[0][1] = "RED";
    expectedMarbleMapString[1][1] = "BLUE";
    expectedMarbleMapString[2][1] = "YELLOW";
    expectedMarbleMapString[3][1] = "BLACK";
    expectedMarbleMapString[4][1] = "YELLOW";

    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 2; x++) {
            EXPECT_EQ(getMarbleColorFromString(expectedMarbleMapString[y][x]), marbleStorage.get(y, x));
        }
    }
}

// valid pick, 2 explosion will happen
TEST(MarbleStorageTest, twoExplosionWillHappen) {
    MarbleStorage marbleStorage = getTestLongMarbleStorage();

    const std::map<MarbleColor, int> result = marbleStorage.pickMove(3, 0);
    EXPECT_EQ(0, getCount(result, MarbleColor::RED));
    EXPECT_EQ(3, getCount(result, MarbleColor::BLUE));
    EXPECT_EQ(2, getCount(result, MarbleColor::YELLOW));
    EXPECT_EQ(1, getCount(result, MarbleColor::BLACK));
    EXPECT_EQ(0, getCount(result, MarbleColor::NONE));

    std::vector<std::vector<std::string> > expectedMarbleMapString(10, std::vector<std::string>(1));
    expectedMarbleMapString[0][0] = "YELLOW";
    expectedMarbleMapString[1][0] = "YELLOW";
    expectedMarbleMapString[2][0] = "BLACK";
    expectedMarbleMapString[3][0] = "YELLOW";

    // for (int y = 0; y < 10; y++) {
    //     for (int x = 0; x < 1; x++) {
    //         EXPECT_EQ(getMarbleColorFromString(expectedMarbleMapString[y][x]), marbleStorage.get(y, x));
    //     }
    // }
}

// valid pick, more than 3 pieces explose at the same time
TEST(MarbleStorageTest, threePiecesExploseAtTheSameTime) {
    MarbleStorage marbleStorage = getTestLongMarbleStorage();

    const std::map<MarbleColor, int> result = marbleStorage.pickMove(8, 0);
    EXPECT_EQ(0, getCount(result, MarbleColor::RED));
    EXPECT_EQ(0, getCount(result, MarbleColor::BLUE));
    EXPECT_EQ(3, getCount(result, MarbleColor::YELLOW));
    EXPECT_EQ(1, getCount(result, MarbleColor::BLACK));
    EXPECT_EQ(0, getCount(result, MarbleColor::NONE));

    std::vector<std::vector<std::string> > expectedMarbleMapString(10, std::vector<std::string>(1));
    expectedMarbleMapString[0][0] = "BLUE";
    expectedMarbleMapString[1][0] = "BLUE";
    expectedMarbleMapString[2][0] = "YELLOW";
    expectedMarbleMapString[3][0] = "BLACK";
    expectedMarbleMapString[4][0] = "YELLOW";
    expectedMarbleMapString[5][0] = "BLUE";

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 1; x++) {
            EXPECT_EQ(getMarbleColorFromString(expectedMarbleMapString[y][x]), marbleStorage.get(y, x));
        }
    }
}

// invalid pick test
TEST(MarbleStorageTest, pickInvalidMove) {
    MarbleStorage marbleStorage = getTestMarbleStorage();

    const std::map<MarbleColor, int> result = marbleStorage.pickMove(7, 0);
    EXPECT_EQ(0, getCount(result, MarbleColor::RED));
    EXPECT_EQ(0, getCount(result, MarbleColor::BLUE));
    EXPECT_EQ(0, getCount(result, MarbleColor::YELLOW));
    EXPECT_EQ(0, getCount(result, MarbleColor::BLACK));
    EXPECT_EQ(0, getCount(result, MarbleColor::NONE));
}