#pragma once

#include <vector>
#include <map>
#include <utility>

#include "MarbleColor.hpp"

// This class represents marble storage.
// y: bottom index is 0 x: left index is 0
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
    MarbleStorage& operator=(const MarbleStorage& marbleStorage) {
        this->marbleMap = marbleStorage.marbleMap;
        return *this;
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

    // get Marble Map
    std::vector<std::vector<MarbleColor> > getMarbleMap() const;

private:
    std::vector<std::vector<MarbleColor> > marbleMap;
    // simulate marble falling.
    // returns the list of index where collision happens.
    // if one of the element in the list is y, then the collision happend between (y, col) and (y+1, col) marbles
    // @param col: the column we should simulate (0-based)
    std::vector<int> fallSimulate(const int col);
    // In x-column, find the maximum y-range where the marble color is same.
    // return the minimum index in the range and maximum index + 1 in the range (half-open section).
    std::pair<int, int> findSameColorRange(const int y, const int x);
};