<?php

$data = array(
    "name"  => "berlinix",
    "password"  => "basic@it",
    );

$pdata = "";
foreach($data as $k => $v) {
    $pdata .= "$k=" . urlencode($v) . "&";
}
$pdata = substr($pdata, 0, -1);

$url = "http://www.douban.com";
$ch = curl_init($url);
curl_setopt($ch, CURLOPT_POST, true);
/* switch between $data and $pdata, to see Content-Type feild */
curl_setopt($ch, CURLOPT_POSTFIELDS, $pdata);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, $data);
curl_setopt($ch, CURLOPT_VERBOSE, $data);

curl_exec($ch);

?>
