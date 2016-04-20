<?php

class NightsWatch
{
	private $_fighter = array();

	function fight()
	{
		foreach ($this->_fighter as $value)
			$value->fight();
	}

	function recruit($f)
	{
		if ($f instanceof IFighter)
			array_push($this->_fighter, $f);
	}
}

?>