import React from 'react';
import { stringToPortionType } from '../../states/Portion';
import PortionTypeSelector from '../common/PortionTypeSelector';
import CountInput from '../common/CountInput';
import MakingPortion from '../../states/MakingPortion';
import MarbleColorSelector from '../common/MarbleColorSelector';

interface Props {
    title: string;
    portion: MakingPortion;
    onUpdatePortion: (portion: Partial<MakingPortion>) => void;
}

const PortionInput: React.FC<Props> = props => {
    return (
        <div className="MakingPortionInput">
            <h4>{props.title}</h4>
            <PortionTypeSelector
                portionType={props.portion.type}
                onChange={(e: React.ChangeEvent<HTMLSelectElement>) => {
                    props.onUpdatePortion({
                        type: stringToPortionType(e.currentTarget.value),
                    });
                }}
            />
            <div className="MakingPortionInput__restColorInput">
                {props.portion.restColors.map((restColor, index) => (
                    <div key={index}>
                        <MarbleColorSelector
                            color={restColor.color}
                            onUpdate={color => {
                                const newRestColors = [
                                    ...props.portion.restColors,
                                ];
                                newRestColors[index].color = color;
                                props.onUpdatePortion({
                                    restColors: newRestColors,
                                });
                            }}
                        />
                        <CountInput
                            count={restColor.count}
                            onUpdate={count => {
                                const newRestColors = [
                                    ...props.portion.restColors,
                                ];
                                newRestColors[index].count = count;
                                props.onUpdatePortion({
                                    restColors: newRestColors,
                                });
                            }}
                        />
                    </div>
                ))}
            </div>
        </div>
    );
};

export default PortionInput;
