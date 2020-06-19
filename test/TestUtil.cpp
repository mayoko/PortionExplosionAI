#include "TestUtil.hpp"

MarbleStorage getTestMarbleStorage() {
    std::vector<std::vector<MarbleColor> > marbleMap(5, std::vector<MarbleColor>(2));
    std::vector<std::vector<std::string> > marbleMapString(5, std::vector<std::string>(2));
    marbleMapString[0][0] = "RED";
    marbleMapString[1][0] = "BLUE";
    marbleMapString[2][0] = "YELLOW";
    marbleMapString[3][0] = "BLACK";
    marbleMapString[4][0] = "YELLOW";
    marbleMapString[0][1] = "RED";
    marbleMapString[1][1] = "BLUE";
    marbleMapString[2][1] = "YELLOW";
    marbleMapString[3][1] = "BLACK";
    marbleMapString[4][1] = "YELLOW";
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 2; x++) {
            marbleMap[y][x] = getMarbleColorFromString(marbleMapString[y][x]);
        }
    }
    MarbleStorage marbleStorage(marbleMap);
    return marbleStorage;
}

State getDefaultState() {
    State state;
    state.setMarbleStorage(getTestMarbleStorage());
    return state;
}
