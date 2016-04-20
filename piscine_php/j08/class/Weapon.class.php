<?php
trait Weapon
{
	private $_rangeShort = 1;
	private $_rangeMedium = 2;
	private $_rangeMax = 15;
	private $_charge = 2;

	function getRange()
	{
		$D = rand(1, 6);
		if ($D == 6)
			return $this->_rangeMax;
		else if ($D >= 4)
			return $this->_rangeMedium;
		else
			return $this->_rangeShort;
	}
	function getCharge()
	{
		return $this->_charge;
	}

	public static function doc()
	{
		echo file_get_contents("Weapon.doc.txt");
	}
}
?>
