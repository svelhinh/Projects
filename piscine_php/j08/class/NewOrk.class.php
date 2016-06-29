<?php
require_once('Ship.class.php');

class NewOrk extends Ship
{
	protected $_name = "NewOrk";
	protected $_x = 0;
	protected $_y = 0;
	protected $_direction = "down";
	protected $_sprite = "img/NewOrk.gif";
	protected $_health = 5;
	protected $_shield = 2;
	protected $_speed = 14;

	function __construct( array $coords )
	{
		$this->setX( $coords['x'] );
		$this->setY( $coords['y'] );
		$this->setDirection( $coords['direction'] );
	}
	public static function doc()
	{
		echo file_get_contents("NewOrk.doc.txt");
	}
}
?>
