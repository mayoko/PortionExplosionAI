import { actionCreatorFactory } from 'typescript-fsa';
import { PortionType } from '../states/Portion';
import { ColorToCount } from '../states/MakingPortion';

const actionCreator = actionCreatorFactory('usable-portion');

export const updateMakingPortionTypeAction = actionCreator<{
    index: number;
    portionType: PortionType;
}>('update-making-portion-type');

export const updateMakingPortionColorToCountAction = actionCreator<{
    index: number;
    mapIndex: number;
    colorToCount: Partial<ColorToCount>;
}>('update-making-portion-color-color-to-count');

export const addMakingPortionColorToCountAction = actionCreator<{
    index: number;
    colorToCount: ColorToCount;
}>('add-making-portion-color-color-to-count');

export const deleteMakingPortionColorToCountAction = actionCreator<{
    index: number;
    mapIndex: number;
}>('delete-making-portion-color-color-to-count');
