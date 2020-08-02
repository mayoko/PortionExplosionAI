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
import {
    updateDiscardedPortionAction,
    addDiscardedPortionAction,
    deleteDiscardedPortionAction,
} from '../../actions/DiscardedPortionActions';

interface Props {
    title: string;
    label: 'usable' | 'discarded';
}

const PortionListContainer: React.FC<Props> = (props: Props) => {
    const portions = useSelector<State, Portion[]>(state =>
        props.label === 'usable'
            ? state.usablePortions
            : state.discardedPortions,
    );
    const dispatch = useDispatch();

    const [updateAction, addAction, deleteAction] =
        props.label === 'usable'
            ? [
                  updateUsablePortionAction,
                  addUsablePortionAction,
                  deleteUsablePortionAction,
              ]
            : [
                  updateDiscardedPortionAction,
                  addDiscardedPortionAction,
                  deleteDiscardedPortionAction,
              ];

    const updatePortion = useCallback(
        (index: number, portion: Partial<Portion>) => {
            dispatch(
                updateAction({
                    index: index,
                    portion: portion,
                }),
            );
        },
        [],
    );
    const addPortion = useCallback(() => {
        dispatch(
            addAction({
                type: PortionType.NONE,
                count: 0,
            }),
        );
    }, []);
    const deletePortion = useCallback((index: number) => {
        dispatch(deleteAction(index));
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
