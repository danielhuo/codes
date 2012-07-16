<?php

$arr = array("berlinix", "male");
list($name, $gender) = $arr;
echo "name: $name, gender: $gender ";

$arr = array("age" => 27, "website" => "www.berlinix.com");
foreach($arr as $key => $val) { $$key = $val; }
echo "age: $age, website: $website ";

?>
