<?php
require_once('Ship.class.php');

class Explozer extends Ship
{
	protected $_name = "Explozer";
	protected $_x = 0;
	protected $_y = 0;
	protected $_direction = "down";
	protected $_sprite = "img/Explozer.png";
	protected $_health = 5;
	protected $_shield = 1;
	protected $_speed = 4;

	function __construct( array $coords )
	{
		$this->setX( $coords['x'] );
		$this->setY( $coords['y'] );
		$this->setDirection( $coords['direction'] );
	}

	public static function doc()
	{
		echo file_get_contents("Explozer.doc.txt");
	}
}
?>
