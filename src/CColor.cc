#include "CColor.h"
/*---------------------------------------------------------------------------*/
// constructors
CColor::CColor() 
: red(0), green(0), blue(0), alpha(0) { }

CColor::CColor(const double& r, const double& g, const double& b, const double& a)
: red(r), green(g), blue(b), alpha(a) {}

CColor::CColor(const CColor& c)
{
	*this = c;
}

/*---------------------------------------------------------------------------*/
// methods
/*void CColor::setRed(const double& i)
{
	red = i;
}

void CColor::setGreen(const double& i)
{
	green = i;
}

void CColor::setBlue(const double& i)
{
	blue = i;
}

void CColor::setAlpha(const double& i)
{
	alpha = i;
}*/

void CColor::setColor(const double& r, const double& g, const double& b, const double& a) 
{
	red = r;
	green = g;
	blue = b;
	alpha = a;
}

/*const double& CColor::getRed() const
{
	return red;
}

const double& CColor::getGreen() const

{
	return green;
}

const double& CColor::getBlue() const
{
	return blue;
}

const double& CColor::getAlpha() const
{
	return alpha;
}*/

/*---------------------------------------------------------------------------*/
// operators
CColor CColor::operator+(CColor& c) 
{
	double r = ( (this->red  +c.red  ) * 0.5 );
	double g = ( (this->green+c.green) * 0.5 );
	double b = ( (this->blue +c.blue ) * 0.5 );
	double a = ( (this->alpha+c.alpha) * 0.5 );
	
	CColor t(r,g,b,a);
	return t;
}

void CColor::operator+=(CColor& c) 
{
	this->red   = ( (this->red  +c.red  ) * 0.5 );
	this->green = ( (this->green+c.green) * 0.5 );
	this->blue  = ( (this->blue +c.blue ) * 0.5 );
	this->alpha = ( (this->alpha+c.alpha) * 0.5 );
}

/*---------------------------------------------------------------------------*/
// external functions
CColor operator-(CColor& c) 
{
	double r = (1.0-c.red);
	double g = (1.0-c.green);
	double b = (1.0-c.blue);
	double a = (1.0-c.alpha);
	
	CColor t(r,g,b,a);
	return t;
}

ostream& operator<<(ostream& o, CColor& c) 
{
	o << "R:" << c.red << " G:" << c.green << " B:" << c.blue << " A:" << c.alpha;
	return o;
}

/*---------------------------------------------------------------------------*/
// EOF
