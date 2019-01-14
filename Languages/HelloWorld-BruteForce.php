<?php

$hash = md5("HelloWorld");

bruteForce("", 10);

function bruteForce(string $prev, int $len){
	for($i = ord('A'), $iMax = ord('z'); $i <= $iMax; $i++){
		$str = $prev . chr($i);
		if($len > 1){
			bruteForce($str, $len - 1);
		}else{
			if(md5($str) === $hash){
				echo $str;
				exit(0);
			}
		}
	}
}
