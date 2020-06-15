#include "MarbleColor.hpp"

MarbleColor getMarbleColorFromString(const std::string marbleColorString) {
    if (marbleColorString == "RED") {
        return MarbleColor::RED;
    }
    if (marbleColorString == "BLUE") {
        return MarbleColor::BLUE;
    }
    if (marbleColorString == "YELLOW") {
        return MarbleColor::YELLOW;
    }
    if (marbleColorString == "BLACK") {
        return MarbleColor::BLACK;
    }
    return MarbleColor::NONE;
}