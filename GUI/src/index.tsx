import React from 'react';
import ReactDOM from 'react-dom';
import { Provider } from 'react-redux';
import InputForm from './components/InputForm';
import Store from './store';

const container = document.getElementById('contents');

ReactDOM.render(
    <Provider store={Store}>
        <InputForm />
    </Provider>,
    container,
);
