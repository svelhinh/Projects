#include "AHitBox.hpp"

AHitBox::AHitBox(void)
	: _x(0), _y(0), _h(0), _w(0)
{
}

AHitBox::AHitBox(int x, int y, int w, int h)
	: _x(x), _y(y), _h(h), _w(w)
{
}

AHitBox::AHitBox(AHitBox const & src)
{
	*this = src;
	return;
}

AHitBox::~AHitBox(void)
{
}

int AHitBox::getPosX(void) const
{
	return _x;
}

int AHitBox::getPosY(void) const
{
	return _y;
}

int AHitBox::getWidth(void) const
{
	return _w;
}

int AHitBox::getHeight(void) const
{
	return _h;
}

void AHitBox::setPosX(int x)
{
	_x = x;
}

void AHitBox::setPosY(int y)
{
	_y = y;
}

void AHitBox::setWidth(int w)
{
	_w = w;
}

void AHitBox::setHeight(int h)
{
	_h = h;;
}

AHitBox & AHitBox::operator = (AHitBox const & rhs)
{
	this->_x = rhs.getPosX();
	this->_y = rhs.getPosY();
	this->_w = rhs.getWidth();
	this->_h = rhs.getHeight();
	return *this;
}

bool AHitBox::collide(AHitBox const & obj) const
{
	if (getPosX() <= obj.getPosX() + obj.getWidth() - 1 &&
		obj.getPosX() <= getPosX() + getWidth() - 1 &&
		getPosY() <= obj.getPosY() + obj.getHeight() - 1 &&
		obj.getPosY() <= getPosY() + getHeight() - 1)
		return true;
	else
		return false;
}
