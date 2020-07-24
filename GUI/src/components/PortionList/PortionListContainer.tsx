import React, { useCallback } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { State } from '../../states/State';
import Portion, { PortionType } from '../../states/Portion';
import {
    updateUsablePortionAction,
    addUsablePortionAction,
    deleteUsablePortionAction,
} from '../../actions/UsablePortionActions';
import PortionList from './PortionList';

interface Props {
    title: string;
    label: 'usable' | 'discarded';
}

const PortionListContainer: React.FC<Props> = (props: Props) => {
    const portions = useSelector<State, Portion[]>(
        state => state.usablePortions,
    );
    const dispatch = useDispatch();
    const updatePortion = useCallback(
        (index: number, portion: Partial<Portion>) => {
            dispatch(
                updateUsablePortionAction({
                    index: index,
                    portion: portion,
                }),
            );
        },
        [],
    );
    const addPortion = useCallback(() => {
        dispatch(
            addUsablePortionAction({
                type: PortionType.NONE,
                count: 0,
            }),
        );
    }, []);
    const deletePortion = useCallback((index: number) => {
        dispatch(deleteUsablePortionAction(index));
    }, []);
    return (
        <PortionList
            title={props.title}
            label={props.label}
            portions={portions}
            addPortion={addPortion}
            updatePortion={updatePortion}
            deletePortion={deletePortion}
        />
    );
};

export default PortionListContainer;
