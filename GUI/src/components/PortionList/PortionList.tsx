import React from 'react';
import Portion from '../../states/Portion';
import PortionInput from './PortionInput';

interface Props {
    title: string;
    label: 'usable' | 'discarded';
    portions: Portion[];
    addPortion: () => void;
    updatePortion: (index: number, portion: Partial<Portion>) => void;
    deletePortion: (index: number) => void;
}

const PortionList: React.FC<Props> = props => {
    return (
        <div className="PortionList">
            <h3 className="PortionList__title">{props.title}</h3>
            {props.portions.map((portion, index) => (
                <PortionInput
                    key={index}
                    label={props.label}
                    portion={portion}
                    onClickDeleteButton={() => {
                        props.deletePortion(index);
                    }}
                    onUpdatePortion={(portion: Partial<Portion>) => {
                        props.updatePortion(index, portion);
                    }}
                />
            ))}
            <div className="PortionList__addButton">
                <button onClick={props.addPortion}>Add</button>
            </div>
        </div>
    );
};

export default PortionList;
