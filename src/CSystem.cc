#include "CSystem.h"

//Constructeurs-----------------------------

CSystem::CSystem()
: listp(), e() {}

CSystem::CSystem(double h, double l, double p)
: listp(), e(h, l, p) {}

//CSystem::CSystem(CSystem& s) {
//	*this = s;
//}

CSystem::~CSystem() {
	for (unsigned int i(0); i<listp.size(); ++i){
		delete listp[i];
	}
	cout << "System destroyed" << endl;
}

//Methodes--------------------

void CSystem::addpart(CPart* mol) {		
	listp.push_back(mol);
}

void CSystem::addpart() {
	unsigned int type(0);
	unsigned int n(0);
	string end;
	CPart* m;
	do 
	{	cout << "Which type of molecule do you want to add?" << endl;
		cout << "Mono : " << MONOATOMIC << endl;
		cout << "Di :   " << DIATOMIC << endl;
		cout << "Tri :  " << TRIATOMIC << endl;
		do {
			cin >> type;}
		while(type > 3 || type < 1);
		
		cout << "How many?	:";
		cin >> n;
		
		cout << "Is that all you want to add? Y/N : ";
		do {
			cin >> end;
			if (end != "Y" && end !="y" && end !="n" && end!="N")
				cerr << "That's not an answer!	:";
		}
		while (end != "Y" && end !="y" && end !="n" && end!="N");
		
		switch(type) 
		{
			case MONOATOMIC :for( unsigned int i(0); i < n ; ++i)
			{	m= new CMono(getEnceinte().getL(), getEnceinte().getH(), getEnceinte().getP(), t);
				addpart(m);
			};
				break;
			case DIATOMIC :for( unsigned int i(0); i < n ; ++i)
			{	m= new CDi(getEnceinte().getL(), getEnceinte().getH(), getEnceinte().getP(), t);
				addpart(m);
			};
				break;
			case TRIATOMIC :for( unsigned int i(0); i < n ; ++i)
			{	m= new CTri(getEnceinte().getL(), getEnceinte().getH(), getEnceinte().getP(), t);
				addpart(m);
			};
				break;
			default:cout << "Then I guess you don't want to add anything" << endl;
		}
		cout << "done." << endl;
	}
	while(end != "y" && end!= "Y");
}

void CSystem::addpart(unsigned int type, unsigned int n) {
	CPart* m;
	switch(type) 
	{
		case MONOATOMIC :for( unsigned int i(0); i < n ; ++i)
		{	m= new CMono(getEnceinte().getL(), getEnceinte().getH(), getEnceinte().getP(), t);
			addpart(m);
		};
			break;
		case DIATOMIC :for( unsigned int i(0); i < n ; ++i)
		{	m= new CDi(getEnceinte().getL(), getEnceinte().getH(), getEnceinte().getP(), t);
			addpart(m);
		};
			break;
		case TRIATOMIC :for( unsigned int i(0); i < n ; ++i)
		{	m= new CTri(getEnceinte().getL(), getEnceinte().getH(), getEnceinte().getP(), t);
			addpart(m);
		};
			break;
		default:cout << "Error" << endl;
	}
	cout << n << " particules of type ";
	switch(type)
	{
		case MONOATOMIC: cout << "Mono";
			break;
		case DIATOMIC: cout << "Di";
			break;
		case TRIATOMIC: cout << "Tri";
			break;
	}
	cout << " were added to the system." << endl;
	
}



CPart* CSystem::getPart(int i) const
{
	return listp[i];
}

int CSystem::getList() const
{
	return listp.size();
}

void CSystem::clear() {
	for (unsigned int i(0); i<listp.size(); ++i){
		
		delete listp[i];
	}
	
	listp.clear();
}

void CSystem::draw() const {
	//Drawing cell.
	glPushMatrix();
	glTranslated(-e.getL()/2, -e.getH()/2, -e.getP()/2);
	
	glBegin(GL_QUAD_STRIP);
	glColor4d(e.getCol().getRed()*1.25, e.getCol().getGreen(), e.getCol().getBlue(), e.getCol().getAlpha()*0.9);
	glVertex3d(0.0f, 0.0f, 0.0f);
	glVertex3d(e.getL(), 0.0f, 0.0f);
	glVertex3d(0.0f, 0.0f, e.getP());
	glVertex3d(e.getL(), 0.0f, e.getP());
	
	glColor4d(e.getCol().getRed(), e.getCol().getGreen(), e.getCol().getBlue(), e.getCol().getAlpha());
	glVertex3d(0.0f, e.getH(), e.getP());
	glVertex3d(e.getL(), e.getH(), e.getP());
	glVertex3d(0.0f, e.getH(), 0.0f);
	glVertex3d(e.getL(), e.getH(), 0.0f);
	
	glColor4d(e.getCol().getRed()*1.25, e.getCol().getGreen(), e.getCol().getBlue(), e.getCol().getAlpha()*0.9);
	glVertex3d(0.0f, 0.0f, 0.0f);
	glVertex3d(e.getL(), 0.0f, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor4d(e.getCol().getRed(), e.getCol().getGreen(), e.getCol().getBlue(), e.getCol().getAlpha());
	glVertex3d(0.0f, 0.0f, 0.0f);
	glVertex3d(0.0f, e.getH(), 0.0f);
	glVertex3d(0.0f, e.getH(), e.getP());
	glVertex3d(0.0f, 0.0f, e.getP());
	
	glVertex3d(e.getL(), e.getH(), 0.0f);
	glVertex3d(e.getL(), e.getH(), e.getP());
	glVertex3d(e.getL(), 0.0f, e.getP());
	glVertex3d(e.getL(), 0.0f, 0.0f);
	glEnd();
	
	// WireCube
	glBegin(GL_LINES);
	glColor4d(e.getCol().getRed()*1.5, e.getCol().getGreen()*1.5, e.getCol().getBlue()*1.5, e.getCol().getAlpha()*1.5);
	
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(e.getL(), 0.0f, 0.0f);
	
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, e.getH(), 0.0f);
	
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, e.getP());
	
	glVertex3f(e.getL(), 0.0f, 0.0f);
	glVertex3f(e.getL(), 0.0f, e.getP());
	
	glVertex3f(e.getL(), 0.0f, 0.0f);
	glVertex3f(e.getL(), e.getH(), 0.0f);
	
	glVertex3f(0.0f, e.getH(), 0.0f);
	glVertex3f(e.getL(), e.getH(), 0.0f);
	
	glVertex3f(e.getL(), 0.0f, e.getP());
	glVertex3f(e.getL(), e.getH(), e.getP());
	
	glVertex3f(e.getL(), e.getH(), 0.0f);
	glVertex3f(e.getL(), e.getH(), e.getP());
	
	glVertex3f(0.0f, 0.0f, e.getP());
	glVertex3f(e.getL(), 0.0f, e.getP());
	
	glVertex3f(0.0f, e.getH(), 0.0f);
	glVertex3f(0.0f, e.getH(), e.getP());
	
	glVertex3f(0.0f, e.getH(), e.getP());
	glVertex3f(e.getL(), e.getH(), e.getP());
	
	glVertex3f(0.0f, e.getH(), e.getP());
	glVertex3f(0.0f, 0.0f, e.getP());
	glEnd();
	
	
	//Drawing particules
	
	for (vector<CPart*>::const_iterator i(listp.begin()); i < listp.end(); ++i)
	{
	if ((**i).getDraw() == true)
		(*i)->draw();
		
	if((**i).getDraworb() == true)
		(**i).getOrb().draw((**i).getCol());
	}
	glPopMatrix();
}
void CSystem::setEpsilon(double eps) {
	this->epsilon = eps;
}

void CSystem::setMaxpoints(int max) {
	this->maxPoints = max;
}

void CSystem::setTemp(double t) {
	this->t = t;
}

void CSystem::setEnceinte(double l, double h, double d) {
	this->e.setL(l);
	this->e.setH(h);
	this->e.setP(d);
}

CEnceinte CSystem::getEnceinte() {
	return this-> e;
}
double CSystem::getEcin() const {
	double ecin(0);
	for (unsigned int i(0); i < listp.size(); ++i)
	{ ecin += pow( (*listp[i]).getVel().getNorm(),2) *  listp[i]->getMass() / 2;}
	return ecin;
}

//Dynamic interactions on particules

void CSystem::rm(unsigned int type) {
	for(vector<CPart*>::iterator i(listp.begin()); i < listp.end(); ++i)
		if( (*i)->getType() == type)
		{
			delete *i;
			listp.erase(i);
			break;
		}
}

void CSystem::rmAll(unsigned int type) {
	for(vector<CPart*>::iterator i(listp.begin()); i < listp.end(); ++i)
		if( (*i)->getType() == type)
		{
			delete *i;
			listp.erase(i);
			
		}
}

void CSystem::setAll (bool active, unsigned int type) {
	for(vector<CPart*>::iterator i(listp.begin()); i < listp.end(); ++i)
	{
		if ( (*i)->getType() == type)
			(**i).setDraw(active);
	}
}

void CSystem::setAllbut(bool active, unsigned int type) {
	for(vector<CPart*>::iterator i(listp.begin()); i < listp.end(); ++i)
	{	cout << "test" << endl;
		if((*i)->getType() != type)
			(**i).setDraw(!active);
		if((*i)->getType() != type)
			(**i).setDraw(!active);
	}
}

void CSystem::addorb(unsigned int type) {
	
	for(vector<CPart*>::iterator i(listp.begin()); i < listp.end(); ++i)
		if((*i)->getType() == type && (**i).getDraworb() == false)
		{	(**i).setDraworb(true);
			break;
		}
}

void CSystem::lessorb(unsigned int type) {
	for(vector<CPart*>::iterator i(listp.begin()); i < listp.end(); ++i)
		if((*i)->getType() == type && (**i).getDraworb() == true)
		{	(**i).setDraworb(false);
			break;
		}
			
			/*int i(0);//listp.size()-1);
			do
		{
			if(listp[i]->getType() == type && (*listp[i]).getDraworb() == true)
			{	(*listp[i]).setDraworb(false);
				break;
			}
			++i;
		}
			while(listp[i]->getType());// != type || i != 0);*/
}

void CSystem::oneorb(unsigned int type)
{
	for(vector<CPart*>::iterator i(listp.begin()); i < listp.end(); ++i)
	{
		(**i).setDraw(false);
	}
	
	for(vector<CPart*>::iterator i(listp.begin()); i < listp.end(); ++i)
	{
		if((*i)->getType() == type)
		{	(**i).setDraworb(true);
			(**i).setDraw(true);
			break;
		}
	}
}
	
void CSystem::setColorset()
{	unsigned int type(0);
	colorset = 1;
	if(colorset == 1)
	{
		for(vector<CPart*>::iterator i(listp.begin()); i < listp.end(); ++i)
		{
			if((*i)->getType() == type)
			{
				++type;
				if (type ==MONOATOMIC)
					(*i)->setCol(0.80392, 0.17647, 0.31765, 0.8);
				
				else if (type == DIATOMIC)
					(*i)->setCol(0.23529, 0.72549, 0.81569, 0.8);
				
				else if (type == TRIATOMIC)
					(*i)->setCol(0.49412, 0.062745, 0.42353, 0.8);
			}
		}
		colorset = 2;
	}
	if(colorset == 2)
	{
		for(vector<CPart*>::iterator i(listp.begin()); i < listp.end(); ++i)
			if((*i)->getType() == type)
			{
				++type;
				if (type ==MONOATOMIC)
					(*i)->setCol(0, 0.52941, 0.83922, 0.8);
				
				else if (type == DIATOMIC)
					(*i)->setCol(0.42353, 0.72549, 0.2, 0.8);
				
				else if (type == TRIATOMIC)
					(*i)->setCol(0.80392, 0.40392, 0.12157, 0.8);
			}
				colorset = 1;
	}
}


//UPDATE DU SYSTEME!---------------------------------------------------
void CSystem::update(double dt) {			//Methode 1
	
	
	for (vector<CPart*>::iterator i(listp.begin()); i < listp.end(); ++i) 
	{
		
		(**i).updatep(dt);					//update de chaque position.
		
		// Check de choc avec paroi et modification de la position et de la vitesse si besoin.
		
		if (((**i).getPos()).getX() > e.getL()) {
			(**i).updatepX(e.getL());}				//update de la position et de la vitesse en cas de p.x > enceinte.getLargeur
		
		if ((**i).getPos().getY() > e.getH()) {
			(**i).updatepY(e.getH());}				//update de la position et de la vitesse en cas de p.y > enceinte.getHauteur
		
		if (((**i).getPos()).getZ() > e.getP()) {
			(**i).updatepZ(e.getP());}				//update de la position et de la vitesse en cas de p.z > enceinte.getProf
		
		if (((**i).getPos()).getX() < 0) {
			(**i).updatepX0();}					//update de la position et de la vitesse en cas de p.x < 0
		
		if (((**i).getPos()).getY() < 0) {
			(**i).updatepY0();}						//update de la position et de la vitesse en cas de p.y < 0
		
		if (((**i).getPos()).getZ() < 0) {
			(**i).updatepZ0();}						//update de la position et de la vitesse en cas de p.z < 0
		
		if ((**i).getDraworb() == true)
			(**i).updateorb();
		
		//Choc inter-particule.-------------------------------------------------------------
		
		/*		for (int j(i+1); j < listp.size(); ++j) {						//Check de choc pr ttes les part suivantes dans s.listp.
			if ( abs( (**i).getPos().getX() - (*listp[j]).getPos().getX() ) < epsilon) 
		{
				if ( abs( (**i).getPos().getY() - (*listp[j]).getPos().getY() ) < epsilon) 
				{	
					if ( abs( ( (**i).getPos() ).getZ() - ( (*listp[j]).getPos() ).getZ() ) < epsilon) 
					{		(**i).updatev(*listp[j]);
					}													
					else continue;											//si i.p.x != j.p.x alors continue
				}
				else continue;												// sinon on risque d'updater une part avec les nouvelles donnees. une autre possibilite serait de
		}
		else continue;													//memoriser la position precedente et d'utiliser celle la. De toute manière, il faut savoir avec
		}	
	};*/																	//quelle particule le choc a eu lieu.
		
		for (vector<CPart*>::iterator j(i+1); j < listp.end(); ++j) {								// pavage spherique
			if (abs(((**i).getPos()-(**j).getPos()).getNorm()) < epsilon)
				(**i).updatev(**j);
		};
	};
}

void CSystem::updatebest(double dt) {			//Methode 2
	

			 map < string, vector <CPart*> > _3Dspace;
 
       for (vector<CPart*>::iterator i(listp.begin()); i < listp.end(); ++i) 
	   {
               int x((int) floor( (**i).getPos().getX()) );
               int y((int) floor( (**i).getPos().getY()) );
               int z((int) floor( (**i).getPos().getZ()) );
			   
			   ostringstream oss;
			   string xx, yy, zz;
 
               /* As particle radii are all greater then 1 and around 2
                  so it's absurd to have cubes of 100pm length so I
                  made them of 300pm and the improvement was clear     */
               x = x % 3 ? x - x % 3 : x; oss << x; xx = oss.str();
               y = y % 3 ? y - y % 3 : y; oss << y; yy = oss.str();
               z = z % 3 ? z - z % 3 : z; oss << z; zz = oss.str();
 
               string pos( xx + yy + zz );
 
               _3Dspace[pos].push_back( *i );
 
               // the probability to have more than two particles in a 100pm length cube is so little that I chose not to take care of it  
               if ( _3Dspace[pos].size() == 2 )
					_3Dspace[pos][0]->updatev( *(_3Dspace[pos][1]) );
			}
		for (vector<CPart*>::iterator i(listp.begin()); i < listp.end(); ++i) 
	{	
		(**i).updatep(dt);					//update de chaque position.
		
		// Check de choc avec paroi et modification de la position et de la vitesse si besoin.
		
		if (((**i).getPos()).getX() > e.getL()) {
			(**i).updatepX(e.getL());}				//update de la position et de la vitesse en cas de p.x > enceinte.getLargeur
		
		if ((**i).getPos().getY() > e.getH()) {
			(**i).updatepY(e.getH());}				//update de la position et de la vitesse en cas de p.y > enceinte.getHauteur
		
		if (((**i).getPos()).getZ() > e.getP()) {
			(**i).updatepZ(e.getP());}				//update de la position et de la vitesse en cas de p.z > enceinte.getProf
		
		if (((**i).getPos()).getX() < 0) {
			(**i).updatepX0();}					//update de la position et de la vitesse en cas de p.x < 0
		
		if (((**i).getPos()).getY() < 0) {
			(**i).updatepY0();}						//update de la position et de la vitesse en cas de p.y < 0
		
		if (((**i).getPos()).getZ() < 0) {
			(**i).updatepZ0();}						//update de la position et de la vitesse en cas de p.z < 0
		
		if ((**i).getDraworb() == true)
			(**i).updateorb();
	};
	
}

void CSystem::debug()
{
			for (vector<CPart*>::iterator i(listp.begin()); i < listp.end(); ++i) 
	{			
		// Check de choc avec paroi et modification de la position et de la vitesse si besoin.
		
		if (((**i).getPos()).getX() > e.getL()) {
			(**i).updatepX(e.getL());}				//update de la position et de la vitesse en cas de p.x > enceinte.getLargeur
		
		if ((**i).getPos().getY() > e.getH()) {
			(**i).updatepY(e.getH());}				//update de la position et de la vitesse en cas de p.y > enceinte.getHauteur
		
		if (((**i).getPos()).getZ() > e.getP()) {
			(**i).updatepZ(e.getP());}				//update de la position et de la vitesse en cas de p.z > enceinte.getProf
		
		if (((**i).getPos()).getX() < 0) {
			(**i).updatepX0();}					//update de la position et de la vitesse en cas de p.x < 0
		
		if (((**i).getPos()).getY() < 0) {
			(**i).updatepY0();}						//update de la position et de la vitesse en cas de p.y < 0
		
		if (((**i).getPos()).getZ() < 0) {
			(**i).updatepZ0();}						//update de la position et de la vitesse en cas de p.z < 0
		
		if ((**i).getDraworb() == true)
			(**i).updateorb();
	};
}
//Operateur

ostream& operator<<(ostream& o, const CSystem& s) {
	o << "Le systeme est compose des " << s.listp.size() << " particules suivantes :" << endl;
	for (unsigned int i(0); i < s.listp.size(); i++) {
		o << "Particule " << i+1 << ":" << endl;
		o << *s.listp[i] << endl;
		o << endl;							 
	}
	o << "Energie cinetique du systeme : " << s.getEcin() << " [m^2*kg / s^2]" << endl;
	return o;
}

//Initialisation of system

void CSystem::init()
{
	
	string rep;
	CHazard h;
	
	cout << "Default configuration? Y/N" << endl;
	do {
		cin >> rep;
		if (rep != "Y" && rep !="y" && rep !="n" && rep!="N" && rep !="test" && rep!="TEST" && rep !="t" && rep!="T")
			cerr << "Try again, you fool!	:";
	}
	while (rep != "Y" && rep !="y" && rep !="n" && rep!="N" && rep !="test" && rep!="TEST" && rep !="t" && rep!="T");	
	//--------------------------------------------------------
	if (rep == "N" || rep =="n")
	{
		cout << "Configure size of box? Y/N" << endl;
		do {
			cin >> rep;
			if (rep != "Y" && rep !="y" && rep !="n" && rep!="N")
				cout << "Try again, you fool!	:";}
		while (rep != "Y" && rep !="y" && rep !="n" && rep!="N");
		
		if (rep == "Y" || rep =="y")
		{double e1, e2, e3;
			
			cout << "Length of the box : " << endl;
			do {
				cin >> e1;
				if (e1 <= 0 || e1 >= e.getMax())
					cout << "Please enter a value between 0 and " << e.getMax() << " :";	}
			while (e1 <= 0 || e1 >= e.getMax());
			
			cout << "Height of the box : " << endl;
			do {
				cin >> e2;
				if (e2 <= 0 || e2 >= e.getMax())
					cout << "Please enter a value between 0 and " << e.getMax() << " :";	}
			while (e2 <= 0 || e2 >= e.getMax());
			
			cout << "Depth of the box : " << endl;
			do {
				cin >> e3;
				if (e3 <= 0 || e3 >= e.getMax())
					cerr << "Please enter a value between 0 and " << e.getMax() << " :";	}
			while (e3 <= 0 || e3 >= e.getMax());
			setEnceinte(e1, e2, e3);}
		
		else setEnceinte(LENGTH, HEIGHT, DEPTH);
		double t1;
		cout << "Temperature of system (°C) : " << endl;
		cin >> t1;
		t1 += 273.5;
		
		t = t1;
		
		addpart();
	}
	//-------------------------------------------------------
	else if(rep == "y" || rep == "Y") {
		t = TEMP;	
		setEnceinte (LENGTH, HEIGHT, DEPTH);
		addpart(MONOATOMIC, NB_MONO);
		addpart(DIATOMIC, NB_DI);
		addpart(TRIATOMIC, NB_TRI);
	}
	
	else {
		t = 298;	
		setEnceinte (1000, 1000, 1200);
		addpart(MONOATOMIC, 300);
		addpart(DIATOMIC, 150);
		addpart(TRIATOMIC, 100);
	}
	
	setEpsilon(EPSILON);
	
	addorb(MONOATOMIC);
	addorb(DIATOMIC);
	addorb(TRIATOMIC);
	
	if (listp.size() > 0)
		(*listp[0]).getOrb().setMaxpoints(30);
	
	cout << "System initialized." << endl;
}

//Sauvegarde de la configuration actuelle dans un file sauvegarde.xml
void CSystem::save() const//const Camera& cam)
{	
	string file_name ("save");
	
	/*cout << "Please enter a file you would like to save to: " ;
	cin >> file_name;*/
		   file_name += ".xml";
	
	//On cree le flot qui va ecrire dans le file sauvegarde.xml
	ofstream file(file_name.c_str());
		
		//On teste si le file peut-etre ouvert
		if(file.fail()){ 
			cerr << "Error: saved_file could not be written on." << endl;
		}
		else
		{ 
			//On commence la sauvegarde de l'univers
			file << " <CSystem>" << endl;
			
			//file << "     " << "<!-- "<< "______.-PARTICULES-.______" << " -->" << endl;
			//On sauvegarde toutes les particules
			for(vector<CPart*>::const_iterator i(listp.begin()); i < listp.end(); ++i)
			{
				//On commence la sauvegarde de corps
				//file << "  " << "<!-- " << "Particule"<< i + 1 << " -->" << endl;
				
				file << " "<< "<Part>" << endl;
				file << "  " << "<Type> " << (*i)->getType() << " </Type>" << endl;
				file << "  " << "<Position> " << (**i).getPos().getX() << " " << (**i).getPos().getY() << " " << (**i).getPos().getZ() << " </Position>" << endl;
				file << "  " << "<Velocity> " << (**i).getVel().getX() << " " << (**i).getVel().getY() << " " << (**i).getVel().getZ() << " </Velocity>" << endl;
				file << "  " << "<Mass> " << (*i)->getMass() << " </Mass>" << endl;
				file << "  " << "<Color> " << (*i)->getCol().getRed() << " " << (*i)->getCol().getGreen() << " " << (*i)->getCol().getBlue() << " " << (*i)->getCol().getAlpha() << " </Color>" << endl;
				file << " " << "</Part>" << endl << endl;
			}
			
			file << "<Enceinte> " << e.getL() << " " << e.getH() << " " << e.getP() << " </Enceinte>" << endl;
			
			file << "</CSystem>" << endl;
			
			//On ferme le flot
			file.close(); 
			
			cout << "system saved "<<endl;// << file_name << endl;
		}
		
}
//EOF----------------------
