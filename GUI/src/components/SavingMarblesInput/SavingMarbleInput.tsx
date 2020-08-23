import React from 'react';
import MarbleColorSelector from '../common/MarbleColorSelector';
import { MarbleColor } from '../../states/MarbleColor';

interface Props {
    title: string;
    marbleColors: MarbleColor[];
    updateColor: (index: number, color: MarbleColor) => void;
}

const SavingMarbleInput: React.FC<Props> = props => {
    return (
        <div className="SavingMarble">
            <h4>{props.title}</h4>
            {props.marbleColors.map((color, index) => (
                <div key={index}>
                    <MarbleColorSelector
                        color={color}
                        onUpdate={color => props.updateColor(index, color)}
                    />
                </div>
            ))}
        </div>
    );
};

export default SavingMarbleInput;
