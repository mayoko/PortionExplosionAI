import React from 'react';
import { MarbleColor, stringToMarbleColor } from '../../states/MakingPortion';

interface Props {
    color: MarbleColor;
    onUpdate: (color: MarbleColor) => void;
}

const MarbleColorSelector: React.FC<Props> = props => {
    return (
        <div className="CountInput">
            <select
                name="portionType"
                value={props.color.toString()}
                onChange={(e: React.ChangeEvent<HTMLSelectElement>) =>
                    props.onUpdate(stringToMarbleColor(e.currentTarget.value))
                }>
                {Object.values(MarbleColor).map(color => (
                    <option key={color} value={color}>
                        {color}
                    </option>
                ))}
            </select>
        </div>
    );
};

export default MarbleColorSelector;
