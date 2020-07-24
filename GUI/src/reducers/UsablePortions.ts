import { reducerWithInitialState } from 'typescript-fsa-reducers';
import {
    addUsablePortionAction,
    updateUsablePortionAction,
    deleteUsablePortionAction,
} from '../actions/UsablePortionActions';
import Portion, { PortionType } from '../states/Portion';

const initUsablePortions: Portion[] = [
    {
        type: PortionType.NONE,
        count: 0,
    },
];

const usablePortionReducer = reducerWithInitialState<Portion[]>(
    initUsablePortions,
)
    .case(addUsablePortionAction, (state, payload) => [...state, payload])
    .case(updateUsablePortionAction, (state, payload) => {
        const index = payload.index;
        const nextState: Portion[] = [...state];
        if (index >= state.length) {
            return nextState;
        }
        nextState[index] = { ...nextState[index], ...payload.portion };
        return nextState;
    })
    .case(deleteUsablePortionAction, (state, payload) => {
        // payload is index
        console.log(state);
        console.log(payload);
        const nextState: Portion[] = [...state];
        nextState.splice(payload, 1);
        return nextState;
    })
    .build();

export default usablePortionReducer;
