#!/usr/bin/php
<?php

$fd = fopen('/var/run/utmpx', 'r');

while (!feof($fd))
	$data .= fgets($fd);
echo $data;
$tab = unpack("Z628", $data);
print_r($tab);

?>
