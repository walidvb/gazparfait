/*---------------------------------------------------------------

Date de Creation:	18.04.2007
Description:		Class Monoatomic
Parent of:			none
Child of:			CPart, CDrawable
Methods:			Construct/Destruct
					get & set all attributes
					print attributes

Modification:		
---------------------------------------------------------------*/
#ifndef _CMONO_H_
#define _CMONO_H_

#include "CPart.h"

class CMono: public CPart {

public:
	//constructors
CMono();
CMono(CVector3D p, CVector3D v, double masse, string name);
CMono(string name);
CMono(double a, double b, double c, double t);
CMono(const CMono& p);
CMono(const CMono& mol, string const& name);
virtual ~CMono() {}

unsigned int getType() const;
CColor getCol() const;
void setCol(const CColor& col);
double getMass() const;
void setMass(const double& m);
void draw() const;
void setCol(const double& r,const double& g, const double& b, const double& a);

protected:
static unsigned int type; //!< attribut du type de la particules mono
static double mass; //!< attribut masse de la particules mono
static CColor c; //!< attribut couleur de la particule mono
};

#endif
/*!		\class CMono
		\brief Sous-classe de particule precisant qu'on est monoatomique
*/
