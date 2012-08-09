<?php

/* berlinix, 2012/07/25
 * ISBN checksum algo
 *
 * ISBN EAN*UCC-组区号-出版者号-出版序号-效验码
 */

/* length of isbn: 13, here is 12 */
#$isbn = "978711526431";
$isbn = "978711526431";
$varr = "131313131313";

$len = strlen($isbn);
$sum = 0;
for($i = 0; $i < $len; ++$i) {
    $sum += intval($isbn[$i]) * intval($varr[$i]);
}

$sret = 10 - $sum % 10;

echo "$sret\n"

?>
