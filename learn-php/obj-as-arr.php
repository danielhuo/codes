<?php

/*
 * berlinix, 2012/06/29
 * treat PHP object as array
 */

class person {
    var $name;
    var $age;

    private $email;
    protected $location;

    /* access all properties, include private & protected */
    function as_arr() {
        foreach($this as $k => $v) {
            echo "$k => $v\n";
        }
    }
}

$p = new person;
$p->name = "berlinix";
$p->age = 27;

/* iterate all public properties */
foreach($p as $k => $v) {
    echo "$k => $v\n";
}

$p->as_arr();

var_dump($p);

?>
