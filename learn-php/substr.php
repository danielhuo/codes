<?php

$arr = array("site" => "berlinix's website",
            "age" => 1.5);

$pbody = "";
foreach($arr as $k => $v) {
    $pbody .= "$k=". urlencode($v) ."&";
}
$pbody = substr($pbody, 0, -1);
echo "$pbody\n";

?>
