import { actionCreatorFactory } from 'typescript-fsa';
import MakingPortion from '../states/MakingPortion';

const actionCreator = actionCreatorFactory('usable-portion');

export const updateMakingPortionAction = actionCreator<{
    index: number;
    portion: Partial<MakingPortion>;
}>('update-making-portion');
