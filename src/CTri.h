/*---------------------------------------------------------------

Date de Creation:	25.05.2007
Description:		Class TriTri-atomic
Parent of:			none
Child of:			CPart, CDrawable
Methods:			Construct/Destruct
					get & set all atTributes
					print atTributes

Modification:		
---------------------------------------------------------------*/
#ifndef _CTRI_H_
#define _CTRI_H_

#include "CPart.h"

class CTri: public CPart {

public:
	//constructors
CTri();
CTri(CVector3D p, CVector3D v, double masse, string name);
CTri(double a, double b, double c, double t);
CTri(string name);
CTri(const CTri& p);
CTri( const CPart& mol, string const& name);

unsigned int getType() const;
CColor getCol() const;
void setCol(const CColor& col);
void setCol(const double& r,const double& g, const double& b, const double& a);
double getMass() const;
void setMass(const double& m);
void draw() const;

protected:
static unsigned int type; //!< attribut du type des particules tri
static double mass; //!< attribut masse de la particules tri
static CColor c;  //!< attribut couleur de la particule tri
};
/*!		\class CTri
		\brief Sous-classe de particule precisant qu'on est Tri-atomique
*/

#endif

