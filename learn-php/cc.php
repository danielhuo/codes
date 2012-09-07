<?php

/* bailing, 2012/09/07
 * Credit Card 
 */

function is_valid($cc)
{
    $s = "";
    for($i = 0; $i < strlen($cc); ++$i) {
        if($i % 2 == 0) {
            $s .= strval(intval($cc[$i]) * 2);
        } else {
            $s .= $cc[$i];
        }
    }

    $cnt = 0;
    for($i = 0; $i < strlen($s); ++$i) {
        $cnt += intval($s[$i]);
    }

    return (($cnt % 10 == 0) ? true : false);
}

$ccs = array(
    "5187188380397866",
    "4013735633800642",
    "4392258004580033",
    "5187107512294767",
    );
foreach($ccs as $cc) {
    echo "check: $cc ". intval(is_valid($cc)) . "\n";
}

?>
