const first = document.getElementsByClassName("test")[0];
const second = document.getElementsByClassName("me")[0];
const third = document.getElementsByClassName("a")[0];
const fourth = document.getElementsByClassName("b")[0];
function newPage(){
    form = document.forms["insurance"];
    if(form["name"].value.length<=0) {
        document.getElementsByClassName("nameerr")[0].innerHTML = "Name cannot be blank"
        return false;
    }
    document.getElementsByClassName("nameerr")[0].innerHTML = ""
    if(!internalcheckPhone() || !internalcheckEmail()) {
        return false;
    }
    first.style.display = "none";
    second.style.display = "contents";
    fourth.style.display = "none";
    third.style.display = "flex";
    // updateBar('50');
    // const progress = document.getElementsByClassName("actual")[0];
    // let width = progress.style.width;
    // const final = 50;
    // const time = setInterval(updateBar, 10);
    // function updateBar() {
    //     if(width===final)
    //         clearInterval(time);
    //     else{
    //         width++;
    //         progress.style.width = width + "%";
    //     }
    // }
}
const entire = document.getElementsByClassName("final")[0];
const result = document.getElementsByClassName("aftersubmit")[0];
function finalSubmit() {
    if(!checkLink()) {
        return false;
    }
    entire.style.display = "none";
    result.style.display = "flex";
}

function updateBar(final) {
    const progress = document.getElementsByClassName("actual")[0];
    let width = progress.style.width;
    let val = "";
    for(let i=0;i<width.length;i++)
    {
        if(width[i]=="%")
            break;
        val+=width[i];
    }
    const time = setInterval(updateBar, 10);
    function updateBar() {
        if(val==final)
        {
            if(final==100)
            {
                const quote = document.getElementsByClassName("fixme")[0];
                quote.innerHTML = "Completed";
            }    
            clearInterval(time);
        }
        else{
            val++;
            progress.style.width = val + "%";
        }
    }
}

function checkPhone() {
    form = document.forms["insurance"];
    if (form["phone"].value.length != 10) {
        document.getElementsByClassName("phonerr")[0].innerHTML = "Phone number must be 10 digits"
        return false;
    }
    else{
        document.getElementsByClassName("phonerr")[0].innerHTML = ""
        updateBar('30');
        return true;
    }
}

function internalcheckPhone() {
    form = document.forms["insurance"];
    if (form["phone"].value.length != 10) {
        document.getElementsByClassName("phonerr")[0].innerHTML = "Phone number must be 10 digits"
        return false;
    }
    else{
        document.getElementsByClassName("phonerr")[0].innerHTML = ""
        return true;
    }
}

function internalcheckEmail() {
    form = document.forms["insurance"];
    // Take _,alphabets and 0-9 values before @, then a @ and 
    // then again alphabets or numbers and then a .
    // and then 2,4 alphabets
    const emailPattern = /^[a-zA-Z0-9._]+@[a-zA-Z0-9.]+\.[a-zA-Z]{2,4}$/;
    if(!emailPattern.test(form["emailfield"].value)) {
        document.getElementsByClassName("emailerr")[0].innerHTML = "Not a valid email address"
        return false;
    }
    else {
        document.getElementsByClassName("emailerr")[0].innerHTML = ""
        return true;
    }
}


function checkEmail() {
    form = document.forms["insurance"];
    // Take _,alphabets and 0-9 values before @, then a @ and 
    // then again alphabets or numbers and then a .
    // and then 2,4 alphabets
    const emailPattern = /^[a-zA-Z0-9._]+@[a-zA-Z0-9.]+\.[a-zA-Z]{2,4}$/;
    if(!emailPattern.test(form["emailfield"].value)) {
        document.getElementsByClassName("emailerr")[0].innerHTML = "Not a valid email address"
        return false;
    }
    else {
        document.getElementsByClassName("emailerr")[0].innerHTML = ""
        updateBar('45');
        return true;
    }
}

function checkLink() {
    form = document.forms["insurance"];
    if(form["digital"].value.length<=0) {
        document.getElementsByClassName("digierr")[0].innerHTML = "Cannot be left blank"
        return false;
    } else {
        document.getElementsByClassName("digierr")[0].innerHTML = ""
        return true;
    }
}