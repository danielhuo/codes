<?php

$s = "abc";
$s2 = "汉字";

echo "strlen() of $s: ".strlen($s)."\n";
echo "strlen() of $s2: ".strlen($s2)."\n";
echo "mb_strlen() of $s with utf8 encode: ".mb_strlen($s2, "utf8")."\n";

?>
