#pragma once

#include <vector>
#include <map>
#include <utility>

enum class MarbleColor {
    RED,
    BLUE,
    YELLOW,
    BLACK,
    NONE
};

class MarbleStorage {
    public:
    MarbleStorage() {}
    ~MarbleStorage() {}
    MarbleStorage(const MarbleStorage& marbleStorage) {
        marbleMap = marbleStorage.marbleMap;
    }
    MarbleStorage(const std::vector<std::vector<MarbleColor> > marbleMap) {
        this->marbleMap = marbleMap;
    }
    // pick one marble and simulate explosion.
    // this function will mutate the class.
    // return how many marbles you would get after the picking
    // if the move is invalid, the sum of marbles you would get is 0
    // @param y: y-index (0-based)
    // @param x: x-index (0-based)
    std::map<MarbleColor, int> pickMove(const int y, const int x);

    // pick one marble. the difference from pick function is that it won't simulate explosion.
    // this function will mutate the class.
    // return how many marbles you would get after the picking
    // if the move is invalid, the sum of marbles you would get is 0
    // @param indexList: list of (y, x). the definition of y and x is same as pick function.
    std::map<MarbleColor, int> pickWithoutExplosionMove(const std::vector<std::pair<int, int> >& indexList);

    // get Marble color for the specific idnex.
    // @param y: y-index (0-based)
    // @param x: x-index (0-based)
    MarbleColor get(const int y, const int x) const;

    private:
    std::vector<std::vector<MarbleColor> > marbleMap;
};