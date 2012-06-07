#include "CTri.h"

//Constructors------------------------
unsigned int CTri::type(TRIATOMIC);
double CTri::mass(  39.948);
CColor CTri::c(0.0, 0.0, 1.0, 1.0);
CTri::CTri() : CPart(){}

CTri::CTri(CVector3D p, CVector3D v, double masse, string name) : CPart(p, v, name)
{}

CTri::CTri(double a, double b, double c, double t) : CPart(a,b,c,t, mass)
{}

CTri::CTri(string name) : CPart(name) {}

CTri::CTri(const CTri& p) : CPart(p) {
	*this = p;							//conversion d'une adresse en objet
}

CTri::CTri( const CPart& mol, string const& name) : CPart( mol, name) {}

unsigned int CTri::getType() const
{
	return type;
}

CColor CTri::getCol() const
{
	return c;
}

void CTri::setCol(const CColor& col)
{
	this->c= col;
}

void CTri::setCol(const double& r,const double& g, const double& b, const double& a)
{
	c.setRed(r);
	c.setBlue(b);
	c.setGreen(g);
	c.setAlpha(a);
}

double CTri::getMass() const
{
	return mass;
}

void CTri::setMass(const double& m)
{
	this->mass=m;
}

void CTri::draw() const
{
	glPushMatrix() ;
	glColor4d(c.getRed(), c.getGreen(), c.getBlue(), c.getAlpha()); // choisi la couleur
	glTranslated( getPos().getX(), getPos().getY(), getPos().getZ()) ;  // se positionne au centre de la sphere
	glutSolidSphere(2.5, 5, 5);  // dessine une wiresphere 
	glPopMatrix();
}

