<?php

function Connection(){

    $server="127.0.0.1";    //主機
    $user="root";           //帳號
    $pass="";               //密碼
    $db="plantdb";         //資料庫

    $connection = mysqli_connect($server, $user, $pass,$db)  or die ("連接失敗錯誤訊息".mysqli_connect_error());

    mysqli_query($connection,"SET NAMES UTF8");

    return $connection;
}

?>