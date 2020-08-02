import React from 'react';
import Portion, { stringToPortionType } from '../../states/Portion';
import PortionTypeSelector from '../common/PortionTypeSelector';
import CountInput from '../common/CountInput';

interface Props {
    label: 'usable' | 'discarded';
    portion: Portion;
    onClickDeleteButton: () => void;
    onUpdatePortion: (portion: Partial<Portion>) => void;
}

const PortionInput: React.FC<Props> = props => {
    return (
        <div className="Portion">
            <PortionTypeSelector
                portionType={props.portion.type}
                onChange={(e: React.ChangeEvent<HTMLSelectElement>) => {
                    props.onUpdatePortion({
                        type: stringToPortionType(e.currentTarget.value),
                    });
                }}
            />
            <CountInput
                count={props.portion.count}
                onUpdate={count => props.onUpdatePortion({ count: count })}
            />
            <div className="Portion__PortionDelete">
                <button onClick={props.onClickDeleteButton}>Delete</button>
            </div>
        </div>
    );
};

export default PortionInput;
