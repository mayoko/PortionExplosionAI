#pragma once

#include <vector>
#include "MarbleStorage.hpp"
#include "Portion.hpp"

class State {
public:
    State(const State& state);
private:
    MarbleStorage marbleStorage;
    std::vector<Portion> makingPortions;
    std::vector<PortionType> availablePortions;
    std::vector<PortionType> usedPortions;
    bool askedProfessorHelp;
}