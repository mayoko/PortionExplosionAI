#pragma once

#include <string>

enum class MarbleColor {
    RED,
    BLUE,
    YELLOW,
    BLACK,
    NONE
};

// return MarbleColor class from string. if the color is not expected, return NONE.
// @param marbleColorString: represents color. that should be "RED", "BLUE", "YELLOW", "BLACK".
MarbleColor getMarbleColorFromString(const std::string marbleColorString);