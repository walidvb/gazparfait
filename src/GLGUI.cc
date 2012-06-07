#define _GLGUI_CC_
#include "GLGUI.h"



// constructeur

GUI::GUI(int argc, char *argv[], CSystem& a_dessiner, string nom_fenetre)
:a_dessiner(a_dessiner), simumode(1)
{
	CVector3D position(-a_dessiner.getEnceinte().getL()*1.5, a_dessiner.getEnceinte().getH()*0.9, -a_dessiner.getEnceinte().getP()*1.3);
	CVector3D visee(a_dessiner.getEnceinte().getL()/2, a_dessiner.getEnceinte().getH()/2,a_dessiner.getEnceinte().getP()/2 );
	CVector3D vertical(0, 1.0,0);
	ma_camera.setPosition(position);
	ma_camera.setAngles(0, 1.5708);
	
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
	glutInitWindowSize( 1280, 800 );
	ma_fenetre=glutCreateWindow( nom_fenetre.c_str() );
	menu();
	glutDisplayFunc( draw );
	glutIdleFunc( idle );
	glutMouseFunc( mouse_clic ); // mouse
	glutMotionFunc( mouse_rotate ); // mouse
	glutPassiveMotionFunc( passive_mouse );
	glutKeyboardFunc( keyboard ); // clavier
	glutKeyboardUpFunc( up_keyboard ); // clavier
	glutSpecialFunc( clavier_special ); // clavier pour la camera
	glutReshapeFunc( reshape );
	
	
	
	
	
	// gestion du temps
	
	glutTimerFunc( 1, simulation, 0 );
	timer_on=true;
	temps=glutGet( GLUT_ELAPSED_TIME );
	ratio=15;
	type=1;
	fullscreen = 0;
	this->a_dessiner=a_dessiner;
	
	;
	
	// Permet la gestion des parties cachÈes
	
	//glEnable( GL_DEPTH_TEST );
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glDepthFunc( GL_LESS );
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
}

// methodes get et set et demarre

unsigned int GUI::getTemps () const
{
	return temps;
}

bool GUI::getTimer_on () const
{
	return timer_on;
}

void  GUI::setTemps ( unsigned int temps )
{
	this->temps=temps;
}

void GUI::setTimer_on ( bool timer_on )
{
	this->timer_on=timer_on;
}

CSystem& GUI::getSystem() 
{
	return this->a_dessiner;
}

void GUI::setRatio(int i)
{
	this->ratio += i;
}



Camera GUI::getCamera() const
{
	return ma_camera;
}


void GUI::setCamera( const Camera& camera )
{
	this->ma_camera = camera;
} 


void GUI::demarre() 
{
	glutMainLoop();
}


// methodes friends


void reshape( int largeur, int hauteur )
{	
	if ( hauteur <= 0 ) hauteur = 1;
	double ratio1( largeur );
	ratio1 /= hauteur;
	
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glViewport( 0, 0, largeur, hauteur );
	gluPerspective( 45.0, ratio1, 1.0, 1000.0 );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	gluLookAt( Linterface->ma_camera.getPosition().getX(), Linterface->ma_camera.getPosition().getY(), Linterface->ma_camera.getPosition().getZ(),
			   0.0, 0.0, 0.0 ,
			   0.0, 1.0, 0.0 );
	
}

void drawString( char *s )//sert a dessiner un string
{
	unsigned int i;
	
	for (i = 0; i < strlen (s); i++)
	{ glutBitmapCharacter ( GLUT_BITMAP_TIMES_ROMAN_24, s[i] ); }
}

void draw()
{
	int rec(0);
	char label[100];
	//glTranslated(0, -Linterface->a_dessiner.getSystem().geEnceinte().getH()/2, 0);
	glColor3f ( 1.0F, 0.50F, 1.0F );
	sprintf ( label, "->Created by Pierre&Walid<-" );
	glRasterPos3f ( Linterface->a_dessiner.getEnceinte().getL()/1.2, Linterface->a_dessiner.getEnceinte().getH()/1.5, Linterface->a_dessiner.getEnceinte().getP()/2);
	
	if( Linterface )
	{
		
		
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		glLoadIdentity();
		
		if(Linterface->ma_camera.getRiding() == 1)
		{
			int follow;
						
			for(unsigned int i(0); i < Linterface->getSystem().getList(); ++i)
		{
			if(Linterface->getSystem().getPart(i)->getType() == Linterface->type)
			{	cout << i;
				follow = i;
				break;
			}
		
		}
			if (!Linterface->getSystem().getPart(follow)->getDraworb() ) Linterface->getSystem().getPart(follow)->setDraworb(true);
			if (!Linterface->getSystem().getPart(follow)->getDraw() ) Linterface->getSystem().getPart(follow)->setDraw(true);

			gluLookAt( -Linterface->getSystem().getPart(follow)->getPos().getX() + Linterface->getSystem().getEnceinte().getH()/2 +( Linterface->getSystem().getPart(0)->getVel().normalize()).getX()*0.5 , 
					   -Linterface->getSystem().getPart(follow)->getPos().getY() + Linterface->getSystem().getEnceinte().getL()/2 + ( Linterface->getSystem().getPart(0)->getVel().normalize()).getY()*0.5, 
					   -Linterface->getSystem().getPart(follow)->getPos().getZ() + Linterface->getSystem().getEnceinte().getP()/2 + ( Linterface->getSystem().getPart(0)->getVel().normalize()).getZ()*0.5,
					   
					   +Linterface->getSystem().getPart(follow)->getPos().getX() - Linterface->getSystem().getEnceinte().getH()/2,
					   +Linterface->getSystem().getPart(follow)->getPos().getY() - Linterface->getSystem().getEnceinte().getL()/2,
					   +Linterface->getSystem().getPart(follow)->getPos().getZ() - Linterface->getSystem().getEnceinte().getP()/2,
					   
					   0.0,1.0,0.0);
		}
		else {
			gluLookAt( Linterface->ma_camera.getPosition().getX(), Linterface->ma_camera.getPosition().getY(), Linterface->ma_camera.getPosition().getZ(),
					   0.0,0.0,0.0,
					   0.0,1.0,0.0);
		}
		
		if(Linterface->ma_camera.getRiding() != 1)
		{
			glRotated(-Linterface->ma_camera.getAngle1(), 0, 1, 0);
		glRotated(Linterface->ma_camera.getAngle2(), 1, 0, 0);		
		}
		
		if ( Linterface != NULL )
		{
			Linterface->a_dessiner.draw();//  methode draw de  CSystem
										  //cout << Linterface->a_dessiner << endl;
			drawString( label );
			if( rec %200 == 0 )
				//	cout << "Kinetic energy of system: " << Linterface->a_dessiner.getEcin() << endl;
				++rec;
		}
		
		glutSwapBuffers();
		glClearColor(1.0, 0.95686, 0.63528, 0.95);  //Colore le fond
	}
	
	
}

// fonction qui sert pour le bon fonctionnement

void idle( void )
{
	glutPostRedisplay();
	glutIdleFunc(0);
}


// rajouter ptet une touche pause ou un truc comme ca


void keyboard( unsigned char touche, int mouse_x, int mouse_y )
{
	switch (touche)
	{
		case '1':
			(Linterface->type) = MONOATOMIC;
			break;
			
		case '2':
			Linterface->type = DIATOMIC;
			break;
			
		case '3':
			Linterface->type= TRIATOMIC;
			break;
			
			
		case 27 : // touche ''echappe''
		case 'q':
		case 'Q':
			Linterface->a_dessiner.~CSystem();
			glutDestroyWindow( glutGetWindow() );
			exit(0);
			break;
			
		case 'a':
		case 'A':
			Linterface->getSystem().addpart( Linterface->type, 1 );
			if( !Linterface->getTimer_on())
				glutPostRedisplay();
			break;
			
		case 'M':
		case 'm':
			Linterface->getSystem().setEnceinte(Linterface->getSystem().getEnceinte().getL()*1.05,
												Linterface->getSystem().getEnceinte().getH()*1.05,
												Linterface->getSystem().getEnceinte().getP()*1.05);
			break;
			
		case 'N':
		case 'n':
			Linterface->getSystem().setEnceinte(Linterface->getSystem().getEnceinte().getL()*0.95,
												Linterface->getSystem().getEnceinte().getH()*0.95,
												Linterface->getSystem().getEnceinte().getP()*0.95);
			break;	
		case 't':
		case 'T':
			Linterface->getSystem().setEnceinte(Linterface->getSystem().getEnceinte().getL()*5,
												Linterface->getSystem().getEnceinte().getH()*5,
												Linterface->getSystem().getEnceinte().getP()*5);
			break;
			
		case 'z':
		case 'Z':
		Linterface->getSystem().setEnceinte(Linterface->getSystem().getEnceinte().getL()*0.5,
												Linterface->getSystem().getEnceinte().getH()*0.5,
												Linterface->getSystem().getEnceinte().getP()*0.5);
		break;
			
		case 'h':
		case 'H':
			if(Linterface->getSystem().getList() != 0)
				Linterface->getSystem().getPart(0)->getOrb().setMaxpoints(5);
			break;
			
		case 'j':
		case 'J':
			if(Linterface->getSystem().getList() != 0)
				Linterface->getSystem().getPart(0)->getOrb().setMaxpoints(-5);
			break;
			
			//une part de 'type de moins
		case 'r':
		case 'R':
			Linterface->getSystem().rm(Linterface->type);
			break;
			
		case 'i':
		case'I':
			Linterface->ma_camera.zoom(1);
			break;
			
		case 'O':
		case 'o':
			Linterface->ma_camera.zoom(-1);
			break;
			
			
			// Change time ratio
		case '-':
			if(Linterface->ratio < 60)
			Linterface->ratio *= 1.1;
			break;
			
		case '+':
			if(Linterface->ratio >1)
			Linterface->ratio *= 0.9;
			break;
			
	}
}

void up_keyboard( unsigned char touche, int mouse_x, int mouse_y )
{
	
	switch (touche)
	{	
		case 'E':
		case 'e':		//!< mode de simulation.
			if (Linterface->simumode == 0)
				Linterface->simumode = 1;
			else Linterface->simumode = 0;
			
		case '1':
			(Linterface->type) = MONOATOMIC;
			break;
			
		case '2':
			Linterface->type = DIATOMIC;
			break;
			
		case '3':
			Linterface->type= TRIATOMIC;
			break;
			
			// Particules interactions 	
			// une orbite de moins
		case 'l':
		case 'L':
			Linterface->getSystem().lessorb(Linterface->type);
			break;
			
			//une orbite de plus
		case 'k':
		case 'K':
			Linterface->getSystem().addorb(Linterface->type);
			break;
			
			//rien qu'une orbite
		case 'D':
		case 'd':
			Linterface->getSystem().oneorb(Linterface->type);
			break;
			
		case 'f':
		case 'F':
			if( Linterface->fullscreen )
			{
				
				glutReshapeWindow( 800, 600 );
				glutPositionWindow( 10, -10 );
				Linterface->fullscreen=0;
			}
			else{
				
				glutFullScreen();
				Linterface->fullscreen = 1;
			}
			break;
			
		case ' ':// la barre espace est la touche pause
			if ( Linterface->getTimer_on() )
			{
				Linterface->a_dessiner.debug();
				Linterface->setTimer_on( false ); // arrÍte la simulation si Ètait en cours
			}
			else
			{
				
				// redemarre la simulation si arrete
				
				glutTimerFunc(1, simulation, 0);
				Linterface->setTimer_on( true ); 
				Linterface->setTemps( glutGet(GLUT_ELAPSED_TIME) ); // on peut ecrire aussi (*Linterface).getTemps()
			}
			break;
			
			//follows a particule
		case 's':
		case 'S':
			if(Linterface->ma_camera.getRiding() != 1 && Linterface->getSystem().getList() != 0)
			{
				Linterface->ma_camera.setAngles(0,0);
				Linterface->ma_camera.setRiding(1);
				for( unsigned int i(0); i < Linterface->getSystem().getList(); ++i )
				{
					Linterface->getSystem().getPart(i)->setDraworb( false);
				};
				
			}
			else Linterface->ma_camera.setRiding(0);
			glutPostRedisplay();
			break;
	}
}

void clavier_special( int touche, int mouse_x, int mouse_y )
{
	switch ( touche )
	{
		
		case GLUT_KEY_UP :
			Linterface->ma_camera.moveUD(1);
			break;
			
		case GLUT_KEY_DOWN:
			Linterface->ma_camera.moveUD(-1);
			break;
			
		case GLUT_KEY_LEFT:
			Linterface->ma_camera.moveLR(1);	
			break;
			
		case GLUT_KEY_RIGHT:
			Linterface->ma_camera.moveLR(-1);
			break;
			
		case GLUT_KEY_F4:
			Linterface->a_dessiner.save();
			//Linterface->ma_camera.save();
			//Linterface->save();
			break;
			
		case GLUT_KEY_F5:
			CParser p("save.xml");
			p.load(Linterface->a_dessiner);//, Linterface->ma_camera);
			glutPostRedisplay();
			break;
			
	}
	
	
}

void mouse_clic( int button , int state , int mouse_x , int mouse_y )
{
	//On enregistre la valeur de la position de mouse quand le bouton de gauche est appuye
	if( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ) 	{
		Linterface->mouse_x = mouse_x;
		Linterface->mouse_y = mouse_y; 
		Linterface->leftMouse = true;
	}
	else if(button ==GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		Linterface->leftMouse = false;
	}
}

void mouse_rotate(int x, int y)
{	
	if (Linterface->leftMouse)
	{
		Linterface->ma_camera.setAngle1( Linterface->ma_camera.getAngle1() - (x - Linterface->mouse_x)*0.5 );
		Linterface->ma_camera.setAngle2( Linterface->ma_camera.getAngle2() - (y - Linterface->mouse_y)*0.5);
		Linterface->mouse_x = x;
		Linterface->mouse_y = y; 
	}
	
}

void passive_mouse(int x, int y)
{
	Linterface->mouse_x = x;
	Linterface->mouse_y = y;
}

void simulation ( int id )
{
	
	unsigned int now( glutGet( GLUT_ELAPSED_TIME ) );
	double dt( now - Linterface->getTemps() ); // change le pas de temps defini dans la classe CSystem
	
	Linterface->setTemps( now );
	
	// mise a jour des positions
	if (Linterface->simumode == 0)
	Linterface->a_dessiner.update( dt / Linterface->ratio );
	
	else 	Linterface->a_dessiner.updatebest( dt / Linterface->ratio );

	glutPostRedisplay();
	if ( Linterface->getTimer_on() )
	{
		glutTimerFunc( 15, simulation , 0 );
	}
	
}



void Add_Part( int i )
{
	Linterface->getSystem().addpart( i, 1 );
}

void Add_Orb( int i )
{
	Linterface->getSystem().addorb(i);
}

void Show( int i )
{
	Linterface->getSystem().setAllbut( true, i );
	
	switch(i)
	{
		case 4:
			for( unsigned int j(1); j<4; ++j )
			{
				Linterface->getSystem().setAll( true, j );
			}
			break;
			
		case 5:
			Linterface->getSystem().oneorb(MONOATOMIC);
			++ Linterface->type;
			break;
	}
	glutPostRedisplay();
	
	
}

void Clear( int i )
{
	Linterface->getSystem().rm(i);
	
	if (i == 27)
	{
		Linterface->getSystem().clear();
		if(Linterface->ma_camera.getRiding() == 1)
			Linterface->ma_camera.setRiding(0);
	}
	
}

void Clear_More( int i )
{
	Linterface->getSystem().rmAll(i);
}

void menu_void( int i )
{
	cout<< endl << "breakpoint" << endl;
	
	switch(i)
	{
		case 20:
			Linterface->getSystem().clear();// faire un delete pr chaque particule
			Linterface->getSystem().setEnceinte(LENGTH, HEIGHT, DEPTH);
			Linterface->getSystem().addpart(MONOATOMIC, NB_MONO);
			Linterface->getSystem().addpart(DIATOMIC, NB_DI);
			Linterface->getSystem().addpart(TRIATOMIC, NB_TRI);
			glutPostRedisplay();
			break;
			
		case 27:
			Linterface->getSystem().~CSystem();
			glutDestroyWindow( glutGetWindow() );
			exit(0);
	}
	
}

void menu()
{	int menu1;
	int submenu1, submenu2, submenu3, submenu4;
	int subsub1;
	
	submenu1 = glutCreateMenu( Add_Part );
	glutAddMenuEntry( "Monoatomic", MONOATOMIC );
	glutAddMenuEntry( "Diatomic", DIATOMIC );
	glutAddMenuEntry( "Triatomic", TRIATOMIC );
	
	submenu2 = glutCreateMenu( Add_Orb );
	glutAddMenuEntry( "Monoatomic", MONOATOMIC );
	glutAddMenuEntry( "Diatomic", DIATOMIC );
	glutAddMenuEntry( "Triatomic", TRIATOMIC );
	
	submenu3 = glutCreateMenu( Show );
	glutAddMenuEntry( "Monoatomic", MONOATOMIC );
	glutAddMenuEntry( "Diatomic", DIATOMIC );
	glutAddMenuEntry( "Triatomic", TRIATOMIC );
	glutAddMenuEntry( "All", 4 );
	glutAddMenuEntry( "Only one orbit", 5 );

	
	subsub1 = glutCreateMenu( Clear_More );
	glutAddMenuEntry( "Monoatomic", MONOATOMIC );
	glutAddMenuEntry( "Diatomic", DIATOMIC );
	glutAddMenuEntry( "Triatomic", TRIATOMIC );
	
	
	submenu4 = glutCreateMenu( Clear );
	glutAddMenuEntry( "Monoatomic", MONOATOMIC );
	glutAddMenuEntry( "Diatomic", DIATOMIC );
	glutAddMenuEntry( "Triatomic", TRIATOMIC );
	glutAddSubMenu( "All", subsub1 );
	glutAddMenuEntry( "Clean system!", 27 );
	
	menu1 = glutCreateMenu( menu_void );
	glutAddSubMenu( "Add a particule of type", submenu1 );
	glutAddSubMenu( "Add an orbit to a particule of type", submenu2 );
	glutAddSubMenu( "Show only particules of type", submenu3 );
	glutAddSubMenu( "Clear", submenu4 );
	glutAddMenuEntry( "Default Configuration", 20 );
	glutAddMenuEntry( "Quit", 27 );
	
	
	glutSetMenu( menu1 );
	glutAttachMenu( GLUT_RIGHT_BUTTON );
}

void GUI::save() const
{
	string file_name("save");
	
	ofstream file(file_name.c_str());
	
		if(file.fail()){ 
			cerr << "Error: saved_file could not be written on." << endl;
		}
	else
	{ 
		Linterface->ma_camera.save(file);
	//	Linterface->a_dessiner.save(file);
	}
	
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

