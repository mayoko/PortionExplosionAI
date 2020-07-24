import { actionCreatorFactory } from 'typescript-fsa';
import Portion from '../states/Portion';

const actionCreator = actionCreatorFactory('usable-portion');

export const addUsablePortionAction = actionCreator<Portion>(
    'change-usable-portion',
);

export const updateUsablePortionAction = actionCreator<{
    index: number;
    portion: Partial<Portion>;
}>('update-usable-portion');

export const deleteUsablePortionAction = actionCreator<number>(
    'delete-usable-portion',
);
