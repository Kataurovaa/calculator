function viewReg(){ 
    document.getElementById("registration").style.visibility = "visible";
    document.getElementById("fill-black").style.visibility = "visible";
    document.getElementById("authorization").style.visibility = "hidden";
    };
function viewAuth(){ 
    document.getElementById("authorization").style.visibility = "visible";
    document.getElementById("fill-black").style.visibility = "visible";
    document.getElementById("registration").style.visibility = "hidden";
    };

function viewFile(){ 
    document.getElementById("upload").style.visibility = "visible";
    document.getElementById("fill-black").style.visibility = "visible";
    };

function closeFill(){
    document.getElementById("fill-black").style.visibility = "hidden";
    document.getElementById("registration").style.visibility = "hidden";
    document.getElementById("upload").style.visibility = "hidden";
    document.getElementById("authorization").style.visibility = "hidden";
};

function viewProp(){ 
    if (document.getElementById("property").style.visibility == "visible"){
        document.getElementById("property").style.visibility = "hidden";
    }
    else{
        document.getElementById("property").style.visibility = "visible";
    }
};

