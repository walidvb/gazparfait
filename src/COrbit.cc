#include "COrbit.h"

unsigned int COrbit::maxPoints(15);


void COrbit::update(const CVector3D& p) {
	if (points.size() >  maxPoints)
		points.pop_back();
		points.push_front(p);
	
}

void COrbit::draw(const CColor& c) const {
	
	glBegin(GL_LINE_STRIP);
	glColor4d(c.getRed(), c.getGreen(), c.getBlue(), 1.0);
    for (unsigned int i(0); i < points.size(); ++i) //deque< CVector3D>::iterator i(points.begin()); i < points.end(); ++i)// 
	{
		glVertex3f(points[i].getX(), points[i].getY(), points[i].getZ());
    }
    glEnd();
}

void COrbit::clear()
{
	points.clear();
}
void COrbit::setMaxpoints(int i)
{	if (maxPoints + i < 0)
		{cout << "Cannot make it smaller!!" << endl;}
	else if (maxPoints + i > 1500)
		{cout << "Cannot make it bigger!!!" << endl;}
	 maxPoints += i;
}



void COrbit::resize(unsigned int i) {
	if( i < 0 ) maxPoints = 0;
	
	else maxPoints = i;
}

ostream& operator<<(ostream& o, const COrbit& orb) 
{
	//for (unsigned int i(0); i< orb.points.size(); ++i)
	//{	o << "point de l'orbite "<< i+1 << orb.points[i] << endl;}
	o << "bof";
	return o;
}


