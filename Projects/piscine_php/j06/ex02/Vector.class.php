<?php
require_once 'Vertex.class.php';
class Vector
{
	static $verbose = false;
	private $_x = 0.0;
	private $_y = 0.0;
	private $_z = 0.0;
	private $_w = 0.0;
	
	function __construct(array $coord)
	{
		if (array_key_exists('dest', $coord) && array_key_exists('orig', $coord))
		{
			$this->_x = $coord['dest']->getX() - $coord['orig']->getX();
			$this->_y = $coord['dest']->getY() - $coord['orig']->getY();
			$this->_z = $coord['dest']->getZ() - $coord['orig']->getZ();
			$this->_w = $coord['dest']->getW() - $coord['orig']->getW();
		}
		if (self::$verbose)
			print($this  . " constructed" . PHP_EOL);
	}

	function __toString()
	{
		return sprintf("Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f )", $this->_x, $this->_y, $this->_z, $this->_w);
	}

	function doc()
	{
		return file_get_contents("Vector.doc.txt");
	}

	function getX()
	{
		return $this->_x;
	}

	function getY()
	{
		return $this->_y;
	}

	function getZ()
	{
		return $this->_z;
	}

	function getW()
	{
		return $this->_w;
	}

	function magnitude()
	{
		return sqrt(pow($this->_x, 2) + pow($this->_y, 2) + pow($this->_z, 2) + pow($this->_w, 2));
	}

	function normalize()
	{
		$tmp = clone $this;
		$tmp->_x /= $tmp->magnitude();
		$tmp->_y /= $tmp->magnitude();
		$tmp->_z /= $tmp->magnitude();
		$tmp->_w /= $tmp->magnitude();
		return $tmp;
	}

	function add( Vector $rhs )
	{
		$tmp = clone $this;
		$tmp->_x += $rhs->getX();
		$tmp->_y += $rhs->getY();
		$tmp->_z += $rhs->getZ();
		$tmp->_w += $rhs->getW();
		return $tmp;
	}

	function sub( Vector $rhs )
	{
		$tmp = clone $this;
		$tmp->_x -= $rhs->getX();
		$tmp->_y -= $rhs->getY();
		$tmp->_z -= $rhs->getZ();
		$tmp->_w -= $rhs->getW();
		return $tmp;
	}

	function opposite()
	{
		$tmp = clone $this;
		$tmp->_x *= -1;
		$tmp->_y *= -1;
		$tmp->_z *= -1;
		$tmp->_w *= -1;
		return $tmp;
	}

	function scalarProduct( $k )
	{
		$tmp = clone $this;
		$tmp->_x *= $k;
		$tmp->_y *= $k;
		$tmp->_z *= $k;
		$tmp->_w *= $k;
		return $tmp;
	}

	function dotProduct( Vector $rhs )
	{
		return $this->_x * $rhs->_x + $this->_y * $rhs->_y + $this->_z * $rhs->_z + $this->_w * $rhs->_w;
	}

	function cos( Vector $rhs )
	{
		return $this->dotProduct($rhs) / sqrt($rhs->magnitude() * $this->magnitude());
	}

	function crossProduct( Vector $rhs )
	{
		$tmp = clone $this;
		$tmp->_x = $tmp->_y * $rhs->_z - $tmp->_z * $rhs->_y;
		$tmp->_y = $tmp->_z * $rhs->_x - $tmp->_x * $rhs->_z;
		$tmp->_z = $tmp->_x * $rhs->_y - $tmp->_y * $rhs->_x;
		return $tmp;
	}

	private function __clone()
	{
	}

	function __destruct()
	{
		if (self::$verbose == true)
			print($this . " destructed" . PHP_EOL);
	}
}

// $vtxO = new Vertex( array( 'x' => 0.0, 'y' => 0.0, 'z' => 0.0 ) );
// $vtxX = new Vertex( array( 'x' => 1.0, 'y' => 3.0, 'z' => 4.0 ) );
// $vtcXunit = new Vector( array( 'orig' => $vtxO, 'dest' => $vtxX ) );

// print ($vtcXunit);

?>