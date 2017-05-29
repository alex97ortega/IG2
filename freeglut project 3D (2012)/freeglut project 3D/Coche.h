#pragma once
#include "GL\freeglut.h"
class Coche 
{
public:
	Coche();
	~Coche();

	void dibuja(GLdouble s, GLdouble rot);

	GLUquadric* o;

};

