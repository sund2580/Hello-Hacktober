<?php
/* Desafio Soma PHPWomen - RJ */
function soma($A, $B){
	return $A - $B;
}

$A = $argv[1];
$B = $argv[2];
$X = $A - $B;

if ($A < $B){
	echo "Valor do A Menor do que B" ."\n"; 
	echo "A = ". $A ."\n"; 
	echo "B = ". $B ."\n";   
	echo "X = ". $X ."\n"; 
} else {  
	echo "X = ". $X ."\n"; 
}



