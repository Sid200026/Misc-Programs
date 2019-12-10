const first = document.getElementsByClassName("test")[0];
const second = document.getElementsByClassName("me")[0];
const third = document.getElementsByClassName("a")[0];
const fourth = document.getElementsByClassName("b")[0];
function newPage(){
    first.style.display = "none";
    second.style.display = "contents";
    fourth.style.display = "none";
    third.style.display = "flex";
    const progress = document.getElementsByClassName("actual")[0];
    let width = progress.style.width;
    const final = 50;
    const time = setInterval(updateBar, 10);
    function updateBar() {
        if(width===final)
            clearInterval(time);
        else{
            width++;
            progress.style.width = width + "%";
        }
    }
}
const entire = document.getElementsByClassName("final")[0];
const result = document.getElementsByClassName("aftersubmit")[0];
function finalSubmit() {
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