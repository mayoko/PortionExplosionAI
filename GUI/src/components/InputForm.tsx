import React from 'react';
import PortionListContainer from './PortionList/PortionListContainer';

const InputForm: React.FC = () => {
    return (
        <div className="InputForm">
            <PortionListContainer label="usable" title="usable portions" />
        </div>
    );
};

export default InputForm;
