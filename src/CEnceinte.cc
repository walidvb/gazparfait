#include "CEnceinte.h"

// constructeurs-destructeurs---------------------------------

CEnceinte::CEnceinte()
: h(0), l(0), p(0), c(0.67, 0.0, 0.298, 0.25), max(200) {}

CEnceinte::CEnceinte( double& hauteur, double& largeur, double& prof )
: h( hauteur ), l( largeur ), p( prof ), c(0.67, 0.0, 0.298, 0.25), max(200){
	}

// methodes---------------------------------------------------

double CEnceinte::getH() const { return h; 
}
double CEnceinte::getL() const { return l; 
}
double CEnceinte::getP() const { return p; 
}

CColor CEnceinte::getCol() const { return c;
}

double CEnceinte::getMax() {
	return max;
	}

void CEnceinte::setH( double& hauteur ) { 
this->h = hauteur; 
}

void CEnceinte::setL( double& largeur ) { 
this->l= largeur; 
}

void CEnceinte::setP( double& prof ) { 
this->p = prof;
}

void CEnceinte::setCol(double r, double g, double b, double a){ 
CColor col(r, g, b, a);
this->c = col;
}
ostream& operator<<( ostream& o, const CEnceinte& e ) {
    o << " L'enceinte fait " << e.h << "m de hauteur, " << e.l << "m de largeur et " << e.p << "m de profondeur" << endl;
    return o;
}
