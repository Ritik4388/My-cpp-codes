import React from "react";
import Form from "./form.jsx";

const isUserRegistered = false;

function App(){
    return(
        <div className="container">
             <Form isRegistered = {isUserRegistered}/>
        </div>
    );
}


export default App;