<!-- POSTs the data from input form to data.txt file for program use -->
<?php
		error_reporting(E_ALL);
		ini_set('display_errors',1);
		$data = $_POST['side'] . "\n";
		$data = "CUBE\n" . $data;
		$fp = file_put_contents("/home/pi/Desktop/group10/LCUD_Project/data.txt", $data, LOCK_EX);
		if($fp === false){
			die('Unable to open file');
		}
?>


<!DOCTYPE html>
<html>
<head>
	<!-- Downloads relevant content -->
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">
  	<script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
  	<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
  	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
  		
	<title>Set Up form</title>
</head>
<!-- Confirmation page for cube input -->
<body style="color: black; background-color: rgb(229, 229, 229); background-image: url(images/bg.jpg);" alink="#000099" link="#000099" vlink="#a700a7">
	<h1>Set up COMPLETE!</h1>
	<br><br><br><br>
	<!-- Return to index.php -->
	<p><a href="./index.php"> <button type="button" class="btn btn-primary">Go Back</button></a></p>
</body>
</html>
