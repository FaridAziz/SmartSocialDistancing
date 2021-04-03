<?php 
    $konek = mysqli_connect("localhost", "root", "", "smartsocialdistancing");

    $sql = mysqli_query($konek, "select * from pengunjung");
    $data = mysqli_fetch_array($sql);
    $nilai = $data["pengunjung"];

    echo $nilai;

?>