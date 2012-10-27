<?php

$arr = array(1, 2, 3);
echo "use @\$arr[]\n";
@$arr[5];
echo "\nnot use @\$arr[]\n";
$arr[5];

?>
