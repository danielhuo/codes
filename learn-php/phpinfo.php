<?php

if(extension_loaded("gd") && function_exists("gd_info")){
    echo "gd supported\n";
    if(function_exists("imageftbbox")) {
        echo "gd imageftbbox() supported\n";
    }
}

?>
