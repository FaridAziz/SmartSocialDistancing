<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class kirimdata extends Controller
{

    public function index()
    {
        $konek = mysqli_connect("localhost", "root", "", "smartsocialdistancing");
        
        if(isset( $_GET['pengunjung'])){
            echo "OK";
            $nilai = $_GET["pengunjung"]; 
            mysqli_query($konek, "update pengunjung set pengunjung = '$nilai'");
            echo $nilai;
        }else{
            echo "kaga OK";
        }
    }
}
