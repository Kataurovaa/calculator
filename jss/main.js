function viewReg(){ 
    document.getElementById("registration").style.visibility = "visible";
    document.getElementById("fill-black").style.visibility = "visible";
    };

function viewFile(){ 
    document.getElementById("upload").style.visibility = "visible";
    document.getElementById("fill-black").style.visibility = "visible";
    };

function closeFill(){
    document.getElementById("fill-black").style.visibility = "hidden";
    document.getElementById("registration").style.visibility = "hidden";
    document.getElementById("upload").style.visibility = "hidden";
}