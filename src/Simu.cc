#include "GLGUI.h"

int main( int argc, char *argv[] ) {
cout << "Launching simulation..." << endl;

CSystem s;
s.init();

			  
// on lance l affichage
Linterface = new GUI(argc, argv, s, "Gaz parfait");
Linterface->demarre();
}


		
		 
		  
		   
