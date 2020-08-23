import React, { useCallback } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { State } from '../../states/State';
import { MarbleColor } from '../../states/MarbleColor';
import SavingMarbleInput from './SavingMarbleInput';
import { updateSavingMarbleAction } from '../../actions/SavingMarbleActions';

interface Props {
    title: string;
}

const SavingMarbleInputContainer: React.FC<Props> = props => {
    const marbleColors = useSelector<State, MarbleColor[]>(
        state => state.savingMarbles,
    );
    const dispatch = useDispatch();

    const updateColor = useCallback(
        (index: number, marbleColor: MarbleColor) => {
            dispatch(updateSavingMarbleAction({ index, marbleColor }));
        },
        [],
    );
    return (
        <SavingMarbleInput
            title={props.title}
            marbleColors={marbleColors}
            updateColor={updateColor}
        />
    );
};

export default SavingMarbleInputContainer;
