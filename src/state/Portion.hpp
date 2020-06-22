#pragma once
#include <map>
#include "./MarbleColor.hpp"

enum class PortionType {
    FALL_IN_LOVE, // get other person's marble
    REWIND_TIME, // reuse the portion already used
    WISDOM, // same as "help from professor"
    DATING, // get 2 different-colored-and-neighbored marbles in the same column. explosion doesn't happen
    MOVE_MARBLE, // move the marble in the pool to empty pole
    BREAK_MARBLE_STORAGE, // remove at most 5 marbles on the same column from the marble storage
    GET_SAME_COLOR, // get the same color marbles in a row in the same column. explosion doesn't happen
    GET_BOTTOM_MARBLE // get the different colored-marbles from each column. for each color, you can only get 1 marble.
};

class Portion {
public:
    Portion(const PortionType portionType, const std::map<MarbleColor, int> targetPortionMap):
        portionType(portionType),
        targetPortionMap(targetPortionMap)
        {
            for (const auto p: targetPortionMap) {
                currentPortionMap[p.first] = 0;
            }
        }
    Portion& operator=(const Portion& portion) {
        this->portionType = portion.portionType;
        this->currentPortionMap = portion.currentPortionMap;
        this->targetPortionMap = portion.targetPortionMap;
        return *this;
    }
    // add 1 marble to the portion. if the move is invalid, return -1. if valid, return 0;
    int addMarble(const MarbleColor marbleColor);
    // remove 1 marble to the portion. if the move is invalid, return -1. if valid, return 0;
    int removeMarble(const MarbleColor marbleColor);
    // get the current number of marbles in the portion
    int get(const MarbleColor marbleColor) const {
        return currentPortionMap.count(marbleColor) == 0 ? 0 : currentPortionMap.at(marbleColor);
    }
private:
    PortionType portionType;
    std::map<MarbleColor, int> currentPortionMap;
    std::map<MarbleColor, int> targetPortionMap;
};