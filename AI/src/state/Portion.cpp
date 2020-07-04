#include "Portion.hpp"

int Portion::addMarble(const MarbleColor marbleColor) {
    if (this->currentPortionMap.count(marbleColor) == 0 ||
        this->currentPortionMap[marbleColor] >= this->targetPortionMap.at(marbleColor)) {
            return -1;
    }
    this->currentPortionMap[marbleColor]++;
    return 0;
}

int Portion::removeMarble(const MarbleColor marbleColor) {
    if (this->currentPortionMap.count(marbleColor) == 0 ||
        this->currentPortionMap[marbleColor] == 0) {
            return -1;
    }
    this->currentPortionMap[marbleColor]--;
    return 0;
}