import { reducerWithInitialState } from 'typescript-fsa-reducers';
import { changeUserAction } from '../actions/UserActions';
import User from '../states/User';

const initUser: User = {
    count: 0,
    name: '',
};

const userReducer = reducerWithInitialState<User>(initUser)
    .case(changeUserAction, (state, payload) => ({
        ...state,
        ...payload,
    }))
    .build();

export default userReducer;
