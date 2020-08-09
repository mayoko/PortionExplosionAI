import { reducerWithInitialState } from 'typescript-fsa-reducers';
import { PortionType } from '../states/Portion';
import {
    updateMakingPortionTypeAction,
    updateMakingPortionColorToCountAction,
    addMakingPortionColorToCountAction,
    deleteMakingPortionColorToCountAction,
} from '../actions/MakingPortionActions';
import MakingPortion, { MarbleColor } from '../states/MakingPortion';

const initMakingPortions: MakingPortion[] = [
    {
        type: PortionType.NONE,
        colorToCounts: [
            {
                color: MarbleColor.NONE,
                count: 0,
            },
        ],
    },
    {
        type: PortionType.NONE,
        colorToCounts: [
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
    .case(updateMakingPortionTypeAction, (state, payload) => {
        const index = payload.index;
        const nextState: MakingPortion[] = [...state];
        if (index >= state.length || index < 0) {
            return nextState;
        }
        nextState[index].type = payload.portionType;
        return nextState;
    })
    .case(updateMakingPortionColorToCountAction, (state, payload) => {
        const index = payload.index;
        const nextState: MakingPortion[] = [...state];
        if (index >= state.length || index < 0) {
            return nextState;
        }
        const mapIndex = payload.mapIndex;
        if (mapIndex < 0 || mapIndex >= state[index].colorToCounts.length) {
            return nextState;
        }
        nextState[index].colorToCounts[mapIndex] = {
            ...nextState[index].colorToCounts[mapIndex],
            ...payload.colorToCount,
        };
        return nextState;
    })
    .case(addMakingPortionColorToCountAction, (state, payload) => {
        const index = payload.index;
        const nextState: MakingPortion[] = [...state];
        if (index >= state.length || index < 0) {
            return nextState;
        }
        nextState[index].colorToCounts = [
            ...nextState[index].colorToCounts,
            payload.colorToCount,
        ];
        return nextState;
    })
    .case(deleteMakingPortionColorToCountAction, (state, payload) => {
        const index = payload.index;
        const nextState: MakingPortion[] = [...state];
        if (index >= state.length || index < 0) {
            return nextState;
        }
        const mapIndex = payload.mapIndex;
        nextState[index].colorToCounts.splice(mapIndex, 1);
        return nextState;
    })
    .build();

export default makingPortionReducer;
