#pragma once
#include "../state/Portion.hpp"

enum class ActionType {
    PROFESSOR_HELP,
    PICK_MARBLE,
    PORTION_TIME_REWIND
};

class Action {
public:
    Action(const ActionType actionType, void* payload):
        actionType(actionType),
        payload(payload)
    {}
    ActionType getActionType() const {
        return this->actionType;
    }
    void* getPayload() const {
        return this->payload;
    }
protected:
    ActionType actionType;
    void* payload;
};

struct ProfessorHelpPayload {
    // marble position (0-indexed)
    int y;
    int x;
    ProfessorHelpPayload(const int y, const int x): y(y), x(x) {}
};

struct PickMarblePayload {
    // marble position (0-indexed)
    int y;
    int x;
    PickMarblePayload(const int y, const int x): y(y), x(x) {}
};

struct RewindTimePortionPayload {
    PortionType portionType;
    RewindTimePortionPayload(const PortionType portionType): portionType(portionType) {}
};