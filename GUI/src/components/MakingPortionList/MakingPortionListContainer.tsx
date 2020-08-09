import React, { useCallback } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { State } from '../../states/State';
import MakingPortion from '../../states/MakingPortion';
import MakingPortionList from './MakingPortionList';
import { updateMakingPortionAction } from '../../actions/MakingPortionActions';

interface Props {
    title: string;
}

const MakingPortionListContainer: React.FC<Props> = (props: Props) => {
    const portions = useSelector<State, MakingPortion[]>(
        state => state.makingPortions,
    );
    const dispatch = useDispatch();

    const updatePortion = useCallback(
        (index: number, portion: Partial<MakingPortion>) => {
            dispatch(
                updateMakingPortionAction({
                    index: index,
                    portion: portion,
                }),
            );
        },
        [],
    );
    return (
        <MakingPortionList
            title={props.title}
            portions={portions}
            updatePortion={updatePortion}
        />
    );
};

export default MakingPortionListContainer;
