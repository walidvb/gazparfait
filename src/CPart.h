/*---------------------------------------------------------------

Date de Creation:	04.04.2007
Description:		Class Particule
Methodes:			Construct/Destruct
get & set all attributes
print attributes

Modification:	18.04.07:
Herite dorenavant de CDrawable
Ajout de la methode virtuelle draw ne faisant rien dans cette classe
20.04.07:
Ajout de l'attribut couleur(RGBA)
26.04.07:
Ajout et definition de la methode updatev.
17.05.07:
Ajout de l'attribut orbite.
30.05.07:
inline de toutes les fcts get/set pour optimiser la simulation. ne marche pas.
Nouveau constructeur 'aleatoire'
06.06.07:
Ajout de la fct getCol()
08.06.07:
La fct updatep n'appelle dorenavant plus updateorb, car il faut attendre de replacer les particules dans l'enceinte.
12.06.07:
Passage des attributs type, masse, et color en static dans chaque classe
Virtualisation des methodes get&set des attributs concernes, et de draw.
Nous avons mnt du polymorphisme!!!
---------------------------------------------------------------*/

#ifndef CParth
#define CParth

#include <ostream>
#include <cmath>
#include "CVector3D.h"
#include "CDrawable.h"
#include "COrbit.h"
#include "CHazard.h"

using namespace std; 

#define MONOATOMIC 1
#define DIATOMIC 2
#define TRIATOMIC 3


class CPart: public CDrawable
{
public:
	
	//Constructors
	CPart();
	CPart(CVector3D p, CVector3D v, string name);
	CPart(double a, double b, double c,  double t, double m); //!< constructeur qui prend la taille de l enceinte(a,b,c), la temperature t du system et la masse de la particule
	CPart(string name);
	CPart(const CPart& p);
	CPart(const CPart& mol, string const& name); //!< constructeur de copie qui prend un nom en argument
	virtual	~CPart() {cout << "Me dead, man!" << endl;}
	
	
	//Public Methods
	CVector3D getPos() const;
	CVector3D getVel() const;
	string getName() const;
	void setPos( const CVector3D& r );
	void setPos(double& x, double& y, double& z);
	void setVel(double& x, double& y, double& z);
	void setVel( const CVector3D& v );
	void setName( const string& name );
	virtual void setMass( const double& m ) =0;			//!<
	virtual void setCol(const CColor& c) = 0;			//!<
	virtual void setCol(const double& r,const double& g, const double& b, const double& a) = 0;
	virtual CColor getCol() const=0;					//!<
	virtual double getMass() const=0;					//!<dynamically returns mass
	virtual unsigned int getType() const = 0;			//!<dynamically  returns type
 	bool getDraw() const;  
	void setDraw(bool active);
	COrbit getOrb() const;
	bool getDraworb() const;
	void setDraworb(bool active);
	virtual void draw() const=0; //!< draw method
	
	
	/*!Methodes permettant l'update des positions et des vitesses*/
	void updatep(double dt);					//!< update la position pour un temps dt donne.
	void updatev(CPart& p);									//!< update la vitesse en fct de la particule choquee
	void updatepX(double larg);							//!< update la position en cas de choc avec une paroi.
	void updatepY(double haut);							//!< update la position en cas de choc avec une paroi.
	void updatepZ(double prof);							//!< update la position en cas de choc avec une paroi.
	void updatepX0();										//!< update la position en cas de choc avec une paroi.
	void updatepY0();										//!< update la position en cas de choc avec une paroi.
	void updatepZ0();										//!< update la position en cas de choc avec une paroi.
	void updateorb();								//!< update les points presents dans la liste orbite.
	
	//operators
	friend ostream& operator<<(ostream& o, const CPart& part);	//!< "Masse, Position, Vitesse"
	
	//attributs
protected:
		
		CVector3D p;//!< position de la part
	CVector3D v; //!< vitesse de la part
	string n; //!< attribut nom de la part
	CColor c; //!< attribut couleur 
	COrbit orb; //!< attribut orbital
	CHazard h; //!< attribut qui va servir a appeller les fonctions de hazard
	bool drawpart; //!< savoir si on dessine une particule
	bool draworb; //!< savoir si on dessine une orbite
};

/*!		\class CPart
\brief Class particule
*/

#endif
