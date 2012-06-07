/*---------------------------------------------------------------

Date de Creation:	04.04.2007
Description:		Classe systeme comportant une collection de particules ainsi qu'une enceinte
Methodes:			Construct/Destruct
					get & set all attributes
					Operateur << qui affiche 

	Modification:	
		18.04.07		
			Ajout de la methode draw.
			La liste de particule est desormais une listre de pointeurs pour permettre une collection heterogene d'objets.
		24.04.07
			Ajout de la methode update, qui met a jour le systeme
		17.05.07
			Ajout de l'attribut maxPoints, utile pour les orbites
		30.05.07:
			inline des fcts get/set et de addpart pr opimisation, puis de-inline.
		05.06.07:
			ajout des fct addpart tel que les particules sont ajoutées aléatoirement, par demande a l'utilisateur
		08.06.07:
			La fct update appelle maintenant update orb, lorsqu'il a fini de replacer les particules dans l'enceinte.
		14.06.07:
			Les boucles for utilisent mnt comme reperes des iterators, ce qui optimise beaucoup certains algorythmes
---------------------------------------------------------------*/

#ifndef CSystemh
#define CSystemh

//Default Configurations

#define LENGTH 200
#define HEIGHT 200
#define DEPTH 250
#define NB_MONO 500
#define NB_DI 350
#define NB_TRI 150
#define TEMP 298
#define EPSILON 0.2

#include "CEnceinte.h"
#include "CPartinc.h"
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

class CSystem : public CDrawable {
	
public:
	//Constructeurs/Destructeurs
	CSystem();
	CSystem(double h, double l, double p); //!< constructeur qui prend la taille de l enceinte en arguments
	virtual	~CSystem();
	
	
	
	//Initialisation of system
	
	void init(); //!< methode pour initialiser le systeme
	
	
	//Methodes
	void addpart(CPart* mol);				//!< Ajout d'une particule au systeme.
	void addpart();							//!< Ajout d'une particule aleatoire au systeme en fct de t. (Cette fct est utilisée en cours de déroulement du programme).
	void addpart(unsigned int type, unsigned int n);	//!< Ajout automatique d'une particule. 
	void clear();							//!< Vide le systeme de toutes ses particules.
	CPart* getPart(int i) const;				//!< get la particule i de la liste.			
	void draw() const;						//!< Affiche le systeme en cours
	void setEpsilon(double eps);			
	void setMaxpoints(int max);
	void setTemp(double t);
	void setEnceinte(double l, double h, double d);	//!< Redimensionne l'enceinte du systeme.
	CEnceinte getEnceinte();
	void update(double dt);							//!< Met a jour les positions et les vitesses de chaque particule presente dans l' enceinte
	void updatebest(double dt);						//!< Pareil, mais en mieux.
	double getEcin()const;							//!< retourne evidemment l'energie cinetique du systeme.
	int getList() const;				//!< Utile pour connaitre la taille de liste dans le parseur.
	inline unsigned int typecheck();				//!< retourne 1 pour mono, 2 pour di, et 3 pour tri.
	
	void debug();
	
	void save() const;
	//List Modifications
	
	void rm(unsigned int type);								//!< Removes an element of type from listp
	void rmAll(unsigned int type);							//!< Removes all elements of type from listp
	
	void setAll(bool active, unsigned int type);			//!< Sets the 'draw' bool of all 'type' to active
	
	void setAllbut(bool active, unsigned int type);			//!< Sets the 'draw' bool of all !type to active
	
	void addorb(unsigned int type);							//!< dessine l'orbite d'un type de plus.
	void lessorb(unsigned int type);						//!< ne dessine plus l'orbite de la derniere 
	void oneorb(unsigned int type);							//!< ne dessine qu'une orbite.
	
	void setColorset();										//!< changes color set (doesn't work yet)
	
	//Operateurs externes
	friend ostream& operator<<(ostream& o, const CSystem& s);	//!< " "
	
private:
		//Constructeurs privés
		//CSystem(CSystem& s);
		
		//CSystem operator=(const CSystem& s) const;
		
		// attributs
	vector < CPart* > listp;						//!< Liste de pointeurs sur les particules presentes dans le systeme
	CEnceinte e;									//!< Enceinte dans laquelle les particules sont.
	double epsilon;									//!< intervalle determinant si le choc a lieu.
	int maxPoints;									//!< nb de pts contenus ds les orbites.
	CHazard h;										//!< element utile pr l'appel des fcts aleatoires.
	double t;
	unsigned int colorset;							//!< Used to know which colorset we're in.
};



/*!		\class CSystem
\brief Classe systeme comprenant une enceinte et une liste de particules.
*/

//EOF
#endif
