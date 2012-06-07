#include "CPart.h"

int main() {

cout << "Construction des 4 Particules:" << endl;

CVector3D pos(1, 2, 3);
CVector3D vit(4, 5, 6);
CPart Na("Sodium");
CPart Cl(3, 3, 3, 298, 20.1797,3);
CPart Ca(pos, vit, 3, "Carbone", 1);
CPart Ca14(Ca, "Carbone 14");

cout << "p: " << pos << " v: " << vit << endl;
cout << Na << endl;
cout << Cl << endl;
cout << Ca << endl;
cout << Ca14 << endl;

cout << "setPos & setVel sur Na(Sodium)" << endl;
Na.setPos(pos);
Na.setVel(vit);
Na.setMass(2);
cout << Na << endl;
cout << "Na=Cl" << endl;
Na = Cl;
cout << "Sodium: " << Na << endl;
CVector3D pos1(2, 3, 4);
Na.setPos(pos1);
cout << "Sodium en pos1 : " << Na << endl;
return 0;
}

