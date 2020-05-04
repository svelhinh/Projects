<?php

class Jaime
{
	function sleepWith($sleep)
	{
		if (get_class($sleep) == "Tyrion")
			print("Not even if I'm drunk !" . PHP_EOL);
		else if (get_class($sleep) == "Sansa")
			print("Let's do this." . PHP_EOL);
		elseif (get_class($sleep) == "Cersei")
			print("With pleasure, but only in a tower in Winterfell, then." . PHP_EOL);
	}
}

?>