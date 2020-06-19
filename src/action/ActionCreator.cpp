#include "Action.hpp"
#include "ActionCreator.hpp"

Action ActionCreator::createProfessorHelpAction(const int y, const int x) {
    ProfessorHelpPayload *professorHelpPayload = new ProfessorHelpPayload(y, x);
    return Action(ActionType::PROFESSOR_HELP, static_cast<void*>(professorHelpPayload));
}