#pragma once

#include "./Action.hpp"
#include "../state/Portion.hpp"
#include "../state/MarbleColor.hpp"

class ActionCreator {
public:
    static Action createProfessorHelpAction(const int y, const int x);
    static Action createPickMarbleAction(const int y, const int x);
    static Action createExchangeMarbleWithPoolAction(const MarbleColor possessionMarbleColor, const MarbleColor poolMarbleColor);
    static Action createMoveMarbleToPoolAction(const MarbleColor marbleColor);
    static Action createMoveMarbleToPortionAction(const int index, const MarbleColor marbleColor);
    static Action createRewindTimePortionAction(const PortionType portionType);
    static Action createWisdomPortionAction(const int y, const int x);
    static Action createDatingPortionAction(const int y, const int x);
private:
    ActionCreator() {}
    ActionCreator(const ActionCreator& ActionCreator) {}
    void operator=(const ActionCreator& actionCreator) {}
};