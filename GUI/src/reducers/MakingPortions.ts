import { reducerWithInitialState } from 'typescript-fsa-reducers';
import { PortionType } from '../states/Portion';
import { updateMakingPortionAction } from '../actions/MakingPortionActions';
import MakingPortion, { MarbleColor } from '../states/MakingPortion';

const initMakingPortions: MakingPortion[] = [
    {
        type: PortionType.NONE,
        restColors: [
            {
                color: MarbleColor.NONE,
                count: 0,
            },
        ],
    },
    {
        type: PortionType.NONE,
        restColors: [
            {
                color: MarbleColor.NONE,
                count: 0,
            },
        ],
    },
];

const makingPortionReducer = reducerWithInitialState<MakingPortion[]>(
    initMakingPortions,
)
    .case(updateMakingPortionAction, (state, payload) => {
        const index = payload.index;
        const nextState: MakingPortion[] = [...state];
        if (index >= state.length || index < 0) {
            return nextState;
        }
        nextState[index] = { ...nextState[index], ...payload.portion };
        return nextState;
    })
    .build();

export default makingPortionReducer;
