#include "CDi.h"

//Constructors------------------------
unsigned int CDi::type(DIATOMIC);
double CDi::mass( 20.1797);
CColor CDi::c(0.0, 1.0, 0.0, 1.0);
CDi::CDi() : CPart(){}

CDi::CDi(CVector3D p, CVector3D v, double masse, string name) : CPart(p, v, name)
{}

CDi::CDi(double a, double b, double c, double t) : CPart(a,b,c,t, mass)
{}

CDi::CDi(string name) : CPart(name) {}

CDi::CDi(const CDi& p) : CPart(p) {
	*this = p;							//conversion d'une adresse en objet
}

CDi::CDi( const CPart& mol, string const& name) : CPart( mol, name) {}

unsigned int CDi::getType() const
{
	return type;
}

CColor CDi::getCol() const
{
	return c;
}

void CDi::setCol(const CColor& col)
{
	this->c= col;
}

void CDi::setCol(const double& r,const double& g, const double& b, const double& a)
{
	c.setRed(r);
	c.setBlue(b);
	c.setGreen(g);
	c.setAlpha(a);
}

double CDi::getMass() const
{
	return mass;
}

void CDi::setMass(const double& m)
{
	this->mass=m;
}

void CDi::draw() const
{
	glPushMatrix() ;
	glColor4d(c.getRed(), c.getGreen(), c.getBlue(), c.getAlpha()); // choisi la couleur
	glTranslated( getPos().getX(), getPos().getY(), getPos().getZ()) ;  // se positionne au centre de la sphere
	glutSolidSphere(1.5, 5, 5);  // dessine une wiresphere 
	glPopMatrix();
}

