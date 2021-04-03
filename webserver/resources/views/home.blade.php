@extends('layout/main')

@section('title', 'Web Monitoring')

@section('container')

<script type="text/javascript">
    $(document).ready(function(){
        setInterval(function(){
            $("#pengunjung").load('cek');
        }, 1000);
    });
</script>

<div class="container" style="text-align:center; padding-top:5%;">

    <h1> Jumlah pengunjung saat ini </h1>
    <div class="panel panel-default">
        <div class="panel-body">
            <p style="font-size:200px;">
                
                <span id="pengunjung"></span>
            </p>
        </div>
    </div>


</div>


@endsection