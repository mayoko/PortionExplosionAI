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
    bool isValidMove(const Action& action) const;

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
    void setExchangeNum(const int exchangeNum) {
        this->exchangeNum = exchangeNum;
    }
    void setMyMarblePool(const std::map<MarbleColor, int> myMarblePool) {
        this->myMarblePool = myMarblePool;
    }
    void setOtherMarblePools(const std::vector<std::map<MarbleColor, int> > otherMarblePools) {
        this->otherMarblePools = otherMarblePools;
    }
    void setUsedPortions(const std::map<PortionType, int>& usedPortions) {
        this->usedPortions = usedPortions;
    }
    void setPickedMarble(const bool pickedMarble) {
        this->pickedMarble = pickedMarble;
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
    int getMyMarblePool(const MarbleColor marbleColor) const {
        return this->myMarblePool.count(marbleColor) == 0 ? 0 : this->myMarblePool.at(marbleColor);
    }
    int getOtherMarblePool(const int index, const MarbleColor marbleColor) const {
        if (index < 0 || index >= this->otherMarblePools.size()) return 0;
        return this->otherMarblePools[index].count(marbleColor) == 0 ? 0 : this->otherMarblePools[index].at(marbleColor);
    }
    int getAvailablePortion(const PortionType portionType) const {
        return this->availablePortions.count(portionType) == 0 ? 0 : this->availablePortions.at(portionType);
    }
    int getUsedPortion(const PortionType portionType) const {
        return this->usedPortions.count(portionType) == 0 ? 0 : this->usedPortions.at(portionType);
    }
    bool isAskedProfessorHelp() const {
        return this->askedProfessorHelp;
    }
    bool isPickedMarble() const {
        return this->pickedMarble;
    }
private:
    MarbleStorage marbleStorage;
    std::vector<Portion> makingPortions;
    std::map<PortionType, int> availablePortions;
    std::map<PortionType, int> usedPortions;
    std::map<MarbleColor, int> marblePosessions;
    std::map<MarbleColor, int> myMarblePool;
    std::vector<std::map<MarbleColor, int> > otherMarblePools;
    bool askedProfessorHelp;
    bool pickedMarble;
    int score;
    // the number of exchange from possession to pool
    int exchangeNum;

    const static int MAX_EXCHANGE_NUM = 3;

    // change the state by professor help action
    void professorHelpMove(const ProfessorHelpPayload& professorHelpPayload);
    // change the state by picking marble action
    void pickMarbleMove(const PickMarblePayload& pickMarblePayload);
    // exchange marble with pool
    void exchangeMarbleWithPoolMove(const ExchangeMarbleWithPoolPayload payload);
    // change the state by portion -- time rewind
    void rewindTimePortionMove(const RewindTimePortionPayload& rewindTimePortionPayload);
    // change the state by portion -- wisdom
    void wisdomPortionMove(const WisdomPortionPayload& payload);
    // change the state by portion -- dating
    void datingPortionMove(const DatingPortionPayload& payload);
};