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
    $q = $_REQUEST["q"]; // Query passed from the html file
    $sql = "SELECT * from user WHERE name='".$q."'";
    $result = $conn->query($sql);
    if ($result->num_rows > 0 && strlen($q)!==0) {
        // check if there is an entry with the same string as that passed by the html file
        while($row = $result->fetch_assoc()) {
            $name = $row["name"];
            $age = $row["age"];
            echo "<table>
                <tr>
                    <th>Name</th>
                    <th>Age</th>
                </tr>
                <tr>
                    <td>".$name."</td>
                    <td>".$age."</td>
                </tr>
            </table>";
        }
    }
?>