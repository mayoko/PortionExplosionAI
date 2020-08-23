import { reducerWithInitialState } from 'typescript-fsa-reducers';
import { updateSavingMarbleAction } from '../actions/SavingMarbleActions';
import { MarbleColor } from '../states/MarbleColor';

const initSavingMarbleColors: MarbleColor[] = [
    MarbleColor.NONE,
    MarbleColor.NONE,
    MarbleColor.NONE,
];

const savingMarbleReducer = reducerWithInitialState<MarbleColor[]>(
    initSavingMarbleColors,
)
    .case(updateSavingMarbleAction, (state, payload) => {
        const index = payload.index;
        const nextState: MarbleColor[] = [...state];
        if (index >= state.length) {
            return nextState;
        }
        nextState[index] = payload.marbleColor;
        return nextState;
    })
    .build();

export default savingMarbleReducer;
