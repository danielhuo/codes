<?php

date_default_timezone_set('Asia/Chongqing');
echo strftime("%Y-%m-%d %H:%M:%S", filectime("/home/bailing/.vimrc"))."\n";
echo strftime("%Y-%m-%d %H:%M:%S", fileatime("/home/bailing/.vimrc"))."\n";
echo strftime("%Y-%m-%d %H:%M:%S", filemtime("/home/bailing/.vimrc"))."\n";
echo strftime("%Y-%m-%d %H:%M:%S", filectime($_SERVER["PHP_SELF"]))."\n";

?>
