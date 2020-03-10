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
        // Create error variables
        $nameErr = $ageErr = "";
        // Create value variables
        $name = $age = "";
    ?>
    <a href="search_people.html">Search People</a>
    <a href="insert_data.php">Insert People</a>
    <a href="index.php">Home</a>
    <?php
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            // This part is responsible for validating the form
            $isValid = true;
            function test_input($data) { // Used to validate the input for any harmful character
                $data = trim($data);
                $data = stripslashes($data);
                $data = htmlspecialchars($data);
                return $data;
            }
            if(empty($_POST["name"])) {
                $nameErr = "Name cannot be empty";
                $isValid = false;
            } else {
                $name = test_input($_POST["name"]);
                // preg_match is to match regular expression with string
                if(preg_match("/[0-9]/",$name)) {
                    $nameErr = "Name cannot contain digits";
                    $isValid = false;
                } else {
                    $nameErr = "";
                }
            }
            if(empty($_POST["age"])) {
                $ageErr = "Age cannot be empty";
                $isValid = false;
            } else {
                $age = test_input($_POST["age"]);
                if(preg_match("/[A-Za-z]/",$age)) {
                    $ageErr = "Age cannot contain alphabets";
                    $isValid = false;
                } else {
                    $ageErr = "";
                }
            }
            if($isValid) {
                // Write SQL Query to insert into table
                // Query should be 
                // INSERT INTO user(name,age) VALUES ('Sid', 10)
                // To get the quotes around sid we use '".$name."'
                $sql = "INSERT INTO user(name,age) VALUES ('".$name."', ".$age.")";
                if ($conn->query($sql) === TRUE) {
                    echo "New record created successfully";
                } else {
                    echo "Error: " . $sql . "<br>" . $conn->error;
                }
            }
        }
    ?>
    <form name="user_create" action=insert_data.php method="post">
        <?php echo $nameErr ?>
        Name : <input type="text" name="name" value=<?php echo $name ?> >
        <?php echo $ageErr ?>
        Age : <input type="text" name="age" value=<?php echo $age ?> >
        <input type="submit" value="submit">
    </form>
</body>
</html>