import { actionCreatorFactory } from 'typescript-fsa';
import Portion from '../states/Portion';

const actionCreator = actionCreatorFactory('usable-portion');

export const addDiscardedPortionAction = actionCreator<Portion>(
    'change-discarded-portion',
);

export const updateDiscardedPortionAction = actionCreator<{
    index: number;
    portion: Partial<Portion>;
}>('update-discarded-portion');

export const deleteDiscardedPortionAction = actionCreator<number>(
    'delete-discarded-portion',
);
