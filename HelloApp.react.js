import React from "react";
import { render } from "react-dom";

const HelloApp = () => (
  <div>
    <h1>Hello World</h1>
  </div>
);

render(<HelloApp />, document.getElementById("app"));
