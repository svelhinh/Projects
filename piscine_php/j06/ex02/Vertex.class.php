<?php
require_once 'Color.class.php';
class Vertex
{
	static $verbose = false;
	private $_x = 0.0;
	private $_y = 0.0;
	private $_z = 0.0;
	private $_w = 1.0;
	private $_color;
	
	function __construct(array $coord)
	{
		if (array_key_exists('x', $coord))
			$this->_x = $coord['x'];
		if (array_key_exists('y', $coord))
			$this->_y = $coord['y'];
		if (array_key_exists('z', $coord))
			$this->_z = $coord['z'];
		if (array_key_exists('w', $coord))
			$this->_w = $coord['w'];
		if (array_key_exists('color', $coord))
			$this->_color = $coord['color'];
		else
			$this->_color = new Color(array('red' => 255, 'green' => 255, 'blue' => 255));
		if (self::$verbose)
			print($this . " constructed" . PHP_EOL);
	}

	function doc()
	{
		return file_get_contents("Vertex.doc.txt");
	}

	function getX()
	{
		return $this->_x;
	}

	function setX($x)
	{
		$this->_x = $x;
	}

	function getY()
	{
		return $this->_y;
	}

	function setY($y)
	{
		$this->_y = $y;
	}

	function getZ()
	{
		return $this->_z;
	}

	function setZ($z)
	{
		$this->_z = $z;
	}

	function getW()
	{
		return $this->_w;
	}

	function setW($w)
	{
		$this->_w = $w;
	}

	function getColor()
	{
		return $this->_color;
	}

	function setColor($color)
	{
		$this->_color = $color;
	}

	function __toString()
	{
		if (self::$verbose)
			return sprintf('Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, ', $this->_x, $this->_y, $this->_z, $this->_w) . $this->_color . ' )';
		else
			return sprintf('Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f )', $this->_x, $this->_y, $this->_z, $this->_w);
	}

	function __destruct()
	{
		if (self::$verbose == true)
			print($this . " destructed" . PHP_EOL);
	}
}

?>