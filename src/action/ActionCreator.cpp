#include "Action.hpp"
#include "ActionCreator.hpp"
#include "../state/Portion.hpp"

Action ActionCreator::createProfessorHelpAction(const int y, const int x) {
    ProfessorHelpPayload professorHelpPayload(y, x);
    return Action(ActionType::PROFESSOR_HELP, professorHelpPayload);
}

Action ActionCreator::createPickMarbleAction(const int y, const int x) {
    PickMarblePayload pickMarblePayload(y, x);
    return Action(ActionType::PICK_MARBLE, pickMarblePayload);
}

Action ActionCreator::createExchangeMarbleWithPoolAction(const MarbleColor possessionMarbleColor, const MarbleColor poolMarbleColor) {
    ExchangeMarbleWithPoolPayload payload(possessionMarbleColor, poolMarbleColor);
    return Action(ActionType::EXCHANGE_MARBLE_WITH_POOL, payload);
}

Action ActionCreator::createRewindTimePortionAction(const PortionType portionType) {
    RewindTimePortionPayload rewindTimePortionPayload(portionType);
    return Action(ActionType::PORTION_TIME_REWIND, rewindTimePortionPayload);
}

Action ActionCreator::createWisdomPortionAction(const int y, const int x) {
    WisdomPortionPayload wisdomPortionPayload(y, x);
    return Action(ActionType::PORTION_WISDOM, wisdomPortionPayload);
}

Action ActionCreator::createDatingPortionAction(const int y, const int x) {
    DatingPortionPayload payload(y, x);
    return Action(ActionType::PORTION_DATING, payload);
}