<?php

function get_url($url) 
{
    $ckfile = tempnam("/tmp", "CURLCOOKIE");

    $ch = curl_init();

    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows; U; Windows NT 5.1; rv:1.7.3) Gecko/20041001 Firefox/0.10.1");
    curl_setopt($ch, CURLOPT_COOKIEJAR, $ckfile);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
    curl_setopt($ch, CURLOPT_AUTOREFERER, true);
    curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
    curl_setopt($ch, CURLOPT_MAXREDIRS, 10);
    //curl_setopt($ch, CURLOPT_VERBOSE, true);
    //curl_setopt($ch, CURLOPT_POST, true);
    
    $content = curl_exec($ch);
    $resp = curl_getinfo($ch);

    curl_close($ch);

    if($resp["http_code"] == 301 or $resp["http_code"] == 302) {
        if($hreaders = get_headers($resp["url"])) {
            foreach($headers as $value) {
                if(substr(strtolower($value), 0, 9) == "location:") {
                    $location = trim(substr($value, 9, strlen($value)));
                    echo "Redirect to $location\n";
                    return get_url($location);
                }
            }
        }
    } else {
        return array($content, $resp);
    }
}



//
//$ch = curl_init();
//
//curl_setopt($ch, CURLOPT_URL, $url);
//curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
//curl_setopt($ch, CURLOPT_POST, true);
//
//$data = array(
//    "loginname" => "berlin860@gmail.com",
//    "password" => "darenshuohua",
//    );
//curl_setopt($ch, CURLOPT_POSTFIELDS, $data);
//
//$output = curl_exec($ch);
//$resp = curl_getinfo($ch);
//
//print_r($resp);

$url = "http://weibo.com";
$ch = curl_init($url);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
$output = curl_exec($ch);
$resp = curl_getinfo($ch);
print_r($resp);

?>
