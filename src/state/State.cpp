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
        {
            const ProfessorHelpPayload payload = std::get<ProfessorHelpPayload>(action.getPayload());
            return this->professorHelpMove(payload);
        }
        case ActionType::PICK_MARBLE:
        {
            const PickMarblePayload payload = std::get<PickMarblePayload>(action.getPayload());
            return this->pickMarbleMove(payload);
        }
        case ActionType::PORTION_TIME_REWIND:
        {
            const RewindTimePortionPayload payload = std::get<RewindTimePortionPayload>(action.getPayload());
            return this->rewindTimePortionMove(payload);
        }
        case ActionType::PORTION_WISDOM:
        {
            const WisdomPortionPayload payload = std::get<WisdomPortionPayload>(action.getPayload());
            return this->wisdomPortionMove(payload);
        }
    }
}

void State::professorHelpMove(const ProfessorHelpPayload& professorHelpPayload) {
    std::vector<std::pair<int, int> > position(1);
    position[0] = std::make_pair(professorHelpPayload.y, professorHelpPayload.x);
    const std::map<MarbleColor, int> result = this->marbleStorage.pickWithoutExplosionMove(position);
    for (const auto p: result) {
        this->marblePosessions[p.first] += p.second;
    }
    score -= 2;
}

void State::pickMarbleMove(const PickMarblePayload& pickMarblePayload) {
    const std::map<MarbleColor, int> result = this->marbleStorage.pickMove(pickMarblePayload.y, pickMarblePayload.x);
    for (const auto p: result) {
        this->marblePosessions[p.first] += p.second;
    }
}

void State::rewindTimePortionMove(const RewindTimePortionPayload& payload) {
    const PortionType portionType = payload.portionType;
    if (this->usedPortions[portionType] == 0) {
        return;
    }
    --usedPortions[portionType];
    ++availablePortions[portionType];
}

void State::wisdomPortionMove(const WisdomPortionPayload& payload) {
    std::vector<std::pair<int, int> > position(1);
    position[0] = std::make_pair(payload.y, payload.x);
    const std::map<MarbleColor, int> result = this->marbleStorage.pickWithoutExplosionMove(position);
    for (const auto p: result) {
        this->marblePosessions[p.first] += p.second;
    }
}