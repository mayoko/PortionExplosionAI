import { combineReducers, createStore } from 'redux';
import { State } from './states/State';
import usablePortionReducer from './reducers/UsablePortions';

const combinnedReducer = combineReducers<State>({
    usablePortions: usablePortionReducer,
});

export const store = createStore(combinnedReducer);

export default store;
