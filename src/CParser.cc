#include "CParser.h"

CParser::CParser(string file_name) 
: file(file_name.c_str()) , head_pos(0)
{
	if(file.fail()){ 
		cerr << "Error: The file " << file_name << " could not be opened." << endl;
	}
	else
	{
		string word;
		while(!file.eof()){
			file >> word;
			txt += word + " ";
		}
		
		//On ajoute un espace apres chaque > et avant chaque <, au cas ou un attribut soit colle a une balise
		for(unsigned int i(0) ; i < txt.size() ; ++i)
		{
			if(txt[i] == '>')
			{
				txt.replace(i , 1 , "> ");
				i += 2;
			}
			
			if(txt[i] == '<')
			{
				txt.replace(i , 1 , " <");
				i += 2;
			}
		}
		//On supprime tous les doubles espaces
		while(txt.find("  ") != string::npos)
		{
			txt.replace(txt.find("  ") , 2 , " ");
		}
		
		//On supprime le tout premier espace
		txt.replace(0 , 1 , "");
		
		//On ferme le flot
		file.close(); 
	}
}


CParser::~CParser(){}

//Balises

string CParser::b_CSystem = "<CSystem>";
string CParser::b_CSystem_end = "</CSystem>";

string CParser::b_comment = "<!--";
string CParser::b_comment_end = "-->";

string CParser::b_CPart = "<Part>";
string CParser::b_CPart_end = "</Part>";

string CParser::b_type = "<Type>";
string CParser::b_type_end = "</Type>";

string CParser::b_pos = "<Position>";
string CParser::b_pos_end = "</Position>";

string CParser::b_vel = "<Velocity>";
string CParser::b_vel_end = "</Velocity>";

string CParser::b_CColor = "<Color>";
string CParser::b_CColor_end = "</Color>";

string CParser::b_Mass = "<Mass>";
string CParser::b_Mass_end = "</Mass>";

//string CParser::b_draw = "<Draw>";
//string CParser::b_draw_end = "</Draw>";

string CParser::b_CEnceinte = "<Enceinte>";
string CParser::b_CEnceinte_end = "</Enceinte>";

string CParser::b_Camera = "<Camera>";
string CParser::b_Camera_end = "</Camera>";

string CParser::b_Angle1  = "<UP&DOWN>";
string CParser::b_Angle1_end = "</UP&DOWN>";

string CParser::b_Angle2  = "<horiz_view>";
string CParser::b_Angle2_end = "</horiz_view>";

string CParser::b_step = "<Step>";
string CParser::b_step_end = "</Step>";

string CParser::b_riding = "<RidingPart>";
string CParser::b_riding_end = "</RidingPart>";

//Methods

double CParser::extract_double() 
{
	return atof(extract_word().c_str());
}

int CParser::extract_int()
{
	return atoi(extract_word().c_str());
}

//Returns next word in file
string CParser::extract_word()
{
	string word;
	
	//Building a word by adding char by char until there is a space
	for(int i(head_pos) ; txt[i] != ' ' ; ++i , ++head_pos)
	{
		word += txt[head_pos];
	}
	
	//Skipping space
	head_pos += 1;
	return word;
	
}

string CParser::extract_string()
{
	return extract_word();
}

int CParser::extract_tag() 
{
	
	//extracting next tag
	string next_tag(extract_word());
	cout << next_tag;
	//Now we compare it
	
	if(next_tag == b_CSystem){return CSYSTEM;}
	else if(next_tag == b_CSystem_end){return CSYSTEM_END;}
	
	else if(next_tag == b_comment){return COMMENT;}
	else if(next_tag == b_comment_end){return COMMENT_END;}
	
	else if(next_tag == b_CPart){return CPART;}
	else if(next_tag == b_CPart_end){return CPART_END;}
	
	else if(next_tag == b_type){return TYPE;}
	else if(next_tag == b_type_end){return TYPE_END;}
	
	else if(next_tag == b_pos){return POS;}
	else if(next_tag == b_pos_end){return POS_END;}
	
	else if(next_tag == b_vel){return VEL;}
	else if(next_tag == b_vel_end){return VEL_END;}
	
	else if(next_tag == b_Mass){return MASS;}
	else if(next_tag == b_Mass_end){return MASS_END;}
	
	else if(next_tag == b_CColor){return COLOR;}
	else if(next_tag == b_CColor_end){return COLOR_END;}
	
	//else if(next_tag == b_draw){return DRAW;}
	//	else if(next_tag == b_draw_end){return DRAW_END;}
	
	else if(next_tag == b_CEnceinte){return CENCEINTE;}
	else if (next_tag  == b_CEnceinte_end){return CENCEINTE_END;}
	
	else if(next_tag == b_comment){return COMMENT;}
	else if(next_tag == b_comment_end){return COMMENT_END;}
	
	else if(next_tag == b_Camera){return CAMERA;}
	else if(next_tag == b_Camera_end){return CAMERA_END;}
	
	else if(next_tag == b_step){return STEP;}
	else if(next_tag == b_step_end){return STEP_END;}
	
	else if(next_tag == b_Angle1){return ANGLE1;}
	else if(next_tag == b_Angle1_end){return ANGLE1_END;}
	
	else if(next_tag == b_Angle2){return ANGLE2;}
	else if(next_tag == b_Angle2_end){return ANGLE2_END;}
	
	
	else return UNKNOWN_TAG;
}

double CParser::extract_angle()
{
	return extract_double();
}

double CParser::extract_step()
{
	return extract_double();
}

CVector3D CParser::extract_vector()
{
	double x(extract_double());
	double y(extract_double());
	double z(extract_double());
	return CVector3D(x , y , z);
}

CVector3D CParser::extract_pos()
{	
	CVector3D pos(extract_vector());
	
	//checking if tag is ended
	if(extract_tag() != POS_END)
	{
		//On lance une erreur
		throw string("Position of particule un-ended");
	}
	
	return pos;
}

CVector3D CParser::extract_vel()
{	
	CVector3D vel(extract_vector());
	
	//checking if tag is ended
	if(extract_tag() != VEL_END)
	{
		//On lance une erreur
		throw string("Velocity of particule un-ended");
	}
	
	return vel;
}

/*bool CParser::extract_draw() 
{
	bool draw(extract_int());
	
	//checking if tag is ended
	if(extract_tag() != DRAW_END)
	{
		//On lance une erreur
		throw string("Draw bool of particule un-ended");
	}
	
	return draw;
}*/

//Part extraction +++++++++++++++++++++++++++++

//Skips next Comment
void CParser::skip_comment()
{
	//Utile pour lire les tags et garder la derniere version en memoire
	int next_tag(0);
	
	//On lit tant que l'on a des balises inconnues, ie le texte du commentaire
	for(next_tag = extract_tag() ; next_tag == COMMENT_END ; next_tag = extract_tag()){}
	
	//On regarde s'il y a une balise qui termine le commentaire
	if(next_tag != COMMENT_END)
	{
		//On lance une erreur
		throw string("Comment un-ended");
	}
}


int CParser::extract_type()
{
	int type(extract_int());
	
	//On regarde s'il s'agit d'un type que l'on connait
	if(type != MONOATOMIC && type != DIATOMIC && type != TRIATOMIC)
	{
		//On lance une erreur
		throw string("Unknown type");
	} 
	
	//On regarde s'il y a une balise qui termine le type
	if(extract_tag() != TYPE_END)
	{
		//On lance une erreur
		throw string("Type un-ended");
	}
	
	return type;
}

CColor CParser::extract_color()
{
	double red(extract_double());
	double green(extract_double());
	double blue(extract_double());
	double alpha(extract_double());
	
	CColor color(red, green, blue, alpha);
	
	//On regarde s'il y a une balise qui termine la couleur
	if(extract_tag() != COLOR_END)
	{
		//On lance une erreur
		throw string("Color un-ended");
	}
	
	return color; 
}


double CParser::extract_mass()
{	
	double mass(extract_double());
	
	//On regarde s'il y a une balise qui termine la masse
	if(extract_tag() != MASS_END)
	{
		throw string("Mass un-ended");
	}
	
	return mass;
}

void CParser::extract_part(CSystem& system)
{
	int type;
	CVector3D pos, vel;
	double mass;
	CColor color;
	CPart* p;
	
	//Checking each sub-tags
	for(int next_tag(extract_tag()) ; next_tag != CPART_END ; next_tag = extract_tag())
	{	
		//Astuce pour afficher le numero du corps qui pose probleme
		ostringstream message;
		
		switch(next_tag)
		{
			case TYPE:
				type = extract_type();
				break;
				
			case POS:
				pos = extract_pos();
				break;
				
			case VEL:
				vel = extract_vel();
				break;
				
			case MASS:
				mass = extract_mass();
				break;
				
			case COLOR:
				color = extract_color();
				break;
				
			case UNKNOWN_TAG :
				//On lance une erreur
				message << "There is an unknown tag in part "/* << system.getList.size() + 1*/ << " that should't be there"; //+1 car il est en construction , donc pas encore dans l'systeme
				throw string(message.str());
				break;
				
			case COMMENT:
				skip_comment();
				break;
			default :
				//On lance une erreur
				message << "There is an unknown tag in part "/* << system.getList.size() + 1*/ << " that should't be there"; //+1 car il est en construction , donc pas encore dans l'systeme
				throw string(message.str());
				break;
		}
	}	
	if(type == MONOATOMIC)
	{
		p = new CMono(pos, vel, mass, "Monoatomic");
		(*p).setDraw(true);
		system.addpart(p);
	}
	else if(type==DIATOMIC)
	{
		p = new CDi(pos, vel, mass, "Diatomic");
		(*p).setDraw(1);
		system.addpart(p);
	}
	else if(type==TRIATOMIC)
	{
		p = new CTri(pos, vel, mass, "Triatomic");
		(*p).setDraw(1);
		system.addpart(p);
	}
	else
	{
		ostringstream message; //Used to know which part is causing a problem.
		message << "Unknown type while constructing part ";// << system.getList.size() + 1; //+1 car il est en construction , donc pas encore dans le systeme
			throw string(message.str());
	}
	
}	

void CParser::extract_enceinte(CSystem& system) 
{
	double L(extract_double());
	double H(extract_double());
	double D(extract_double());
	system.setEnceinte(L , H , D);
}

	//Loads data in the system
	void CParser::load(CSystem& system, Camera& cam)
	{	
		try
	{
		
		//Used to read tags and save last tag read
		int next_tag(0);
		
		//Delete all comments
		for(next_tag =  extract_tag() ; next_tag == COMMENT ; next_tag = extract_tag())
		{
			skip_comment();
		}
		
		//Linterface = new GUI(argc , argv , system, "Gaz Parfait");
		
		//Checking if there is a system in file
		if(next_tag != CAMERA)
		{
			throw string("There is no Camera in this file");
		}
		
		double angle1, angle2, step;
		bool ridingpart;
		CVector3D position;
		//Reads until CAMERA_END
		if(next_tag == CAMERA)
		for(next_tag = extract_tag() ; next_tag != CAMERA_END ; next_tag = extract_tag())
		{	cout << next_tag;
			switch(next_tag)
			{
				case POS:
					position = extract_pos();
					break;
					
				case ANGLE1:
					angle1 = extract_angle();
					break;
					
				case ANGLE2:
					angle2 = extract_angle();
					break;
					
				case STEP:
					step = extract_step();
					break;
					
				case RIDING:
					ridingpart = extract_int();
					
				case COMMENT :
					skip_comment();
					break;
					
				case UNKNOWN_TAG :
					//throws an error
					throw string("Unknown tag in file (upper level)..");
					break;
					
				default :
					//Throws an error
					throw string("Something's wrong with the camera...");
					break;
			}
			
			
			
			cam.setStep(step);
			cam.setAngles(angle1, angle2);
			cam.setPosition(position);
			cam.setRiding(ridingpart);
		}
	}
	catch(string& error)
	{
		cerr << error << endl;
	}	
	//Pour partir a zero
	system.clear();
	//Error management
	try
	{
		
		//Used to read tags and save last tag read
		int next_tag(0);
		
		//Delete all comments
		for(next_tag =  extract_tag() ; next_tag == COMMENT ; next_tag = extract_tag())
		{
			skip_comment();
		}
		
		//Checking if there is a system in file
		if(next_tag != CSYSTEM)
		{
			throw string("There is no system in this file");
		}
		
		/*		//Unused as we won't take filenames directly from terminal.
			Linterface = new GUI(argc , argv , system, "Gaz Parfait");*/
		
		//Reads until CSYSTEM_END
		for(next_tag = extract_tag() ; next_tag != CSYSTEM_END ; next_tag = extract_tag())
		{	
			switch(next_tag)
			{
				case CENCEINTE :
					//sets enceinte
					extract_enceinte(system);
					break;
					
				case CPART :
					//adding a part to system
					extract_part(system);
					break;	
					
				case COMMENT :
					skip_comment();
					break;
					
				case UNKNOWN_TAG :
					//throws an error
					throw string("Unknown tag in file (upper level)..");
					break;
					
				default :
					//Throws an error
					throw string("Loaded");
					break;
			}
		}	
	}
	//Catching error
	catch(string& error)
	{
		cerr << error << endl;
	}
}

void CParser::load(CSystem& system)
{	system.clear();
	//Error management
	try{
		
		//Used to read tags and save last tag read
		int next_tag(0);
		
		//Delete all comments
		for(next_tag =  extract_tag() ; next_tag == COMMENT ; next_tag = extract_tag())
		{
			skip_comment();
		}
		
		//Checking if there is a system in file
		if(next_tag != CSYSTEM)
		{
			throw string("There is no system in this file");
		}
		
		/*		//Unused as we won't take filenames directly from terminal.
			Linterface = new GUI(argc , argv , system, "Gaz Parfait");*/
		
		//Reads until CSYSTEM_END
		for(next_tag = extract_tag() ; next_tag != CSYSTEM_END ; next_tag = extract_tag())
		{	
			switch(next_tag)
			{
				case CENCEINTE :
					//sets enceinte
					extract_enceinte(system);
					break;
					
				case CPART :
					//adding a part to system
					extract_part(system);
					break;	
					
				case COMMENT :
					skip_comment();
					break;
					
				case UNKNOWN_TAG :
					//throws an error
					throw string("Unknown tag in file (upper level)..");
					break;
					
				default :
					//Throws an error
					throw string("Loaded");
					break;
			}
		}	
	}
	//Catching error
	catch(string& error)
	{
		cerr << error << endl;
	}
}
//EOF