#pragma once
#include "Malla.h"
#include "GL\freeglut.h"

class Camara
{
public:
	Camara(PuntoVector3D* eyep,	PuntoVector3D* lookp, PuntoVector3D* upp);
	~Camara();

private:
	PuntoVector3D* eye;
	PuntoVector3D* look;
	PuntoVector3D* up;
	PuntoVector3D* u;
	PuntoVector3D* v;
	PuntoVector3D* n;

	GLdouble left;
	GLdouble right;
	GLdouble top;
	GLdouble bottom;
	GLdouble Near;
	GLdouble Far;
	GLdouble fovy;
	GLdouble aspect;
};

