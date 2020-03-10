<?php
    // Constants in php
    define("servername", "localhost");
    define("username", "root");
    $password = ""; // Alternative way
    define("db","testdb");
    // Establishing connectivity
    $conn = mysqli_connect(constant("servername"), constant("username"), $password, constant("db"));
    // Check connection
    if (!$conn) {
        die("Connection failed: " . mysqli_connect_error());
    }
    $sql = "SELECT * from user";
    $q = $_REQUEST["q"]; // Query passed from the html file
    $result = $conn->query($sql);
    $person = false;
    if ($result->num_rows > 0 && strlen($q)!==0) {
        // check if there is an entry with the same string as that passed by the html file
        while($row = $result->fetch_assoc()) {
            $cur = $row["name"];
            $len = strlen($q);
            $substr = substr($cur,0,$len);
            if(strcmp($substr,$q) == 0) {
                echo $cur;
                $person = true;
                break;
            }
        }
    }
    if(!$person) {
        echo "No suggestions";
    }
?>