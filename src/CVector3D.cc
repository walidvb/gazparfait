#include "CVector3D.h"

//Constructors    -------------------------------------


CVector3D::CVector3D()
: x(0), y(0), z(0) {}

CVector3D::CVector3D(double x, double y, double z)
: x(x), y(y), z(z) {}

CVector3D::CVector3D(  CVector3D const& v) {
	*this = v;
}


//get&set methods -------------------------------------

void CVector3D::getCoords(double& x, double& y, double& z) const
{
	x = this->x;
	y = this->y;
	z = this->z;
}

double CVector3D::getX() const
{
	return this->x;
}

double CVector3D::getY() const
{
	return this->y;
}

double CVector3D::getZ() const
{
	return this->z;
}

double CVector3D::getNorm() const
{ 
	double norme(x*x + y*y + z*z);
	return norme;
}

CVector3D CVector3D::normalize()
{
	return (*this)/sqrt(getNorm());
}

void CVector3D::setCoords(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void CVector3D::setX(double x){
	this->x = x;
}

void CVector3D::setY(double y){
	
	this->y = y;
}

void CVector3D::setZ(double z){
	
	this->z = z;
}
/*---------------------------------------------------------------------------*/
// internal operators
CVector3D CVector3D::operator+(const CVector3D& v) const
{
	double x,y,z;
	v.getCoords(x,y,z);
	return CVector3D( (this->x+x),(this->y+y),(this->z+z) );
}


CVector3D CVector3D::operator-(const CVector3D& v) const
{
	double x,y,z;
	v.getCoords(x,y,z);
	
	return CVector3D( (this->x-x),(this->y-y),(this->z-z) );
}

CVector3D CVector3D::operator*(const double& d) const
{
	return CVector3D( (x*d),(y*d),(z*d) );
}

CVector3D CVector3D::operator/(const double& d) const
{
	return CVector3D( (x/d),(y/d),(z/d) );
}

double CVector3D::operator|(const CVector3D& v) const
{
	double x,y,z;
	v.getCoords(x,y,z);
	
	return ( this->x*x + this->y*y + this->z*z );
}

CVector3D CVector3D::operator^(const CVector3D& v) const
{
	double x,y,z;
	v.getCoords(x,y,z);
	
	double a = this->y*z - this->z*y;
	double b = this->z*x - this->x*z;
	z = this->x*y - this->y*x;
	
	CVector3D u(a,b,z);
	return u;
}

CVector3D CVector3D::operator-(void) const
{
	CVector3D v( (-x) , (-y) , (-z) );
	return v;
}

void CVector3D::operator+=(const CVector3D& v)
{
	double x,y,z;
	v.getCoords(x,y,z);
	this->x += x;
	this->y += y;
	this->z += z;
}

void CVector3D::operator-=(const CVector3D& v)
{
	double x,y,z;
	v.getCoords(x,y,z);
	this->x -= x;
	this->y -= y;
	this->z -= z;
}

void CVector3D::operator*=(const double d)
{
	x *= d;
	y *= d;
	z *= d;
}

void CVector3D::operator/=(const double d)
{
	x /= d;
	y /= d;
	z /= d;
}

void CVector3D::operator^=(const CVector3D& v)
{
	double x,y,z;
	v.getCoords(x,y,z);
	
	double a = this->y*z - this->z*y;
	double b = this->z*x - this->x*z;
	this->z = this->x*y - this->y*x;
	this->x = a;
	this->y = b;
}


/*---------------------------------------------------------------------------*/
// external operators
CVector3D operator*(const double& d, const CVector3D& v)
{
	return (v * d);
}

ostream& operator<<(ostream& o, const CVector3D& v)
{
	o << " (" << v.x << ", " << v.y << ", " << v.z << ")";
	return o;
}

bool CVector3D::operator==(CVector3D& v)	{
	if (this->x == v.getX() && this->y == v.getY() && this->z == v.getZ())
		return true;
	else return false;
}

bool CVector3D::operator!=(CVector3D& v)	{
	if (this->x != v.getX() || this->y != v.getY()  || this->z != v.getZ())
		return true;
	else return false;
}

/*---------------------------------------------------------------------------*/
// EOF
