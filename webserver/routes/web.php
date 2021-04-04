<?php

use Illuminate\Support\Facades\Route;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/', function () {
    return view('home');
});

Route::get('/cek', function () {
    return view('CekPengunjung');
});

// Route::get('/kirimdata', function () {
//     return view('kirimdata');
// });


Route::get('/kirimdata', 'App\Http\Controllers\kirimdata@index');

