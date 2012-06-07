/*------------------------------------------------------------------------

Creation Date	: 	10.06.2007
Description	:	Class used to move around while simulating
Parent of	:       none
Child of	:		none
Methods	:      get/set moveFB, moveLR, zoom.
Dependencies	:	

------------------------------------------------------------------------*/

#ifndef GLCamerah
#define GLCamerah


#include "CVector3D.h"
#include <fstream>
#include <iostream>

using namespace std;


class Camera
{

public :
	Camera(); //!< default constructor
	Camera( CVector3D const& position); //!<  Constructor with only a CVector3D as argument(his own position
	Camera( const Camera& cam); //!< Copy Constructor
	virtual ~Camera(); //!<  Virtual destructor
	
	Camera& operator=(const Camera& cam); //  Surcharge de l'operateur = ( affectation d'une camera )

	friend ostream& operator<<(ostream& o , const Camera& cam);  // Surcharge de l'operateur << ( affichage d'une camera )

	void save(ofstream& file) const;	//!<allows to save camera to an .xml, but must be called from GLGUI

// methodes get
	
	CVector3D getPosition() const; //!<
	CVector3D getVertical() const; //!<
	double getAngle1() const;	//!<
	double getAngle2() const;	//!<
	int getRiding() const;	//!<
	
// methodes set
	
	void setPosition( const CVector3D& position );	//!<un-used, because the camera doesn't move.
	void setStep(const double& step);				//!<
	void setAngle1(const double& angle1);			//!<
	void setAngle2(const double& angle2);			//!<
	void setAngles(const double& angle1, const double& angle2);	//!<
	void setRiding(const int& riding);				//!<

//moving methods

	void moveUD(int i);			//!< allows to move forward or backwards, depending on i = +-1
	void moveLR(int i);			//!< allows the sphere moving around us ...
	void zoom(int i);			//!< makes a big step, back or forth...
	
	
protected :
	
	CVector3D position; //!< position of camera
	static double step; //!< step
	double angle1, angle2; //!< rotation angles
	int riding;	//!<if riding ==1, then you're riding a particule
	
};
/*! \class Camera
	\brief Camera class allowing to change the point of view (it actually changes the way a system is displayed)
*/

#endif 
// EOF