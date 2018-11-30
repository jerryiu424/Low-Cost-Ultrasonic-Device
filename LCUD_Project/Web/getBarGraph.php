<style>
    #myProgress {
      width: 100%;
      background-color: #ddd;
       transform: rotate(-90deg);
      
    }
    
    #myBar {
      width: 1%;
      height: 300px;
      background-color: #4CAF50;
     rotation: 90deg;
    
    }
    </style>

<?php

$query = "SELECT * FROM sensor WHERE datetime = (SELECT MAX(datetime) FROM sensor)";

$result = mysqli_query($connection, $query);

if(!$query){
	die("database query failed");
}
else {
    $row = mysqli_fetch_assoc($result);
    
	
	
?>