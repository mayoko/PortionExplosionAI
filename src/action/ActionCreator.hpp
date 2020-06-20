#pragma once
#include "./Action.hpp"

class ActionCreator {
public:
    static Action createProfessorHelpAction(const int y, const int x);
    static Action createPickMarbleAction(const int y, const int x);
private:
    ActionCreator() {}
    ActionCreator(const ActionCreator& ActionCreator) {}
    void operator=(const ActionCreator& actionCreator) {}
};