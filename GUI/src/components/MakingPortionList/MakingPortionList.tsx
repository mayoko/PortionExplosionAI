import React from 'react';
import MakingPortion from '../../states/MakingPortion';
import MakingPortionInput from './MakingPortionInput';

interface Props {
    title: string;
    portions: MakingPortion[];
    updatePortion: (index: number, portion: Partial<MakingPortion>) => void;
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
                    onUpdatePortion={(portion: Partial<MakingPortion>) => {
                        props.updatePortion(index, portion);
                    }}
                />
            ))}
        </div>
    );
};

export default PortionList;
