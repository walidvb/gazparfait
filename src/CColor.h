/*------------------------------------------------------------------------

Creation Date	: 	2007.04.24
Description	:	Class used to define RGBA coded color values
Methods	:	constructors, set -red, -green, -blue, -alpha
			get -red, -green, -blue, -alpha,
			setcolor (sets all four values at once)
			operators +,+= (mix two colors),
			external operator - (opposite color),
			external operator<< (display color value)
Dependencies	:	ostream

[CHANGELOG]


------------------------------------------------------------------------*/

#ifndef _CCOLOR_H_
#define _CCOLOR_H_

#include <ostream>

using namespace std;

class CColor
{
public:
	// constructors
	CColor();//!<
	CColor(const double& r, const double& g, const double& b, const double& a);//!<
	CColor(const CColor& c);//!<
	virtual	~CColor() {};//!<
	
	
	// methods
	inline void setRed(const double& i);//!<
	inline void setGreen(const double& i);//!<
	inline void setBlue(const double& i);//!<
	inline void setAlpha(const double& i);//!<
	void setColor(const double& r, const double& g, const double& b, const double& a);//!<
	
	inline const double& getRed() const;//!<
	inline const double& getGreen() const;//!<
	inline const double& getBlue() const;//!<
	inline const double& getAlpha() const;//!<
	
	// internal operators
	CColor operator+(CColor& c) ;	//!< mixes colors
	void operator+=(CColor& c);		//!< mixes colors
	
	// external operators
	friend CColor operator-(CColor& c);					//!< return 1 - CColor	
	friend ostream& operator<<(ostream& o, CColor& c); //!< " "
	
private:
	double red;		//!<R value
	double green;	//!<G value
	double blue;	//!<B value
	double alpha;	//!<A value
};

/*---------------------------------------------------------------------------*/
// inlined functions (get/set)
inline void CColor::setRed(const double& i)
{
	red = i;
}

inline void CColor::setGreen(const double& i)
{
	green = i;
}

inline void CColor::setBlue(const double& i)
{
	blue = i;
}

inline void CColor::setAlpha(const double& i)
{
	alpha = i;
}

inline const double& CColor::getRed() const
{
	return red;
}

inline const double& CColor::getGreen() const

{
	return green;
}

inline const double& CColor::getBlue() const
{
	return blue;
}

inline const double& CColor::getAlpha() const 
{
	return alpha;
}
/*!		\class CColor
\brief Classe Couleur utilisee pour definir les RGBA valeurs de couleur.
*/
#endif
