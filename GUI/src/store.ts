import { combineReducers, createStore } from 'redux';
import { State } from './states/State';
import userReducer from './reducers/UserReducer';

const combinnedReducer = combineReducers<State>({
    user: userReducer,
});

export const store = createStore(combinnedReducer);

export default store;
