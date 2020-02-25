<?php
// $myfile = fopen("webdictionary.txt", "r") or die("Unable to open file!");
$myfile = fopen("newfile.txt", "w") or die("Unable to open file!");
for ($x = 0; $x <= 99; $x++) {
    fwrite($myfile, $x."\n");
}
fclose($myfile);
$myfile = fopen("newfile.txt", "r") or die("Unable to open file!");
for($x = 0; $x <8; $x++) {
    $output = fread($myfile,2);
    if($x%2!=0) {
        echo $output;
    }
}
echo $output;
for($x = 0; $x <91; $x++) {
    $output = fread($myfile,3);
    if($x%2==0) {
        echo $output;
    }
}
fclose($myfile)
?>