<?php
include("connect.php");

$link=Connection();

mysqli_query($link,"SET NAMES UTF8");

$temp=$_POST["temperature"];
$hum=$_POST["humidity"];
$wat=$_POST["water"];
$search=mysqli_query("select * from plandata where plant ='S01'");
$numb =mysqli_num_rows($search);

if($numb>0){
    $query = "UPDATE plandata SET water = '$wat' AND temerture = '$temp' AND humidity = '$hum' WHERE plant ='S01'";
}else{
    $query = "INSERT INTO plandata (id,plant,water,temerature,humidity) VALUES ('mis20418','S010,'.$wat.','.$temp.','.$hum')";
}


//增加  資料表 (欄位)  值

mysqli_query($query,$link);
mysqli_close($link);


?>