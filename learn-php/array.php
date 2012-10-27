<?php

$arr = [1 => "Washington", "Adams", "Honest" => "Lincoln", "Jefferson"];
$arr = [-1 => "George II", "George III", "Washington"];

$arr = ["hello", "world"];
@$arr[2];

$arr = ["red", "large"];
list($color, $size) = $arr;
echo "$color, $size\n";

$arr = ["Nike", "red", "large", "location" => "Beijing"];
list($brand, ,$size) = $arr;
echo "$brand, $size\n";

unset($arr[0]);
unset($arr["location"]);

var_dump($arr);

?>
