/*------------------------------------------------------------------------

Creation Date	: 	23.05.2007
Description	:	Class used to draw object, understand input
Parent of	:       none
Child of	:		none
Methods	:      get/set draw save keyboard.etc...
Dependencies	:	None

------------------------------------------------------------------------*/
#ifndef _GLGUI_H_
#define _GLGUI_H_


#ifdef _GLGUI_CC_
#define __export
#else
#define __export extern
#endif

#include <GLUT/glut.h>
#include <cstdlib>

#include "CSystem.h"
#include "GLCamera.h"
#include "CParser.h"

using namespace std;





class GUI 
{
	
private	:

	//CSystem  a_dessiner;  //!< system a dessine
	unsigned int temps;   //!< temps absolu
	bool timer_on;        //!< pour savoir si la simulation tourne
	double ratio;         //!< Time ratio (dt is divided by this ratio)
	//unsigned int type;    //!< Used to select a type while calling functions like addpart...
	bool fullscreen;      //!< tells if fullscreen mode is on/off
	bool ridingpart;	  //!< is on on if you're riding a particule
	bool simumode;
	//Camera ma_camera;
	int ma_fenetre;
	
	int mouse_x, mouse_y;
	bool leftMouse;
	double alpha, beta;
	int mouse_ancienne_x, mouse_ancienne_y;
	
	
	
public:

		Camera ma_camera;
		CSystem  a_dessiner;  //!< system a dessine
		unsigned int type;    //!< Used to select a type while calling functions like addpart...

	// methodes get & set

	unsigned int getTemps () const;
	bool getTimer_on () const;
	void setTemps( unsigned int temps );
	void setTimer_on( bool timer_on );
	CSystem& getSystem();
	Camera getCamera() const;
	void setCamera(const Camera& camera);
	void setRatio(int i);

	void save() const;
    // declaration des methodes "friend"

	friend void keyboard( unsigned char, int mouse_x, int mouse_y ); //!< clavier normal
	friend void up_keyboard( unsigned char, int mouse_x, int mouse_y ); //!< clavier "quand on lache une touche"
	friend void clavier_special (int touche, int mouse_x, int mouse_y); //!< clavier pour la camera
	friend void draw();
	friend void reshape( int largeur, int hauteur );
	friend void idle( void ); //!< pour que ca marche
	friend void simulation( int id );

	friend void menu();

	
    //Gere les evenements mouse
	
	friend void mouse_clic(int bouton , int etat , int mouse_x , int mouse_y); //!< Quand on clique avec le bouton de gauche
	friend void mouse_rotate(int mouse_x , int mouse_y);
	friend void passive_mouse(int x, int y);

	/*methodes propres a la camera utile uniquement si la camera est declare en dehors de la classe gui

	Camera getCamera() const;
	void setCamera( const Camera& camera ); */


   void demarre(); //!< methode qui demarre l interface

	
   // constructeur qui prend en argument un pointeur sur ce qu il doit dessiner c a dire le systeme
	GUI( int argc, char *argv[], CSystem& a_dessiner, string nom_fenetre);	//!< constructeur de GUI				 
						 
	

};



   // variable GLOBALE ( ne pas l oublier )

__export GUI* Linterface; //!< variable globale de type GUI

#endif

/*! \class GLGUI
	\brief Allows to display a_dessiner attributes
*/
