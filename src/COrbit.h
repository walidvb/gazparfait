/*---------------------------------------------------------------

Date de Creation:	17.05.2007
Description:		Class Orbit
Methodes:			Construct/Destruct
					print orbit
					draw

Modification:		16.06.07
						Ajout de la methode clear, pour vider les listes quand l'orbite n'est plus affichee.
---------------------------------------------------------------*/

#ifndef COrbith
#define COrbith

#include "CDrawable.h"
#include <deque>
#include <ostream>
#include "CVector3D.h"
#include "CColor.h"
#include "GLUT/glut.h"

class COrbit
{
public:
	
	//Constructors, get/set
COrbit() {};
virtual ~COrbit() {};

void resize(unsigned int i);
void draw(const CColor& c) const;
void setMaxpoints(int i); //!< defini le maximum de point dessines par une orbite
void clear();
	//methodes
void update(const CVector3D& p);								//!< rajoute le vecteur p dans la liste points.
friend ostream& operator<<(ostream& o, const COrbit& orb);		//!< " "

protected:
	
CColor c; //!< couleur de l orbite
static unsigned int maxPoints; //!< nbre maximal de points
CVector3D p; 
deque<CVector3D> points; //!< liste de positions 
};

/*!		\class COrbit
		\brief Classe Orbit stoquant les 'maxPoints' positions de la particule a laquelle elle appartient.
*/
#endif
