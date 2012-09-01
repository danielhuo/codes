<?php

$ck = tempnam("/tmp", "CURLCOOKIE");

function get_page($url, $ck)
{
    $ch = curl_init($url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($ch, CURLOPT_COOKIEJAR, $ck);
    $output = curl_exec($ch);
    $resp = curl_getinfo($ch);
    if($resp["http_code"] == 200) {
        return $output;
    }
    return false;
}

if(($page = get_page("http://www.zhihu.com", $ck))){
    if(preg_match('<input type="hidden" name="_xsrf" value="[^\"]*">', $page, $matches) === 1){
        $line = $matches[0];
        if(preg_match('/value="([^"]*)"/', $line, $matches) !== false) {
            $xsrf = $matches[1];
        }
    }
}

if(isset($xsrf)) {
    $ch = curl_init("https://www.zhihu.com/login");
    curl_setopt($ch, CURLOPT_COOKIEFILE, $ck);
    curl_setopt($ch, CURLOPT_VERBOSE, true);
    curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);  
    curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, false); 
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($ch, CURLOPT_POST, true);
    curl_setopt($ch, CURLOPT_VERBOSE, true);
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);

    $data = array(
        "email"     => "berlin860@gmail.com",
        "password"  => "darenshuohua",
        "_xsrf"     => $xsrf,
        );
    $pdata = "";
    foreach($data as $k => $v) {
        $pdata .= "$k=" . urlencode($v) . "&";
    }
    $pdata = substr($pdata, 0, -1);
        
    curl_setopt($ch, CURLOPT_POSTFIELDS, $pdata);

    $output = curl_exec($ch);
    $info = curl_getinfo($ch);

    var_dump($output);
}

?>
