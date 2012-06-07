#include "CSystem.h"

int main() {
	
	cout << "Constructions des 3 particules: " << endl;
	
	CVector3D pos(1, 2, 3);
	CVector3D vit(4, 5, 6);
	CVector3D pos1(9, 8, 7);
	
	CPart Na("Sodium");
	CPart Cl(pos, vit, 2, "Chlore", 2);
	CPart Ca(pos1, vit, 3, "Carbone", 1);
	
	CSystem s(3.0, 4.0, 5.0);
	cout << "Ajout de Sodium" << endl;
	s.addpart(&Na);
	
	cout << s << endl;
	Na.draw();
	
	cout << "Ajout du reste..." << endl;
	
	s.addpart(&Cl);
	s.addpart(&Ca);
	//s.addpart(25, 3);
	cout << s << endl;
	Cl.draw();
	
	cout << "fin du test." << endl;
	
	return 0;
}
