#include "Action.hpp"
#include "ActionCreator.hpp"
#include "../state/Portion.hpp"

Action ActionCreator::createProfessorHelpAction(const int y, const int x) {
    ProfessorHelpPayload *professorHelpPayload = new ProfessorHelpPayload(y, x);
    return Action(ActionType::PROFESSOR_HELP, static_cast<void*>(professorHelpPayload));
}

Action ActionCreator::createPickMarbleAction(const int y, const int x) {
    PickMarblePayload *pickMarblePayload = new PickMarblePayload(y, x);
    return Action(ActionType::PICK_MARBLE, static_cast<void*>(pickMarblePayload));
}

Action ActionCreator::createRewindTimePortionAction(const PortionType portionType) {
    RewindTimePortionPayload *rewindTimePortionPayload = new RewindTimePortionPayload(portionType);
    return Action(ActionType::PORTION_TIME_REWIND, rewindTimePortionPayload);
}