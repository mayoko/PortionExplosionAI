#include "Action.hpp"
#include "ActionCreator.hpp"

Action ActionCreator::createProfessorHelpAction(const int y, const int x) {
    ProfessorHelpPayload *professorHelpPayload = new ProfessorHelpPayload(y, x);
    return Action(ActionType::PROFESSOR_HELP, static_cast<void*>(professorHelpPayload));
}

Action ActionCreator::createPickMarbleAction(const int y, const int x) {
    PickMarblePayload *pickMarblePayload = new PickMarblePayload(y, x);
    return Action(ActionType::PICK_MARBLE, static_cast<void*>(pickMarblePayload));
}