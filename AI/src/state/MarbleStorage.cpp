#include "MarbleStorage.hpp"
#include <set>
#include <iostream>

bool outRange(const int y, const int x, const int height, const int width) {
    return y < 0 || y >= height || x < 0 || x >= width;
}

MarbleColor MarbleStorage::get(const int y, const int x) const {
    if (height == 0) {
        return MarbleColor::NONE;
    }
    if (outRange(y, x, height, width)) {
        return MarbleColor::NONE;
    }
    return this->marbleMap[y][x];
}

std::map<MarbleColor, int> MarbleStorage::pickMove(const int y, const int x) {
    std::map<MarbleColor, int> result;
    if (this->get(y, x) == MarbleColor::NONE) {
        return result;
    }
    result[marbleMap[y][x]]++;
    marbleMap[y][x] = MarbleColor::NONE;
    while (true) {
        bool endFlag = true;
        const std::vector<int> collisionPos = fallSimulate(x);
        // collisionPos.length should be 0 or 1
        for (const int collisionY: collisionPos) {
            if (this->get(collisionY, x) != this->get(collisionY+1, x)) {
                continue;
            }
            const std::pair<int, int> yRange = findSameColorRange(collisionY, x);
            const int minY = yRange.first;
            const int maxY = yRange.second;
            endFlag = false;
            result[marbleMap[minY][x]] += maxY - minY;
            for (int tmpY = minY; tmpY < maxY; tmpY++) {
                marbleMap[tmpY][x] = MarbleColor::NONE;
            }
        }
        if (endFlag) {
            break;
        }
    }
    return result;
}

std::map<MarbleColor, int> MarbleStorage::pickWithoutExplosionMove(const std::vector<std::pair<int, int> >& indexList) {
    std::map<MarbleColor, int> result;
    std::set<int> simulateColumns;
    for (const auto p: indexList) {
        const int y = p.first;
        const int x = p.second;
        if (this->get(y, x) == MarbleColor::NONE) {
            return std::map<MarbleColor, int>();
        }
        result[marbleMap[y][x]]++;
        marbleMap[y][x] = MarbleColor::NONE;
        simulateColumns.insert(x);
    }
    for (const int x: simulateColumns) {
        fallSimulate(x);
    }
    return result;
}

std::vector<int> MarbleStorage::fallSimulate(const int col) {
    int y = 0, bottomY = 0;
    std::vector<int> result;
    while (y < height) {
        while (y < height && this->get(y, col) == MarbleColor::NONE) {
            ++y;
        }
        if (y == height) {
            break;
        }
        int maxY = y+1;
        while (maxY < height && this->get(maxY, col) != MarbleColor::NONE) {
            ++maxY;
        }
        if (bottomY != 0) {
            result.push_back(bottomY-1);
        }
        if (y != bottomY) {
            for (int offset = 0; offset < maxY-y; ++offset) {
                std::swap(marbleMap[bottomY+offset][col], marbleMap[y+offset][col]);
            }
        }
        bottomY += maxY - y;
        y = maxY;
    }
    return result;
}

std::pair<int, int> MarbleStorage::findSameColorRange(const int y, const int x) {
    // min-rannge
    int minY = y - 1;
    while (minY >= 0) {
        if (this->get(minY, x) != this->get(y, x)) {
            break;
        }
        minY--;
    }
    minY++;
    // max-range
    int maxY = y + 1;
    while (maxY < marbleMap.size()) {
        if (this->get(maxY, x) != this->get(y, x)) {
            break;
        }
        maxY++;
    }
    return std::make_pair(minY, maxY);
}