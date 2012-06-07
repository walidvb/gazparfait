/*----------------------------------------------------

Date de Creation:	04.04.2007
Description:		Classe Enceinte permettant de representer les parois enfermant la simulation
Methodes:			Constructeurs-Destructeurs, get & set et affichage de l'enceinte
Modifications:		30.05.07:
						 des fcts get/set.

----------------------------------------------------*/

#ifndef CEnceinteh
#define CEnceinteh

#include <iostream>
#include "CColor.h"

using namespace std;

class CEnceinte
{
	
private:
	double h;	//!<attribut definissant la hauteur de l enceinte
	double l;	//!< attribut definissant la longeur de l enceinte
	double p;	//!< attribut definissant la profondeur de l enceinte
	CColor c;	//!< attribut defnissant la couleur de l enceinte
	int max;	//!< attribut pour avoir la taille maximale de l enceinte, non utilise
	
public:
		
	// constructeurs-destructeurs-----------------------
		
	CEnceinte();
	CEnceinte( double& hauteur, double& largeur, double& prof );
	
	~CEnceinte() {};
	
	// methodes-----------------------------------------
	
	 double getH() const;
	 double getL() const; 
	 double getP() const;
	 CColor getCol() const;
	 double getMax();
	 
	 void setH( double& hauteur );
	 void setL( double& largeur );
	 void setP ( double& prof );
	 void setCol(double r, double g, double b, double a);
	 
	friend ostream& operator<<( ostream& o, const CEnceinte& e ); //!< " "
	
};
/*!		\class CEnceinte
		\brief Classe Enceinte contenant sa propre taille. (L, H, P)
*/
#endif
