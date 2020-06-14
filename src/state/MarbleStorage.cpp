#include "MarbleStorage.hpp"

MarbleColor MarbleStorage::get(const int y, const int x) const {
    const int height = this->marbleMap.size();
    if (height == 0) {
        return MarbleColor::NONE;
    }
    const int width = this->marbleMap[0].size();
    if (y < 0 || y >= height || x < 0 || x >= width) {
        return MarbleColor::NONE;
    }
    return this->marbleMap[y][x];
}

std::map<MarbleColor, int> pickMove(const int y, const int x) {
    std::map<MarbleColor, int> result;
    return result;
}

std::map<MarbleColor, int> pickWithoutExplosionMove(const int y, const int x) {
    std::map<MarbleColor, int> result;
    return result;
}