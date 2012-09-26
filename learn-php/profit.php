<?php

$base = 300 * 12;   // year
$years = 20;        // 20 years

$total = 0;
$i = 0;
while($i < 20) {
    $total = intval($base * 1.09);
    echo "$i year total: $total\n";
    ++$i;
    $base = ($total + 300 * 12);
}
echo "\nEnd total: $total\n";

?>
