import React from 'react';
import MakingPortion from '../../states/MakingPortion';
import MakingPortionInput from './MakingPortionInput';
import { PortionType } from '../../states/Portion';
import { ColorToCount } from '../../states/MakingPortion';

interface Props {
    title: string;
    portions: MakingPortion[];
    updatePortionType: (index: number, portionType: PortionType) => void;
    updateColorToCount: (
        index: number,
        mapIndex: number,
        colorToCount: Partial<ColorToCount>,
    ) => void;
    addColorToCount: (index: number) => void;
    deleteColorToCount: (index: number, mapIndex: number) => void;
}

const PortionList: React.FC<Props> = props => {
    return (
        <div className="MakingPortionList">
            <h3 className="MakingPortionList__title">{props.title}</h3>
            {props.portions.map((portion, index) => (
                <MakingPortionInput
                    key={index}
                    title={`portion ${index + 1}`}
                    portion={portion}
                    onUpdatePortionType={portionType => {
                        props.updatePortionType(index, portionType);
                    }}
                    onAddColorToCount={() => props.addColorToCount(index)}
                    onDeleteColorToCount={mapIndex =>
                        props.deleteColorToCount(index, mapIndex)
                    }
                    onUpdateColorToCount={(mapIndex, colorToCount) =>
                        props.updateColorToCount(index, mapIndex, colorToCount)
                    }
                />
            ))}
        </div>
    );
};

export default PortionList;
