<?php
$cars = array("a1","a2","a3","a4","a5","a6","a7","a8","a9","a10");
$inp = "a1";
$index = -1;
for($i = 0; $i<count($cars); $i++){
    if($cars[$i] == $inp) {
        $index = $i;
    }
}
if($index == -1) {
    $index = "Not Found";
}
echo $index;
?>