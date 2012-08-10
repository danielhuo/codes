<?php

/* bailing, 2012/08/10,
 * learn php singleton design pattern
 */

class sprice
{
    private static $inst;

    private function __construct()
    {
        echo "construct of sprice";
    }

    public static function singleton()
    {
        if(!isset(self::$inst)) {
            $c = __CLASS__;
            self::$inst = new $c;
        }
        return self::$inst;
    }

    public function countries()
    {
        echo "get all countries";
    }

    public function __clone()
    {
        trigger_error("Clone is not allowed!", E_USER_ERROR);
    }
}

echo "* start\n";
$sp = sprice::singleton();
echo "\n* get singleton done(create object at the first use space)\n";
$sp->countries();

echo "\n--------------------\n";

$sp2 = sprice::singleton();
assert($sp == $sp2);

//$sp2 = clone $sp;   // error here

?>
