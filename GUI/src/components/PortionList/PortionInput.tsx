import React from 'react';
import Portion, {
    PortionType,
    stringToPortionType,
} from '../../states/Portion';

interface Props {
    label: 'usable' | 'discarded';
    portion: Portion;
    onClickDeleteButton: () => void;
    onUpdatePortion: (portion: Partial<Portion>) => void;
}

const PortionInput: React.FC<Props> = props => {
    return (
        <div className="Portion">
            <div className="Portion__PortionType">
                <select
                    name="portionType"
                    value={props.portion.type.toString()}
                    onChange={(e: React.ChangeEvent<HTMLSelectElement>) => {
                        props.onUpdatePortion({
                            type: stringToPortionType(e.currentTarget.value),
                        });
                    }}>
                    {Object.values(PortionType).map(portionType => (
                        <option key={portionType} value={portionType}>
                            {portionType}
                        </option>
                    ))}
                </select>
            </div>
            <div className="Portion__PortionCount">
                <input
                    type="text"
                    name="portionCount"
                    value={props.portion.count}
                    onChange={(e: React.ChangeEvent<HTMLInputElement>) => {
                        const value: number = parseInt(
                            e.currentTarget.value || '0',
                        );
                        if (value === NaN) {
                            return;
                        }
                        props.onUpdatePortion({
                            count: value,
                        });
                    }}
                />
            </div>
            <div className="Portion__PortionDelete">
                <button onClick={props.onClickDeleteButton}>Delete</button>
            </div>
        </div>
    );
};

export default PortionInput;
