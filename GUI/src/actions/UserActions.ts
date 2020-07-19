import { actionCreatorFactory } from 'typescript-fsa';
import User from '../states/User';

const actionCreator = actionCreatorFactory('user-action');

export const changeUserAction = actionCreator<Partial<User>>('change-user');
