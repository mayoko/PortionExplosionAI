import React from 'react';

interface Props {
    count: number;
    onUpdate: (count: number) => void;
}

const PortionTypeSelector: React.FC<Props> = props => {
    return (
        <div className="CountInput">
            <input
                type="text"
                name="countInput"
                value={props.count}
                onChange={(e: React.ChangeEvent<HTMLInputElement>) => {
                    const value: number = parseInt(
                        e.currentTarget.value || '0',
                    );
                    if (value === NaN) {
                        return;
                    }
                    props.onUpdate(value);
                }}
            />
        </div>
    );
};

export default PortionTypeSelector;
