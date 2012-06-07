/*------------------------------------------------------------------------

Creation Date	: 	13.06.2007
Description	:	Class used to parse configuration files for the project.
Can read data from a file and construct a System from
it (or throw an exception if the read fails), or write
the data of the current System into a file.
Parent of	:       none
Child of	:		none
Methods	:       a lot
Dependencies	:	string, fstream, sstream, everything used
by CSystem

------------------------------------------------------------------------*/

#ifndef _CPARSER_H_
#define _CPARSER_H_

// INCLUDES

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "CSystem.h"
#include "GLGUI.h"
using namespace std;

class CParser
{
public:
	CParser(string file_name);
	virtual ~CParser();
	
	void load(CSystem& system, Camera& cam);
	void load(CSystem& system);
	
	//Balises
	
	static string b_CSystem;
	static string b_CSystem_end;
	
	static string b_comment;
	static string b_comment_end;
	
	static string b_CPart;
	static string b_CPart_end;
	
	static string b_type;
	static string b_type_end;
	
	static string b_pos;
	static string b_pos_end;
	
	static string b_vel;
	static string b_vel_end;
	
	static string b_CColor;
	static string b_CColor_end;
	
	static string b_Mass;
	static string b_Mass_end;
	
	static string b_CEnceinte;
	static string b_CEnceinte_end;
	
	 
	static string b_Camera;
	static string b_Camera_end;
	
	static string b_Angle1;
	static string b_Angle1_end;
	
	static string b_Angle2;
	static string b_Angle2_end;
	
	static string b_step;
	static string b_step_end;
	
	static string b_riding;
	static string b_riding_end;
	
	// Enumeration of different types
	
	enum tag{COMMENT, COMMENT_END, UNKNOWN_TAG,
		CSYSTEM, CSYSTEM_END,
		CENCEINTE, CENCEINTE_END,
		CPART, CPART_END,
		TYPE, TYPE_END,
		POS, POS_END,
		VEL, VEL_END,
		COLOR, COLOR_END,
		MASS, MASS_END,
		
		
		CAMERA, CAMERA_END,
		ANGLE1, ANGLE1_END,
		ANGLE2, ANGLE2_END,
		STEP, STEP_END,
		RIDING, RINDING_END};
	
	//returns next word in file
	string extract_word();
	
	string extract_string();
	
	//returns next tag
	int extract_tag();
	
	//Skips comment
	void skip_comment();
	
	//returns int or double extracted
	double extract_double();
	int extract_int();
	
	//returns vectors
	CVector3D extract_vector();
	CVector3D extract_pos();
	CVector3D extract_vel();
	
	//returns enceinte
	CEnceinte extract_enceinte();
	
	double extract_angle();
	double extract_step();
	
	//CPart
	void extract_part(CSystem& system);
	
	//returns type
	int extract_type();
	
	CColor extract_color();
	
	double extract_mass();
	
	void extract_enceinte(CSystem& system);
	
private:
		ifstream file;
	string txt;
	int head_pos;
};	
#endif

