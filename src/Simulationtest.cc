#include "CSystem.h"


int main() {

cout << "Construction du systeme a 3 particules" << endl;

CVector3D pos(1, 2, 3);
CVector3D vit(4, 5, 6);
CVector3D pos1(9, 8, 7);
CVector3D pos2(9, 8, 7);
CVector3D vit2(0, 0, 0);

CDi Na(2, 2, 2, 298);
CMono Cl(pos, vit, 2, "Chlore");
CTri Ca(pos1, vit, 3, "Carbone");
Ca.setDraworb(true);
CSystem s(10, 10, 10);
s.addpart(&Na);
s.addpart(&Cl);
s.addpart(&Ca);
double dt(0.1);
s.setEpsilon(0.01);
s.setMaxpoints(3);

cout << "Lancement de la simulation :" << endl;
cout << endl;

for (int i(0); i <= 4; ++i) {

	cout << "Step " << i+1 << ": " << endl;
	cout << endl;
	cout << s << endl;
	s.update(dt);
	cout << "+++++++++++++++++++++++++++++++" << endl;
	cout << endl;
}

cout << "fin du test." << endl;

return 0;
}

