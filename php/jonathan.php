<?php
$start = microtime(true);
$words = array();
$letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
for($i=0;$i<10000;$i++){
	$word = "";
	for($j=0;$j<4;$j++){
		$word .= substr($letters, rand(0,25), 1);
	}
	array_push($words, $word);
}
asort($words);
foreach($words as $word){
	file_put_contents("jonathan_output.txt", $word . "\n", FILE_APPEND);
}
echo "Took " . (microtime(true) - $start) . "s to finish";
?>