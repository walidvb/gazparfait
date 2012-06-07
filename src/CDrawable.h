/*------------------------------------------------------------------------

Creation Date	: 	18.04.2007
Description	:	Abstract base class defining a drawable object.
Defines three methods which all drawable objects
have to implement: draw (draw the object using
						 OpenGL), and animate. The latter function can be void
if the object stays still.
Parent of	:	CPart, CSystem
Child of	:	none
Methods	:	draw, animate
Dependencies	:	none

------------------------------------------------------------------------*/

#ifndef _CDRAWABLE_H_
#define _CDRAWABLE_H_

#include <GLUT/glut.h>

class CDrawable
{
public:
	CDrawable() {};
	virtual ~CDrawable() {};
	
			//Methods
	virtual void draw() const =0; //!< methode virtuelle de CDrawable
	
};
/*!		\class CDrawable
\brief Classe de laquelle herite tous les elements dessinables( enceinte, particules, systemes, orbite, etc...)
*/
#endif
