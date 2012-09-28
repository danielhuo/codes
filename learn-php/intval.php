<?php

echo intval(0.1*10)."\n";           // 1
echo intval(0.8*10)."\n";           // 8
echo intval((0.1+0.5)*10)."\n";     // 6
echo intval((0.1+0.6)*10)."\n";     // 7
echo intval((0.1+0.7)*10)."\n";     // 7, why?!!

echo "--\n";
function times_two(&$int) {
    $int = $int * 2;
}
$int = 2;
$result = times_two($int);
echo "$result\n";

echo "--\n";
$x = 2;
echo $x == 2 ? '我' : $x == 1 ? '你' : '它';    // why?

echo "--\n";
$x = 11;
printf("%d\n", printf("%d", printf("%d", $x)));

echo "--\n";
$a = 3; $b = 5;
if($a = 5 || $b = 7) { 
    $a++;
    $b++;
}
echo "$a $b\n";

echo "--\n";
echo -10%3;
echo "\n";

echo "--\n";
$arr = array(0 => 1, "aa"=> 2, 3, 4);
foreach($arr as $key => $val) {
    echo "key:$key:val:$val,";      // 1 => 3, 2 => 4 !!
    echo ($key == "aa" ? 5 : $val);
}
echo "\n";

echo "--\n";
if(0 == "aa") {
    echo "woo!\n";      // equal!
}

echo "--\n";
$num = "009d2ff4bfffe4f8";
echo base_convert($num, 16, 2)."\n";
echo strlen("10011101001011111111010010111111111111111110010011111000")."\n";   // 56
// 0000 0000 ....                                                               // 64
echo base_convert("010011", 2, 10)."\n";
echo "\n";

?>
