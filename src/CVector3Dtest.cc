#include "CVector3D.h"
#include <ostream>
#include <cmath>

using namespace std;

int main() {

CVector3D vect1;
CVector3D vect2;
CVector3D vect3;

vect1.setCoords(1, 2, -0.1);
vect2.setCoords(2.6, 3.5, 4.1);
vect3.setCoords(1, 2, -0.1);


cout << "Vecteur 1 : " << vect1 << endl;
cout << "Vecteur 2 : " << vect2 << endl;
cout << "Vecteur 3 : " << vect3 << endl;

cout << "Le Vecteur 1 est ";
if (vect1 == vect2) {
    cout << "egal au ";
} else {
    cout << " different du ";
}
cout << " Vecteur 2," << endl << " et est ";
if (vect1!=vect3) {
    cout << " different du ";
} else {
    cout << " egal au ";
}
cout << " Vecteur 3." << endl;

cout << "vect2 = vect1" << " = ";
vect2 = vect1;
cout << vect2<< endl;
 cout << "Le Vecteur 1 est ";
if (vect1 == vect2) {
    cout << "egal au ";
} else {
    cout << " different du ";
}
cout << " Vecteur 2," << endl << " et est ";
if (vect1!=vect3) {
    cout << " different du ";
} else {
    cout << " egal au ";
}
cout << " Vecteur 3." << endl;
};
