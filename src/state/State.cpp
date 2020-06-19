#include "State.hpp"
#include <utility>

State::State(const State& state):
    marbleStorage(state.marbleStorage),
    makingPortions(state.makingPortions),
    availablePortions(state.availablePortions),
    usedPortions(state.usedPortions),
    askedProfessorHelp(state.askedProfessorHelp)
{}

State::State():
    marbleStorage(MarbleStorage()),
    makingPortions(),
    availablePortions(),
    usedPortions(),
    askedProfessorHelp()
{}

void State::move(const Action& action) {
    switch(action.getActionType()) {
        case ActionType::PROFESSOR_HELP:
            ProfessorHelpPayload *professorHelpPayload = static_cast<ProfessorHelpPayload*>(action.getPayload());
            return this->professorHelpMove(*professorHelpPayload);
    }
}

void State::professorHelpMove(const ProfessorHelpPayload& professorHelpPayload) {
    std::vector<std::pair<int, int> > position(1);
    position[0] = std::make_pair(professorHelpPayload.y, professorHelpPayload.x);
    this->marbleStorage.pickWithoutExplosionMove(position);
}