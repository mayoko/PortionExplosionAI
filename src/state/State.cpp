#include "State.hpp"
#include <utility>
#include <variant>

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
        case ActionType::PORTION_DATING:
        {
            const DatingPortionPayload payload = std::get<DatingPortionPayload>(action.getPayload());
            return this->datingPortionMove(payload);
        }
    }
}

bool State::isValidMove(const Action& action) const {
    switch(action.getActionType()) {
        case ActionType::PROFESSOR_HELP:
        {
            const ProfessorHelpPayload payload = std::get<ProfessorHelpPayload>(action.getPayload());
            return !this->askedProfessorHelp && this->marbleStorage.get(payload.y, payload.x) != MarbleColor::NONE;
        }
        case ActionType::PICK_MARBLE:
        {
            const PickMarblePayload payload = std::get<PickMarblePayload>(action.getPayload());
            return !this->pickedMarble && this->marbleStorage.get(payload.y, payload.x) != MarbleColor::NONE;
        }
        case ActionType::PORTION_TIME_REWIND:
        {
            const RewindTimePortionPayload payload = std::get<RewindTimePortionPayload>(action.getPayload());
            return getAvailablePortion(PortionType::REWIND_TIME) > 0 && getUsedPortion(payload.portionType) > 0;
        }
        case ActionType::PORTION_WISDOM:
        {
            const WisdomPortionPayload payload = std::get<WisdomPortionPayload>(action.getPayload());
            return this->marbleStorage.get(payload.y, payload.x) != MarbleColor::NONE && getAvailablePortion(PortionType::WISDOM) > 0;
        }
        case ActionType::PORTION_DATING:
        {
            const DatingPortionPayload payload = std::get<DatingPortionPayload>(action.getPayload());
            const MarbleColor color1 = this->marbleStorage.get(payload.y, payload.x);
            const MarbleColor color2 = this->marbleStorage.get(payload.y + 1, payload.x);
            return color1 != MarbleColor::NONE && color2 != MarbleColor::NONE && color1 != color2 && getAvailablePortion(PortionType::DATING) > 0;
        }
    }
    return true;
}

void State::professorHelpMove(const ProfessorHelpPayload& professorHelpPayload) {
    std::vector<std::pair<int, int> > position(1);
    position[0] = std::make_pair(professorHelpPayload.y, professorHelpPayload.x);
    const std::map<MarbleColor, int> result = this->marbleStorage.pickWithoutExplosionMove(position);
    for (const auto p: result) {
        this->marblePosessions[p.first] += p.second;
    }
    this->setAskedProfessorHelp(true);
    score -= 2;
}

void State::pickMarbleMove(const PickMarblePayload& pickMarblePayload) {
    const std::map<MarbleColor, int> result = this->marbleStorage.pickMove(pickMarblePayload.y, pickMarblePayload.x);
    for (const auto p: result) {
        this->marblePosessions[p.first] += p.second;
    }
    this->setPickedMarble(true);
}

void State::rewindTimePortionMove(const RewindTimePortionPayload& payload) {
    const PortionType portionType = payload.portionType;
    if (this->usedPortions[portionType] == 0) {
        return;
    }
    --availablePortions[PortionType::REWIND_TIME];
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
    --availablePortions[PortionType::WISDOM];
}

void State::datingPortionMove(const DatingPortionPayload& payload) {
    std::vector<std::pair<int, int> > position(2);
    position[0] = std::make_pair(payload.y, payload.x);
    position[1] = std::make_pair(payload.y + 1, payload.x);
    const std::map<MarbleColor, int> result = this->marbleStorage.pickWithoutExplosionMove(position);
    for (const auto p: result) {
        this->marblePosessions[p.first] += p.second;
    }
    --availablePortions[PortionType::DATING];
}