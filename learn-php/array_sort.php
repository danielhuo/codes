<?php

/* bailing, 2012/08/23
 * learn array_multisort()
 */

/* sort simple array */

$a = array(
    "United States" => 10,
    "China" => 5,
    "Brazil" => 12,
    "Japan" => 4,
    );

function print_a(&$a) {
    foreach($a as $k => $v) {
        echo "$k, $v\n";
    }
}

echo "----------\n";
array_multisort($a);
print_a($a);

echo "----------\n";
array_multisort($a, SORT_DESC);
print_a($a);

echo "----------\n";
$cnts = array_values($a);
array_multisort($cnts, SORT_DESC, $a);
print_a($a);

/* sort array */

$a = array(
    array("user" => "bailing", "age" => 27),
    array("user" => "taoqi", "age" => 2.5),
    array("user" => "berlinix", "age" => 2.3),
    array("user" => "tbring", "age" => 1.5),
    );

$ages = array();
foreach($a as $row) {
    $ages []= $row["age"];
}

echo "----------\n";
array_multisort($ages, SORT_DESC, $a);
print_r($a);


?>
