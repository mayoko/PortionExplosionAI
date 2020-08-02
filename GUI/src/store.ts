import { combineReducers, createStore } from 'redux';
import { State } from './states/State';
import usablePortionReducer from './reducers/UsablePortions';
import discardedPortionReducer from './reducers/DiscardedPortions';

const combinnedReducer = combineReducers<State>({
    usablePortions: usablePortionReducer,
    discardedPortions: discardedPortionReducer,
});

export const store = createStore(combinnedReducer);

export default store;
