<?php
class Player
{
	private $ship;
	private $name;

	public function __construct( array $kwargs )
	{
		if (array_key_exists('name', $kwargs))
			$this->name = $kwargs['name'];
		if (array_key_exists('ship', $kwargs))
			$this->ship = $kwargs['ship'];
	}
	public static function doc()
	{
		echo file_get_contents("Player.doc.txt");
	}
	public function getName()
	{
		return $this->name;
	}
	public function getShip()
	{
		return $this->ship;
	}
	public function __toString()
	{
		return "<h4>" . $this->name . "<br /> <p class='health'>Health : " . $this->ship->getHealth() .
		"<br />Shield : " . $this->ship->getShield() . "</p></h4><img src='" . $this->ship->getSprite() . "' title='"
		. $this->ship->getName() . "' />";
	}
}
?>