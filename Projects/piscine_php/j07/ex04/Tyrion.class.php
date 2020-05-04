<?php

class Tyrion
{
	function sleepWith($sleep)
	{
		if (get_class($sleep) == "Jaime" || get_class($sleep) == "Cersei")
			print("Not even if I'm drunk !" . PHP_EOL);
		else if (get_class($sleep) == "Sansa")
			print("Let's do this." . PHP_EOL);
	}
}

?>