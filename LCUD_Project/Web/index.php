<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<!-- Creates the styles needed for the bar showing % Full -->

<html>
<style>
#myProgress {
	width: 25%;
	margin-left: 35%;
	background-color: #ddd;
	transform: rotate(-90deg);
	position: absolute;
	border-style: solid;
}

#myBar {
	width: 1%;
	margin-left: 0%;
	height: 300px;
	background-color: #4CAF50;
	rotation: 90deg;
	border-style: solid;
	border-width: 0px 1px 0px 0px;
	border-color: #006400;
}

</style>
  <!-- Downloads relevant content needed-->
  <head>
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">
  <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
  <script src="http://code.jquery.com/jquery-latest.js" ></script> 
  <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
  
	<script type="text/javascript" >
	<!-- Creates an interval to refresh data on screen without refreshing page -->
	setInterval("refreshContent();", 5000);
	<!-- Reloads content on page based on id of content and inner content, also refreshes graph with move()-->
	function refreshContent() {
		$('#content').load(location.href + ' #innerContent');
		move();
		
	}
	</script>
	<!-- move() sets the green bar to correct percentage -->
	<script> function move() { 
	var elem = document.getElementById("myBar");
	var width = 1; 
	var id = setInterval(frame(), 10);
	function frame() { 
	  <!-- Gets the value of the percentfull from the page and cnverts to number -->
	  var percent = document.getElementById("percent").innerHTML;
	  if(width >= 100) { 
	    clearInterval(id); 
	  } else { 
	    width = parseFloat(percent);
	    elem.style.width = width + '%'; 
	  } 
	} 
      }
  </script>  
  <meta content="text/html;charset=ISO-8859-1" http-equiv="Content-Type">
  <title>LCUD</title>

  <style type="text/css"></style>
  
  <link rel="icon" href="favicon.ico">

</head>

<body style="color: black; background-color: rgb(229, 229, 229); background-image: url(images/bg.jpg);" alink="#000099" link="#000099" vlink="#a700a7">
<br>
<a href="Group&#32;10.html"><img style="border: 0px solid ; width: 86px; height: 25px;" name="GI" alt="Group Info" title="Group Info" src="images/GI1.png" onmouseover="document.GI.src='images/GI2.png'" onmouseup="document.GI.src='images/GI1.png'" onmouseout="document.GI.src='images/GI1.png'"></a><br>

<!-- Creates table that shows the sensor and its relevant data -->
<div style="text-align: center;"><big style="font-weight: bold;"><big><big><span style="font-family: Helvetica;">Low Cost Ultrasonic Device</span></big></big></big><br>
<table style="text-align: left; width: 963px; height: 48px; margin-left: auto; margin-right: auto;" border="1" cellpadding="2" cellspacing="2">
  <tbody>
    <tr>
      <td style="vertical-align: top; background-color: rgb(153, 255, 255); width: 471px; text-align: center;">
      <div style="background-color: white;"><span style="font-family: Helvetica;"><br><br><br><br>
Sensor Number: 1</span><br>
      <br><br><br><br>
      </div>
      </td>
      <!-- This connects to the database, and uses getdata.php to fetch data for table values-->
      <td style="vertical-align: top; text-align: center; background-color: rgb(153, 255, 255); width: 472px;">
      <div style="text-align: left; background-color: white;" id="content">
		<div id="innerContent" style="span:nth-child(odd) {background: #grey;}">
		  <!-- Data is pushed to database every 10s and is averaged before push, and data refreshes every 5s -->
		  <span style="font-family: Helvetica; margin:auto;"> <b>Database updated every 10s, data refreshes every 5s</b></span><br>      
		<?php
			include "connectdb.php";
 			include "getdata.php";
		?>
		</div>
      </div>
      </td>
      <br>
    </tr>
  </tbody>
</table>
<br>
<br>

<!-- Creates the bar to show a visual of the container current volume and total volume -->
<div class = "container">
  <div class = "row"> 
      <h2 style="margin-left: 43%;"><b>% Full</b></h2>
  </div>
  <div class = "row">
    <div class = "col"> 
      <div id = "graph">
	<div id = "graphContent">
	  <body onLoad="move()">
	  <br><br>
	  <div id="myProgress"><div id="myBar"></div></div><br>
	  </body>
	</div>
      </div>
    </div>
  </div>
</div>

</div>
<br>
<!-- Goes tio the form page to input a new container -->
<a href="./form.php"> <button type="button" class="btn btn-primary">Set up</button></a>
<br>

</body></html>
