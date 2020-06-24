#pragma once
#include "../state/Portion.hpp"
#include <variant>

enum class ActionType {
    PROFESSOR_HELP,
    PICK_MARBLE,
    PORTION_TIME_REWIND,
    PORTION_WISDOM
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

struct WisdomPortionPayload {
    // marble position (0-indexed)
    int y;
    int x;
    WisdomPortionPayload(const int y, const int x): y(y), x(x) {}
};

typedef std::variant<
        ProfessorHelpPayload,
        PickMarblePayload,
        RewindTimePortionPayload,
        WisdomPortionPayload
    > ActionPayload;

class Action {
public:
    Action(const ActionType actionType, const ActionPayload& payload):
        actionType(actionType),
        payload(payload)
    {}
    ActionType getActionType() const {
        return this->actionType;
    }
    ActionPayload getPayload() const {
        return this->payload;
    }
protected:
    ActionType actionType;
    ActionPayload payload;
};
