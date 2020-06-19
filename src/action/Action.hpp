#pragma once

enum class ActionType {
    PROFESSOR_HELP
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