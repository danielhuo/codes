<?php

$ck = tempnam("/tmp", "CURLCOOKIE");

$ch = curl_init("http://www.douban.com");
curl_setopt($ch, CURLOPT_COOKIEJAR, $ck);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
curl_exec($ch);

?>
