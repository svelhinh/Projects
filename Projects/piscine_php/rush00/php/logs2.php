<?php
 $data = unserialize(file_get_contents("../data/log"));
date_default_timezone_set('Europe/Paris');
// print_r($data);
foreach ($data as $key)
{
  foreach ($key as $val)
    echo $val;
     for($i = 0; $val[2][$i]; $i++)
        echo $val[2][$i];
}
?>
