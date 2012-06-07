#include "CSystem.h"

void init(CSystem& s);

int main() {
cout << "Launching simulation..." << endl;
CSystem s;
s.init();
double dt(0.1);
cout << s << endl;

for (int i(0); i <= 2; ++i) {

	cout << "Step " << i+1 << ": " << endl;
	cout << endl;
	cout << s << endl;
	s.update(dt);
	cout << "+++++++++++++++++++++++++++++++" << endl;
	cout << endl;
	}

cout << "end." << endl;

}
		 
		  
		   
