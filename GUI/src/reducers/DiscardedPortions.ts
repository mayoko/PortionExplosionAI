import { reducerWithInitialState } from 'typescript-fsa-reducers';
import {
    addDiscardedPortionAction,
    updateDiscardedPortionAction,
    deleteDiscardedPortionAction,
} from '../actions/DiscardedPortionActions';
import Portion, { PortionType } from '../states/Portion';

const initDiscardedPortions: Portion[] = [
    {
        type: PortionType.NONE,
        count: 0,
    },
];

const discardedPortionReducer = reducerWithInitialState<Portion[]>(
    initDiscardedPortions,
)
    .case(addDiscardedPortionAction, (state, payload) => [...state, payload])
    .case(updateDiscardedPortionAction, (state, payload) => {
        const index = payload.index;
        const nextState: Portion[] = [...state];
        if (index >= state.length) {
            return nextState;
        }
        nextState[index] = { ...nextState[index], ...payload.portion };
        return nextState;
    })
    .case(deleteDiscardedPortionAction, (state, payload) => {
        // payload is index
        const nextState: Portion[] = [...state];
        nextState.splice(payload, 1);
        return nextState;
    })
    .build();

export default discardedPortionReducer;
