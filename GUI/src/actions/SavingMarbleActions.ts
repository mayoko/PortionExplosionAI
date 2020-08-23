import { actionCreatorFactory } from 'typescript-fsa';
import { MarbleColor } from '../states/MarbleColor';

const actionCreator = actionCreatorFactory('saving-marbles');

export const updateSavingMarbleAction = actionCreator<{
    index: number;
    marbleColor: MarbleColor;
}>('update-saving-marble');
