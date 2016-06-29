<?php
require_once('Weapon.class.php');

abstract class Ship
{
	private $_direction_ok;
	use Weapon;

	function shoot($enemy_ship)
	{
		$_direction_ok = 0;
		$distx = $this->getX() - $enemy_ship->getX();
		$disty = $this->getY() - $enemy_ship->getY();
		$distx = abs($distx);
		$disty = abs($disty);
		$range = $this->getRange();
		if ($this->getDirection() == 'up' && $this->getY() > $enemy_ship->getY() && $this->getX() == $enemy_ship->getX() && $range >= $disty)
			$_direction_ok = 1;
		if ($this->getDirection() == 'down' && $this->getY() < $enemy_ship->getY() && $this->getX() == $enemy_ship->getX() && $range >= $disty)
			$_direction_ok = 1;
		if ($this->getDirection() == 'left' && $this->getX() > $enemy_ship->getX() && $this->getY() == $enemy_ship->getY() && $range >= $distx)
			$_direction_ok = 1;
		if ($this->getDirection() == 'right' && $this->getX() < $enemy_ship->getX() && $this->getY() == $enemy_ship->getY() && $range >= $distx)
			$_direction_ok = 1;
		if($_direction_ok)
		{
			$tmp = $this->getCharge();
			if ($enemy_ship->getShield() > 0)
				while ($tmp > 0)
				{
					$enemy_ship->setShield( $enemy_ship->getShield() - 1 );
					$tmp--;
					if ($enemy_ship->getShield() <= 0)
						break;
				}
			while ($tmp > 0)
			{
				$enemy_ship->setHealth( $enemy_ship->getHealth() - 1 );
				$tmp--;
				if ($enemy_ship->getHealth() <= 0)
					break;
			}
		}
		return $range;
	}

	function moveup($enemy_ship)
	{
		if ($this->getY() - $this->getSpeed() > $enemy_ship->getY() ||
		   	$this->getY() < $enemy_ship->getY() || $enemy_ship->getX() != $this->getX())
				$this->setY( $this->getY() - $this->getSpeed() );
		else
			$this->setY( $enemy_ship->getY() + 1);

		$this->setDirection( "up" );
	}

	function movedown($enemy_ship)
	{
		if ($this->getY() + $this->getSpeed() < $enemy_ship->getY() ||
			$this->getY() > $enemy_ship->getY() || $enemy_ship->getX() != $this->getX())
			$this->setY( $this->getY() + $this->getSpeed() );
		else
			$this->setY( $enemy_ship->getY() - 1);
		$this->setDirection( "down" );
	}

	function moveleft($enemy_ship)
	{
		if ($this->getX() - $this->getSpeed() > $enemy_ship->getX() ||
		   	$this->getX() < $enemy_ship->getX() || $enemy_ship->getY() != $this->getY())
				$this->setX( $this->getX() - $this->getSpeed() );
		else
			$this->setX( $enemy_ship->getX() + 1);
		$this->setDirection( "left" );
	}

	function moveright($enemy_ship)
	{
		if ($this->getX() + $this->getSpeed() <  $enemy_ship->getX() ||
		   	$this->getX() > $enemy_ship->getX() || $enemy_ship->getY() != $this->getY())
				$this->setX( $this->getX() + $this->getSpeed() );
		else
			$this->setX( $enemy_ship->getX() - 1);
		$this->setDirection( "right" );
	}

	function destructed()
	{
		if ($this->getHealth() <= 0)
			return 1;
		if ($this->getY() > 99 || $this->getY() < 0 || $this->getX() > 149 || $this->getX() < 0)
			return 1;
		return 0;
	}

	// GETTERS

	function getName()
	{
		return $this->_name;
	}

	function getX()
	{
		return $this->_x;
	}

	function getY()
	{
		return $this->_y;
	}

	function getDirection()
	{
		return $this->_direction;
	}

	function getSprite()
	{
		return $this->_sprite;
	}

	function getHealth()
	{
		return $this->_health;
	}

	function getShield()
	{
		return $this->_shield;
	}

	function getSpeed()
	{
		return $this->_speed;
	}

	// SETTERS

	function setX( $x )
	{
		$this->_x = $x;
	}

	function setY( $y )
	{
		$this->_y = $y;
	}

	function setDirection( $direction )
	{
		$this->_direction = $direction;
	}

	function setHealth( $health )
	{
		$this->_health = $health;
	}

	function setShield( $shield )
	{
		$this->_shield = $shield;
	}

	public static function doc()
	{
		echo file_get_contents("Ship.doc.txt");
	}
}
?>
