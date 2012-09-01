<?php

$p2 = "/codes/php/file.ext";
$p3 = "codes/php/file.ext";
$p4 = "./file.ext";

echo "PATHINFO_DIRNAME of $p2: ".pathinfo($p2, PATHINFO_DIRNAME)."\n";
echo "PATHINFO_DIRNAME of $p3: ".pathinfo($p3, PATHINFO_DIRNAME)."\n";
echo "PATHINFO_DIRNAME of $p4: ".pathinfo($p4, PATHINFO_DIRNAME)."\n";
echo "PATHINFO_BASENAME of $p2: ".pathinfo($p2, PATHINFO_BASENAME)."\n";
echo "basename() of $p2: ".basename($p2)."\n";
echo "PATHINFO_EXTENSION of $p2: ".pathinfo($p2, PATHINFO_EXTENSION)."\n";
echo "PATHINFO_FILENAME of $p2: ".pathinfo($p2, PATHINFO_FILENAME)."\n";

echo "basename() of $p2: ".basename($p2, ".ext")."\n";

?>
