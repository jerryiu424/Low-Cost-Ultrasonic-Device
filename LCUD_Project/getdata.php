<?php
// Queries the databse for the latest entry
$query = "SELECT * FROM sensor WHERE datetime = (SELECT MAX(datetime) FROM sensor)";

$result = mysqli_query($connection, $query);

if(!$query){
	die("database query failed");
}
else {
	// Fetches the row for the result
	$row = mysqli_fetch_assoc($result);
	// Each line echo's an associated data value form the database
	echo "<span style=\"font-family: American Typewriter;\"> <b>Duration: </b>" . $row['duration'] . " ms</span><br>";
	echo "<span style=\"font-family: American Typewriter;\"> <b>Temperature: </b>" . $row['temperature'] . " &#176;C</span><br>";
	echo "<span style=\"font-family: American Typewriter;\"> <b>Distance: </b>" . $row['distance'] . " cm</span><br>";
	echo "<span style=\"font-family: American Typewriter;\"> <b>Volume: </b>" . $row['volume'] . " mL</span><br>";
	echo "<span style=\"font-family: American Typewriter;\"> <b>Current Level: </b>" . $row['level'] . " cm</span><br>";
	echo "<span style=\"font-family: American Typewriter;\"> <b>Percent Full: </b><span id = \"percent\">" . $row['percentfull'] . "</span> %</span><br>";
	echo "<span style=\"font-family: American Typewriter;\"> <b>Shape: </b>" . $row['shape'] . "</span><br>";
	echo "<span style=\"font-family: American Typewriter;\"> <b>Date and Time: </b>" . $row['datetime'] . "</span><br>";
}
?>
