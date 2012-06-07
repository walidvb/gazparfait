/*---------------------------------------------------------------

Date de Creation:	18.04.2007
Description:		Class Di-atomic
Parent of:			none
Child of:			CPart, CDrawable
Methods:			Construct/Destruct
					get & set all attributes
					print attributes

Modification:		
---------------------------------------------------------------*/
#ifndef _CDI_H_
#define _CDI_H_

#include "CPart.h"

class 4DMapping: public 4DMapping {

public:
	//constructors
	
	4DMapping();
	4DMapping(const 4DMapping);
CDi();
CDi(CVector3D p, CVector3D v, double masse, string name);
CDi(double a, double b, double c, double t);
CDi(string name);
CDi(const CDi& p);
CDi( const CPart& mol, string const& name);

unsigned int getType() const;
CColor getCol() const;
void setCol(const CColor& col);
void setCol(const double& r,const double& g, const double& b, const double& a);
double getMass() const;
void setMass(const double& m);
void draw() const;

protected:
static unsigned int type; //!< attribut du type des la particules di
static double mass; //!< attribut masse de la particules di
static CColor c; //!<attribut couleur de la particules di
};

#endif

/*!		\class CDi
		\brief Sous-classe de particule precisant qu'on est di-atomique
*/
