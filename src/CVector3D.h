/*---------------------------------------------------------------

Date de Creation:	21.03.2007
Description:		Classe vecteur permettant le positionnement par 3 coordonnées
Methodes:			Construct/Destruct
					get & set coordonnees

Modification:		
	28.03.07:		suppression de la methode affiche et compare en faveur d' operateurs
	20.04.07:		Ajout et suppression de l'operateur < et >, car il n'est pas utile, vu qu'on ne peut pas associer tous
					les cas ou une part sort de l'enceinte, mais on doit dissocier selon la paroi qu'elle traverse.
---------------------------------------------------------------*/

#ifndef CVector3Dh
#define CVector3Dh

#include <iostream>
#include <cmath>

using namespace std;

class CVector3D
{
public:
	//Constructeurs
	
CVector3D();
CVector3D(double x, double y, double z);
CVector3D( CVector3D const& v);
~CVector3D() {}

	//Methodes Publiques

void getCoords(double& x, double& y, double& z) const;
void setCoords(double x, double y, double z);

double getNorm() const ;													//!< retourne la norme au carre
double getX() const  ;
double getY() const ;
double getZ() const ;
void setX(double x);
void setY(double y);
void setZ(double z);
CVector3D normalize();														//!< retourne un vecteur unitaire
void nullify();															//!< annule le vecteur

	//operateurs
  friend CVector3D operator*(const double& d, const CVector3D& v); //!< u = d * v
  friend ostream& operator<<(ostream& o, const CVector3D& v);    //!< "(x,y,z)"
  
   CVector3D operator+(const CVector3D& v) const;		//!< u = v + w
   CVector3D operator-(const CVector3D& v) const;		//!< u = v - w
   CVector3D operator*(const double& d) const;			//!< u = v * d
   CVector3D operator/(const double& d) const;			//!< u = v / w
   CVector3D operator^(const CVector3D& v) const;       //!< u = v cross w
   double    operator|(const CVector3D& v) const;       //!< d = v produit scalaire w
   CVector3D operator-(void) const;						//!< v = -w
   void operator+=(const CVector3D& v);					//!< v += w
   void operator-=(const CVector3D& v);					//!< v -= w
   void operator*=(const double d);						//!< v *= d
   void operator/=(const double d);						//!< v /= d
   void operator^=(const CVector3D& v);                 //!< v ^= w
   bool operator==(CVector3D& v);						//!< v == w
   bool operator!=(CVector3D& v);						//!< v != w

	//attributs
private:
double x;
double y;
double z;
double norme();
};

#endif

/*---------------------------------------------------------------------------*/

/*! \class CVector3D
	\brief Classe vecteur permettant le positionnement par 3 coordonnees.
*/
// EOF
