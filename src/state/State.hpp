#pragma once

#include <vector>
#include "MarbleStorage.hpp"
#include "Portion.hpp"
#include "../action/Action.hpp"

class State {
public:
    State();
    State(const State& state);
    // change the state by action
    void move(const Action& action);

    // getter / setter
    MarbleStorage getMarbleStorage() const {
        return this->marbleStorage;
    }
    void setMarbleStorage(const MarbleStorage& marbleStorage) {
        this->marbleStorage = marbleStorage;
    }
    void setMakingPortions(const std::vector<Portion>& makingPortions) {
        this->makingPortions = makingPortions;
    }
    void setAvailablePortions(const std::vector<PortionType>& availablePortions) {
        this->availablePortions = availablePortions;
    }
    void setUsedPortions(const std::vector<PortionType>& usedPortions) {
        this->usedPortions = usedPortions;
    }
    void setAskedProfessorHelp(const bool askedProfessorHelp) {
        this->askedProfessorHelp = askedProfessorHelp;
    }
private:
    MarbleStorage marbleStorage;
    std::vector<Portion> makingPortions;
    std::vector<PortionType> availablePortions;
    std::vector<PortionType> usedPortions;
    bool askedProfessorHelp;

    // change the state by professor help action
    void professorHelpMove(const ProfessorHelpPayload& professorHelpPayload);
};