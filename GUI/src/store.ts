import { combineReducers, createStore } from 'redux';
import { State } from './states/State';
import usablePortionReducer from './reducers/UsablePortions';
import discardedPortionReducer from './reducers/DiscardedPortions';
import makingPortionReducer from './reducers/MakingPortions';

const combinnedReducer = combineReducers<State>({
    usablePortions: usablePortionReducer,
    discardedPortions: discardedPortionReducer,
    makingPortions: makingPortionReducer,
});

export const store = createStore(combinnedReducer);

export default store;
