CXX=c++ -pg
CXXFLAGS= -g -Wall  
CC = c++

# Bibliotheques pour OpenGL et glut
 LDFLAGS  = -pg #-L/usr/X11R6/lib/ -pg 
LDLIBS   = -framework OpenGL -framework GLUT # mac
# LDLIBS =-lglut -lGLU -lGL -lXmu -lXi # linux/windows

#directions for making all objects/executables at once
all: Simu #Simutxt Projet des Gaz Parfaits de Walid et Pierre

# Construction of test programs

CVector3Dtest: 		CVector3Dtest.o CVector3D.o

CVector3Dtest.o:	CVector3D.h CVector3Dtest.cc

CParttest:		CParttest.o CPart.o CVector3D.o CColor.o COrbit.o CHazard.o

CParttest.o:		CPart.h CParttest.cc

CSystemtest:		CSystemtest.o CSystem.o CPart.o CEnceinte.o CVector3D.o CMono.o CDi.o CTri.o CColor.o COrbit.o CHazard.o

CSystemtest.o:		CSystem.h CSystemtest.cc

Simu.o:				Simu.cc GLGUI.h

Simu:				Simu.o CSystem.o CPart.o CEnceinte.o CVector3D.o CMono.o CDi.o CTri.o CColor.o COrbit.o CHazard.o GLGUI.o GLCamera.o CParser.o

Simutxt:			Simutxt.cc

Simulationtest.o:	Simulationtest.cc

Simulationtest:		Simulationtest.o CSystem.o CPart.o CEnceinte.o CVector3D.o CMono.o CDi.o CTri.o CColor.o COrbit.o CHazard.o

COrbittest.o:		COrbit.h COrbittest.cc

COrbittest:			COrbittest.o CColor.o CVector3D.o COrbit.o

#Construction of class objects					
CVector3D.o:		CVector3D.h CVector3D.cc

CPart.o:			CPart.h CPart.cc

CSystem.o:			CSystem.h CSystem.cc

CEnceinte.o:		CEnceinte.h CEnceinte.cc

CMono.o:			CMono.h CMono.cc

CDi.o:				CDi.h CDi.cc

CTri.o:				CTri.h CTri.cc

CColor.o:			CColor.h CColor.cc

COrbit.o:			COrbit.h COrbit.cc

CHazard.o:			CHazard.h CHazard.cc

CParser.o:			CParser.h CParser.cc

#Construction of GUI objects

GLGUI.o:	GLGUI.h GLGUI.cc

GLCamera.o:	GLCamera.h GLCamera.cc

#Cleaning up the mess
clean:				
	rm *.o #Cleaning up...

