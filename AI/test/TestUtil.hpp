#pragma once
#include <vector>
#include "../src/state/MarbleStorage.hpp"
#include "../src/state/State.hpp"
#include "../src/state/Portion.hpp"

MarbleStorage getTestMarbleStorage();
MarbleStorage getTestLongMarbleStorage();
State getDefaultState();
Portion getDefaultPortion();
std::vector<Portion> getDefaultPortions();