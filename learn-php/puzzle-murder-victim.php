<?php

/* 
 * by berlinix, 20111130
 * puzzle detail: http://www.berlinix.com/puzzle_murder_victim_20111130.html 
 */

class person
{
    var $name;
    var $gender;
    var $pro;
    var $family;

    function __construct($n, $g, $p, $f)
    {
        $this->name = $n;
        $this->gender = $g;
        $this->pro = $p;
        $this->family = $f;
    }

    function is_male()   { return ($this->gender == "male" ? true : false); }
    function is_female() { return ($this->gender == "female" ? true : false); }
    function is_doctor() { return ($this->pro == "doctor" ? true : false); }
    function is_lawyer() { return ($this->pro == "lawyer" ? true : false); }
}

function same_gender($p1, $p2) { return ($p1->gender == $p2->gender ? true : false); }
function same_pro($p1, $p2) { return ($p1->pro == $p2->pro ? true : false); }
function same_family($p1, $p2) { return ($p1->family== $p2->family ? true : false); }
function same_person($p1, $p2) { return ($p1->name == $p2->name ? true : false); }

$Y = new person("Y", "male",   "doctor", "A");
$D = new person("D", "female", "doctor", "A");
$H = new person("H", "female", "lawyer", "A");

$L = new person("L", "female", "lawyer", "B");
$G = new person("G", "male",   "doctor", "B");
$W = new person("W", "male",   "lawyer", "B");

$all = array($Y, $D, $H, $L, $G, $W);
$total = count($all);

echo "<table>";
echo "<tr><th>M/V</th><th>Y</th><th>D</th><th>H</th><th>L</th><th>G</th><th>W</th></tr>";
for($i = 0; $i < $total; $i++) {        // $i is murder 
    $m = $all[$i];
    echo "<tr><th>", $m->name, "</th>";
    for($j = 0; $j < $total; $j++) {    // $j is victim
        $v = $all[$j];

        if(same_person($m, $v)) {       // skip
            echo "<td>x</td>";
            continue;
        }

        $tag = "";
        /* Judge-1 */
        if(same_family($m, $v)) {
            if($m->is_male()) {
                $tag .= "1";
            }
        } else {
            if($m->is_doctor()) {
                $tag .= "1";
            }
        }

        /* Judge-2 */
        if(same_pro($m, $v)) {
            if($v->is_male()) {
                $tag .= "2";
            }
        } else {
            if($v->is_female()) {
                $tag .= "2";
            }
        }

        /* Judge-3 */
        if(same_gender($m, $v)) {
            if($m->is_lawyer()) {
                $tag .= "3";
            }
        } else {
            if($v->is_doctor()) {
                $tag .= "3";
            }
        }

        /* output tag */
        if($tag == "123") {
            echo "<td style='color: red'>+</td>";
        } else {
            echo "<td>$tag</td>";
        }
    }
    echo "</tr>";
}
echo "</table>";
?>
