<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>CAT 2</title>
</head>
<body>
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
    ?>
    <a href="search_people.html">Search People</a>
    <a href="insert_data.php">Insert People</a>
    <a href="index.php">Home</a>
    <table>
        <tr>
            <th>Name</th>
            <th>Age</th>
        </tr>
        <?php
            $sql = "SELECT name, age FROM user";
            $result = $conn->query($sql);
            if ($result->num_rows > 0) {
                // output data of each row
                while($row = $result->fetch_assoc()) {
                    echo "<tr>";
                    echo "<td>".$row["name"]."</td>";
                    echo "<td>".$row["age"]."</td>";
                    echo "</tr>";
                }
            } else {
                echo "0 results";
            }
        ?>
    </table>
    <!-- GET A SPECIFIC USER -->
    <form name="spec">
        <select id="specific" name="specific" value="Choose an user" oninput="getInfoSpecific()">
        <?php
            $sql = "SELECT name, age FROM user";
            $result = $conn->query($sql);
            if ($result->num_rows > 0) {
                // output data of each row
                while($row = $result->fetch_assoc()) {
                    echo "<option value=".$row["name"].">".$row["name"]."</option>";
                }
            }
        ?>
        </select>
    </form>
    <div id="ele"></div>
<script>
    let str="";
    const ele = document.getElementById("ele")
    function getInfoSpecific(id) {
        str = document.forms["spec"]["specific"].value;
        sendRequest();
    }
    function sendRequest() {
        let xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            ele.innerHTML = this.responseText;
        }
        };
        xhttp.open("GET", "get_info.php?q="+str, true); // true means asynchronous false means synchronous
        xhttp.send();
    }
</script>
</body>
</html>