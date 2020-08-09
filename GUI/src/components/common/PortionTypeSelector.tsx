import React from 'react';
import { PortionType } from '../../states/MakingPortion';

interface Props {
    portionType: PortionType;
    onChange: (e: React.ChangeEvent<HTMLSelectElement>) => void;
}

const PortionTypeSelector: React.FC<Props> = props => {
    return (
        <div className="PortionTypeSelector">
            <select
                name="portionType"
                value={props.portionType.toString()}
                onChange={props.onChange}>
                {Object.values(PortionType).map(portionType => (
                    <option key={portionType} value={portionType}>
                        {portionType}
                    </option>
                ))}
            </select>
        </div>
    );
};

export default PortionTypeSelector;
