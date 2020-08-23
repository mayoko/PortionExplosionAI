import React, { useCallback } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { State } from '../../states/State';
import MakingPortion, { ColorToCount } from '../../states/MakingPortion';
import { MarbleColor } from '../../states/MarbleColor';
import MakingPortionList from './MakingPortionList';
import {
    updateMakingPortionTypeAction,
    updateMakingPortionColorToCountAction,
    addMakingPortionColorToCountAction,
    deleteMakingPortionColorToCountAction,
} from '../../actions/MakingPortionActions';
import { PortionType } from '../../states/Portion';

interface Props {
    title: string;
}

const MakingPortionListContainer: React.FC<Props> = (props: Props) => {
    const portions = useSelector<State, MakingPortion[]>(
        state => state.makingPortions,
    );
    const dispatch = useDispatch();

    const updatePortionType = useCallback(
        (index: number, portionType: PortionType) => {
            dispatch(
                updateMakingPortionTypeAction({
                    index: index,
                    portionType: portionType,
                }),
            );
        },
        [],
    );
    const updateColorToCount = useCallback(
        (
            index: number,
            mapIndex: number,
            colorToCount: Partial<ColorToCount>,
        ) => {
            dispatch(
                updateMakingPortionColorToCountAction({
                    index: index,
                    mapIndex: mapIndex,
                    colorToCount: colorToCount,
                }),
            );
        },
        [],
    );
    const addColorToCount = useCallback(
        (index: number, colorToCount: ColorToCount) => {
            dispatch(
                addMakingPortionColorToCountAction({
                    index: index,
                    colorToCount: colorToCount,
                }),
            );
        },
        [],
    );
    const deleteColorToCount = useCallback(
        (index: number, mapIndex: number) => {
            dispatch(
                deleteMakingPortionColorToCountAction({
                    index: index,
                    mapIndex: mapIndex,
                }),
            );
        },
        [],
    );
    return (
        <MakingPortionList
            title={props.title}
            portions={portions}
            updatePortionType={updatePortionType}
            updateColorToCount={updateColorToCount}
            addColorToCount={index => {
                addColorToCount(index, {
                    color: MarbleColor.NONE,
                    count: 0,
                });
            }}
            deleteColorToCount={deleteColorToCount}
        />
    );
};

export default MakingPortionListContainer;
