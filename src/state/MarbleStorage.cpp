#include "MarbleStorage.hpp"
#include <set>

bool outRange(const int y, const int x, const int height, const int width) {
    return y < 0 || y >= height || x < 0 || x >= width;
}

MarbleColor MarbleStorage::get(const int y, const int x) const {
    const int height = this->marbleMap.size();
    if (height == 0) {
        return MarbleColor::NONE;
    }
    const int width = this->marbleMap[0].size();
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
            const std::pair<int, int> yRange = findSameColorRange(collisionY, x);
            const int minY = yRange.first;
            const int maxY = yRange.second;
            if (maxY - minY == 1) {
                break;
            }
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
    int lastNonEmpty = -1;
    std::vector<int> result;
    for (int y = 0; y < marbleMap.size(); y++) {
        if (marbleMap[y][col] != MarbleColor::NONE) {
            if (y != lastNonEmpty + 1) {
                marbleMap[lastNonEmpty+1][col] = marbleMap[y][col];
                marbleMap[y][col] = MarbleColor::NONE;
                if (lastNonEmpty != -1) {
                    result.push_back(lastNonEmpty);
                }
            }
            lastNonEmpty++;
        }
    }
    return result;
}

std::pair<int, int> MarbleStorage::findSameColorRange(const int y, const int x) {
    // min-rannge
    int minY = y - 1;
    while (minY >= 0) {
        if (marbleMap[minY][x] != marbleMap[y][x]) {
            break;
        }
        minY--;
    }
    minY++;
    // max-range
    int maxY = y + 1;
    while (maxY < marbleMap.size()) {
        if (marbleMap[maxY][x] != marbleMap[y][x]) {
            break;
        }
        maxY++;
    }
    return std::make_pair(minY, maxY);
}