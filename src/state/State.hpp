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
    void setAvailablePortions(const std::map<PortionType, int>& availablePortions) {
        this->availablePortions = availablePortions;
    }
    void setUsedPortions(const std::map<PortionType, int>& usedPortions) {
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
    int getAvailablePortion(const PortionType portionType) const {
        return this->availablePortions.count(portionType) == 0 ? 0 : this->availablePortions.at(portionType);
    }
    int getUsedPortion(const PortionType portionType) const {
        return this->usedPortions.count(portionType) == 0 ? 0 : this->usedPortions.at(portionType);
    }
private:
    MarbleStorage marbleStorage;
    std::vector<Portion> makingPortions;
    std::map<PortionType, int> availablePortions;
    std::map<PortionType, int> usedPortions;
    std::map<MarbleColor, int> marblePosessions;
    bool askedProfessorHelp;
    int score;

    // change the state by professor help action
    void professorHelpMove(const ProfessorHelpPayload& professorHelpPayload);
    // change the state by picking marble action
    void pickMarbleMove(const PickMarblePayload& pickMarblePayload);
    // change the state by portion -- time rewind
    void rewindTimePortionMove(const RewindTimePortionPayload& rewindTimePortionPayload);
    // change the state by portion -- wisdom
    void wisdomPortionMove(const WisdomPortionPayload& payload);
};