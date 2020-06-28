#pragma once
#include "../state/Portion.hpp"
#include <variant>

enum class ActionType {
    PROFESSOR_HELP,
    PICK_MARBLE,
    EXCHANGE_MARBLE_WITH_POOL,
    MOVE_MARBLE_TO_POOL,
    PORTION_TIME_REWIND,
    PORTION_WISDOM,
    PORTION_DATING
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

struct ExchangeMarbleWithPoolPayload {
    MarbleColor possessionMarbleColor;
    MarbleColor poolMarbleColor;
    ExchangeMarbleWithPoolPayload(const MarbleColor possessionMarbleColor, const MarbleColor poolMarbleColor):
            possessionMarbleColor(possessionMarbleColor),
            poolMarbleColor(poolMarbleColor)
    {}
};

struct MoveMarbleToPoolPayload{
    MarbleColor marbleColor;
    MoveMarbleToPoolPayload(const MarbleColor marbleColor): marbleColor(marbleColor) {}
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

struct DatingPortionPayload {
    // marble position (0-indexed)
    // will get (y, x) and (y+1, x)
    int y;
    int x;
    DatingPortionPayload(const int y, const int x): y(y), x(x) {}
};

typedef std::variant<
        ProfessorHelpPayload,
        PickMarblePayload,
        ExchangeMarbleWithPoolPayload,
        MoveMarbleToPoolPayload,
        RewindTimePortionPayload,
        WisdomPortionPayload,
        DatingPortionPayload
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
