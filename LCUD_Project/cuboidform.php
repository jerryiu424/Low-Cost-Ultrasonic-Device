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
<!-- Input Form for Cuboid -->
<body style="color: black; background-color: rgb(229, 229, 229); background-image: url(images/bg.jpg);" alink="#000099" link="#000099" vlink="#a700a7">
	<br><br><br><br>
	<p><b>Cuboid:</b></p>
	<div class="container">
  		<div class="row">
		<!-- Gets width, length, height in that order to POST -->
  		<form action="./cuboidformText.php" method="POST" enctype="multipart/form-data">
  		<label><b>Width:</b></label>
  		<input type="number" step="any" name="width" id="width"/>
  		<label><b>Length:</b></label>
  		<input type="number" step="any" name="length" id="length"/>
  		<label><b>Height:</b></label>
  		<input type="number" step="any" name="height" id="height"/>
  		<input type="submit" value="submit"/>
		<!-- Return to form.php -->
		<p><a href="./form.php"> <button type="button" class="btn btn-primary">Go Back</button></a></p>
  		</form>
		</div>
	</div>
</body>
</html>

