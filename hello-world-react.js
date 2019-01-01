import React, { Component } from 'react';

class HelloWorld extends Component {
    constructor(props) {
        super(props);

        this.state =  {
            hello_hacktober: "Hello, World"
        };
    }

    render() {
        return (
            <div class="hello">
                <p>
                    {this.state.hello_hacktober}   
                </p>
            </div>
        );
    }
}

export default HelloWorld;