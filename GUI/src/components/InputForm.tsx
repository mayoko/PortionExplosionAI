import React from 'react';
import PortionListContainer from './PortionList/PortionListContainer';
import MakingPortionListContainer from './MakingPortionList/MakingPortionListContainer';

const InputForm: React.FC = () => {
    return (
        <div className="InputForm">
            <PortionListContainer label="usable" title="usable portions" />
            <PortionListContainer
                label="discarded"
                title="discarded portions"
            />
            <MakingPortionListContainer title="making portions" />
        </div>
    );
};

export default InputForm;
