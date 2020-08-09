import React from 'react';
import { stringToPortionType, PortionType } from '../../states/Portion';
import PortionTypeSelector from '../common/PortionTypeSelector';
import CountInput from '../common/CountInput';
import MakingPortion, { ColorToCount } from '../../states/MakingPortion';
import MarbleColorSelector from '../common/MarbleColorSelector';

interface Props {
    title: string;
    portion: MakingPortion;
    onUpdatePortionType: (portionType: PortionType) => void;
    onUpdateColorToCount: (
        mapIndex: number,
        colorToCount: Partial<ColorToCount>,
    ) => void;
    onAddColorToCount: () => void;
    onDeleteColorToCount: (index: number) => void;
}

const PortionInput: React.FC<Props> = props => {
    return (
        <div className="MakingPortionInput">
            <h4>{props.title}</h4>
            <PortionTypeSelector
                portionType={props.portion.type}
                onChange={(e: React.ChangeEvent<HTMLSelectElement>) => {
                    props.onUpdatePortionType(
                        stringToPortionType(e.currentTarget.value),
                    );
                }}
            />
            <div className="MakingPortionInput__restColorInput">
                {props.portion.colorToCounts.map((colorToCount, index) => (
                    <div key={index}>
                        <MarbleColorSelector
                            color={colorToCount.color}
                            onUpdate={color =>
                                props.onUpdateColorToCount(index, {
                                    color: color,
                                })
                            }
                        />
                        <CountInput
                            count={colorToCount.count}
                            onUpdate={count =>
                                props.onUpdateColorToCount(index, {
                                    count: count,
                                })
                            }
                        />
                        <button
                            onClick={() => props.onDeleteColorToCount(index)}>
                            delete
                        </button>
                    </div>
                ))}
                <div className="MakingPortionInput__restColorInput-add">
                    <button onClick={props.onAddColorToCount}>Add</button>
                </div>
            </div>
        </div>
    );
};

export default PortionInput;
