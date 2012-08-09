<?php

/* bailing, 2012/08/09 */

$s = "300(Ocean Shipping 100)";                     /* extract 100 from string */
echo preg_replace("/\(.*\)/", "", $s)."\n";         /* output: 300 */
echo preg_replace("/\d/", "", $s)."\n";             /* output: (Ocean Shipping ) */
echo preg_replace("/ \d+\)/", "", $s)."\n";         /* output: 300(Ocean Shipping */
echo preg_replace("/\d+\([^\d]* (\d+)\)/", "\${1}", $s)."\n";         /* output: 100, here!! */

if(preg_match("/ \d+\)/", $s, $matches) == 1) {
    echo trim($matches[0], " )")."\n";              /* output: 100 */
}

$parts = preg_split("/ /", $s);
echo trim($parts[count($parts) - 1], ")")."\n";     /* output: 100 */

$parts = explode(" ", $s);
echo trim($parts[count($parts) - 1], ")")."\n";     /* output: 100 */

$s = "link to http://www.berlinix.com/.";
echo preg_replace("/http:\/\/(.*)\//", "<a href=\"\${0}\">\${0}</a>", $s)."\n";


?>
