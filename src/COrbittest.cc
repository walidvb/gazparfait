#include "COrbit.h"

int main() {
	CVector3D p;
	CVector3D q(1,2,3);
	
COrbit o;
o.update(p);
o.update(q);

cout << o << endl;
return 0;
}
