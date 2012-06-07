/*---------------------------------------------------------------

Date de Creation:	01.06.2007
Description:		Classe Hasard contenant les fonctions frequement utilisées.
Methodes:			Construct/Destruct
										
Modification:		
---------------------------------------------------------------*/
#ifndef CHazardh
#define CHazardh

#include <ostream>
#include <cmath>

using namespace std;

class CHazard {
	public:
CHazard() {};
~CHazard() {};

	//Methods
inline double unif(double a, double b);				//!< choisi au hasard un nombre compris entre a et b
double gauss(double moyenne, double ecart_type);	//!< tire les vitesses selon la methode de gauss

};

inline double CHazard::unif(double a, double b) {
    return a + (rand() / double(RAND_MAX)) * (b - a);
}
/*!		\class CHazard
		\brief Classe Hasard utile pour l'appel des fonctions du hasard dans diverses fonctions.
*/
#endif
