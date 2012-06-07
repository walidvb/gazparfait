#include "GLCamera.h"


double Camera::step(0.1);

Camera::Camera( CVector3D const& position) // constructeur de camera
	: position(position) 
{}


Camera::Camera( const Camera& cam ) // Constructeur de copie
	: position(cam.position){}
	
Camera::Camera() 
{}


Camera::~Camera() {}  // destructeur


Camera& Camera::operator=( const Camera& cam )  
{
	position = cam.position;
	
	return *this;
}

//Methods

void Camera::moveUD(int i)
{	
	angle2 += step*50*i;
}

void Camera::moveLR(int i)
{
	angle1 += step*50*i;
}

void Camera::zoom(int i)
{
	position += -i*step*position;
}

// methodes get et set

double Camera::getAngle1() const
{
	return angle1;
}

double Camera::getAngle2() const
{
	return angle2;
}

int Camera::getRiding() const
{
	return riding;
}

void Camera::setRiding(const int& riding)
{
	this->riding = riding;
}

void Camera::setAngle1(const double& angle1)
{
	this->angle1 = angle1;
}

void Camera::setAngle2(const double& angle2)
{
	this->angle2 = angle2;
}

void Camera::setAngles(const double& angle1, const double& angle2)
{
	this->angle1 = angle1;
	this->angle2 = angle2;
}

CVector3D Camera::getPosition() const
{
	return position;
}

void Camera::setPosition( const CVector3D& position )
{
	this->position=position;
}

void Camera::setStep(const double& step)
{
	this->step = step;
}

ostream& operator<<( ostream& o , const Camera& cam )
{
	o << "position : " << cam.position << endl;
	return o;
}
	
void Camera::save(ofstream& file) const
{
	//string file_name ("save");
	
	/*cout << "Please enter a file you would like to save to: " ;
	cin >> file_name;*/
	//file_name += ".xml";
	
	//On cree le flot qui va ecrire dans le file sauvegarde.xml
	//ofstream file(file_name.c_str());
	
	//On teste si le file peut-etre ouvert
	if(file.fail()){ 
		cerr << "Error: saved_file could not be written on." << endl;
	}
	else
	{ 
		
		file << "<Camera> " << endl;
		file << " <Position>" << position.getX() << " " << position.getY() << " "<< position.getZ() << " </Position>"<< endl;
		file << " <UP&DOWN> " << angle1 << " </UP&DOWN>" << endl;
		file << " <horiz_view> " << angle2 << " </horiz_view>" << endl;
		file << " <Step> " << step << " </Step>" << endl;
		file << " <RidingPart> " << riding << " </RidingPart>" << endl;
		file << "</Camera>" << endl;
	}
}




