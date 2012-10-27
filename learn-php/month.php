<?php

function _year_months()
{
    $months = array();
    $idx = 0;
    while(++$idx < 13) {
        $months []= sprintf("%02d", $idx);
    }

    return $months;
}

?>
