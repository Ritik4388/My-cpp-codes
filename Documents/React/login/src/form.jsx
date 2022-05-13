import React from "react";

function Form(props){
    return(
        <form className="form">
            <input placeholder="Username" type= "text" />
            <input placeholder="Password" type= "text" />
            {props.isRegistered ? null : <input placeholder="Confirm-Password" type= "text" />} 
            <button type="submit">
                {props.isRegistered ? "Login" : "Register"}
            </button>
        </form>
    );
}

export default Form;