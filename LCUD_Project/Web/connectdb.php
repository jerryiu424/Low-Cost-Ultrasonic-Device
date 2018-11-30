<?php
// login info for local database
$dbhost = "localhost";
$dbuser= "root";
$dbpass = "group10";
$dbname = "group10";
// connect to database
$connection = mysqli_connect($dbhost, $dbuser,$dbpass,$dbname);
// error catch
if (mysqli_connect_errno()) {
 die("Database connection failed :" .
 mysqli_connect_error() . " (" . mysqli_connect_errno() . ")" );
 } //end of if statement
?>
