#include "CPart.h"

//Constructors    -------------------------------------
CPart::CPart()
: p(), v(), n(0) {}

CPart::CPart(CVector3D p,CVector3D v, string name)
: p(p), v(v), n(name), draworb(false) {}

CPart::CPart(double a, double b, double c, double t, double m) {
	double spec(1e-3*8.314472/m);
	CVector3D p(h.unif(0, a), h.unif(0, b), h.unif(0, c));
	CVector3D v(h.gauss(0.0, sqrt(spec*t)), h.gauss(0.0, sqrt(spec*t)), h.gauss(0.0,sqrt(spec*t)));
	this->p = p;
	this->v = v;
	this->drawpart = true;
}

CPart::CPart(string name)
: p(), v(), n(name), draworb(false) {}

CPart::CPart(const CPart& p) {
	*this = p;					//conversion d'une adresse en objet
}

CPart::CPart( const CPart& mol, string const& name) :
draworb(false) {
	this->p = mol.getPos();
	this->v = mol.getVel();
	this->n = name;
}

//get&set methods -------------------------------------

CVector3D CPart::getPos() const{
	return p;
}

CVector3D CPart::getVel() const{
	return v;
}

string CPart::getName() const{
	return n;
}

/*double CPart::getMass() const{
return m;
}*/

/*CColor CPart::getCol() const {
return c;
}*/

void CPart::setPos( const CVector3D& r ) {
	this->p = r;
}

void CPart::setPos(double& x, double& y, double& z) {
	this->p.setX(x);
	this->p.setY(y);
	this->p.setZ(z);
}

void CPart::setVel( const CVector3D&  v) {
	this->v = v;
}

void CPart::setVel(double& x, double& y, double& z) {
	this->v.setX(x);
	this->v.setY(y);
	this->v.setZ(z);
}

void CPart::setName(const string& name) {
	this->n = name;
}

/*void CPart::setMass(const double& m) {
this->m = m;
}

void CPart::setCol(CColor& c) {
	this->c = c;
}*/

bool CPart::getDraw() const {
	return drawpart;}

void CPart::setDraw(bool active) {
	this->drawpart = active;
	if(active == false)
		this->draworb = active;}

COrbit CPart::getOrb() const {
	return this-> orb;
}

bool CPart::getDraworb() const {
	return draworb;}

void CPart::setDraworb(bool active) {
	this->draworb = active;
	if (active == false)
		orb.clear();
}

//Methodes & Operateurs externes ----------------------

ostream& operator<<(ostream& o, const CPart& part) {
	o << "Nom: " << part.n << "  Masse: " << part.getMass() << "  Position: " << part.p << "  Vitesse: " << part.v << endl;
	if (part.draworb==true)
		o << "Orbite: "<< endl;
	o << part.orb << endl;
	return o;
}


void CPart::updatep(double dt) {
	this->p = p + v*dt;
	
}

void CPart::updatev( CPart& p) {
	//cout << "++++++++++++++++++" << endl;
	//cout << "Collision de la particule " << this->n << " avec la particule " << p.getName() << endl;
	//cout << endl;
	CVector3D vg;
	vg = v * p.getMass()/(getMass()+p.getMass()) + p.getVel() * p.getMass()/(getMass()+p.getMass());								
		
	//cout << "Conservation de la quantité de mouvement: " << endl;
	
	CVector3D v0(h.unif(-5, 5), h.unif(-5, 5), h.unif(-5, 5));
	v0.normalize();
	
	//cout << endl;
	//cout << getMass() <<endl;
	//cout << "Quantité de mouvement avant le choc: " << v*getMass() + p.getVel()*p.getMass() << endl;
	//cout << "Energie cinétique avant le choc: " << v.getNorm()*getMass()/2 + p.getVel().getNorm()*p.getMass()/2 << endl;
	//cout << endl;
	//cout << "Quantité de mouvement après le choc: " << (vg+v0)*getMass() + (vg-v0 * getMass()/p.getMass())*p.getMass() << endl;
	//cout << "Energie cinétique après le choc: " << (vg+v0).getNorm()*getMass()/2 + (vg-v0 * getMass()/p.getMass()).getNorm()*p.getMass()/2 << endl;
	//cout << "++++++++++++++++++" << endl;
	v = (vg+v0);
	p.setVel( (vg-v0 * getMass()/p.getMass()) );								
	
}

void CPart::updatepX(double larg)	{//	cout << "Collision avec la paroi 2 de la particule " << n << endl;
	this->p.setX(2*larg - p.getX());
	this->v.setX(-v.getX());		}

void CPart::updatepY(double haut)	{//	cout << "Collision avec la paroi 4 de la particule " << n << endl;
	this->p.setY(2*haut - p.getY());
	this->v.setY(-v.getY());		}

void CPart::updatepZ(double prof)	{//	cout << "Collision avec la paroi 6 de la particule " << n << endl;
	this->p.setZ(2*prof - p.getZ());
	this->v.setZ(-v.getZ());		}

void CPart::updatepX0()	{//	cout << "Collision avec la paroi 1 de la particule " << n << endl;
	this ->p.setX(-p.getX());
	this->v.setX(-v.getX());		}

void CPart::updatepY0()	{//	cout << "Collision avec la paroi 3 de la particule " << n << endl;
	this ->p.setY(-p.getY());
	this->v.setY(-v.getY());		}

void CPart::updatepZ0()	{//	cout << "Collision avec la paroi 5 de la particule " << n << endl;
	this ->p.setZ(-p.getZ());
	this->v.setZ(-v.getZ());		}


void CPart::updateorb() {
	this->orb.update(p);
}








