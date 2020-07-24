import React, { useCallback } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { changeUserAction } from '../actions/UserActions';
import { State } from '../states/State';
import User from '../states/User';
import CountButton from './CountButton';
import TextBox from './TextBox';

const UserForm: React.FC = () => {
    const { name, count } = useSelector<State, User>(a => a.user);
    const dispatch = useDispatch();
    const onNameChange = useCallback((value: string) => {
        dispatch(changeUserAction({ name: value }));
    }, []);
    const onCountClick = useCallback(() => {
        dispatch(changeUserAction({ count: count + 1 }));
    }, [count]);
    return (
        <div>
            <p>
                <TextBox
                    value={name}
                    label="User Name"
                    type="text"
                    onChangeText={onNameChange}
                />
            </p>
            <p>
                <CountButton
                    count={count}
                    label="visits"
                    onClick={onCountClick}
                />
            </p>
        </div>
    );
};

export default UserForm;
