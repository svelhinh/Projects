<?php

class Color
{
	static $verbose = false;
	public $red = 0;
	public $green = 0;
	public $blue = 0;

	function __construct(array $kwargs)
	{
		if (array_key_exists('red', $kwargs))
			$this->red = intval($kwargs['red']);
		if (array_key_exists('green', $kwargs))
			$this->green = intval($kwargs['green']);
		if (array_key_exists('blue', $kwargs))
			$this->blue = intval($kwargs['blue']);
		if (array_key_exists('rgb', $kwargs))
		{
			$this->red = (intval($kwargs['rgb']) >> 16) % 256;
            $this->green = (intval($kwargs['rgb']) >> 8) % 256;
            $this->blue = intval($kwargs['rgb']) % 256;
		}
		if (self::$verbose == true)
			print($this . " constructed." . PHP_EOL);
	}


	function __toString()
	{
		return sprintf('Color( red: %3d, green: %3d, blue: %3d )', $this->red, $this->green, $this->blue);
	}

	static function doc()
	{
		return file_get_contents("Color.doc.txt");
	}

	function add(Color $kwargs)
	{
		$resultat = new Color(array('red' => $this->red + $kwargs->red, 'green' => $this->green + $kwargs->green, 'blue' => $this->blue + $kwargs->blue));
		return $resultat;
	}

	function sub(Color $kwargs)
	{
		$resultat = new Color(array('red' => $this->red - $kwargs->red, 'green' => $this->green - $kwargs->green, 'blue' => $this->blue - $kwargs->blue));
		return $resultat;
	}

	function mult($factor)
	{
		$resultat = new Color(array('red' => $this->red * $factor, 'green' => $this->green * $factor, 'blue' => $this->blue * $factor));
		return $resultat;
	}

	function __destruct()
	{
		if (self::$verbose == true)
			print($this . " destructed." . PHP_EOL);
	}
}

?>