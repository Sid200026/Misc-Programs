const first = document.getElementsByClassName("test")[0];
const second = document.getElementsByClassName("me")[0];
const third = document.getElementsByClassName("a")[0];
const fourth = document.getElementsByClassName("b")[0];
function newPage(){
    first.style.display = "none";
    second.style.display = "contents";
    fourth.style.display = "none";
    third.style.display = "flex";
}