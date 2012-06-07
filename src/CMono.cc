#include "CMono.h"

//Constructors------------------------
unsigned int CMono::type(MONOATOMIC);
double CMono::mass(4.002602);
CColor CMono::c(1.0, 0.0, 0.0, 1.0);

CMono::CMono() : CPart(){}

CMono::CMono(CVector3D p, CVector3D v, double masse, string name) : CPart(p, v, name)
{}

CMono::CMono(string name) : CPart(name){}

CMono::CMono(double a, double b, double c, double t) : CPart(a,b,c,t,mass)
{}

CMono::CMono(const CMono& p) : CPart(p) {
	*this = p;							//conversion d'une adresse en objet
}

CMono::CMono( const CMono& mol, string const& name) : CPart( mol, name) {}

unsigned int CMono::getType() const
{
	return type;
}

CColor CMono::getCol() const
{
	return c;
}

void CMono::setCol(const CColor& col)
{
	this->c= col;
}

void CMono::setCol(const double& r,const double& g, const double& b, const double& a)
{
	c.setRed(r);
	c.setBlue(b);
	c.setGreen(g);
	c.setAlpha(a);
}

double CMono::getMass() const
{
	return mass;
}

void CMono::setMass(const double& m)
{
	this->mass=m;
}

void CMono::draw() const
{
	glPushMatrix() ;
	glColor4d(c.getRed(), c.getGreen(), c.getBlue(), c.getAlpha()); // choisi la couleur
	glTranslated( getPos().getX(), getPos().getY(), getPos().getZ()) ;  // se positionne au centre de la sphere
	glutSolidSphere(1, 5, 5);  // dessine une wiresphere 
	glPopMatrix();
	
	if(draworb == true)
	{
		orb.draw(c);
	}
	
}
