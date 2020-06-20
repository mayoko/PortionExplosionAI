#pragma once

#include <vector>
#include "MarbleStorage.hpp"
#include "MarbleColor.hpp"
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
    void setMarblePosessions(const std::map<MarbleColor, int> marblePosessions) {
        this->marblePosessions = marblePosessions;
    }
    int getMarblePosession(const MarbleColor marbleColor) const {
        return this->marblePosessions.count(marbleColor) == 0 ? 0 : this->marblePosessions.at(marbleColor);
    }
private:
    MarbleStorage marbleStorage;
    std::vector<Portion> makingPortions;
    std::vector<PortionType> availablePortions;
    std::vector<PortionType> usedPortions;
    std::map<MarbleColor, int> marblePosessions;
    bool askedProfessorHelp;

    // change the state by professor help action
    void professorHelpMove(const ProfessorHelpPayload& professorHelpPayload);
    // change the state by picking marble action
    void pickMarbleMove(const PickMarblePayload& pickMarblePayload);
};