#pragma once
#include "Malla.h"
#include "GL\freeglut.h"

class Camara
{
public:
	Camara(PuntoVector3D* eyep,	PuntoVector3D* lookp, PuntoVector3D* upp);
	~Camara();
	void movRoll(GLfloat roll);

private:
	PuntoVector3D* eye;
	PuntoVector3D* look;
	PuntoVector3D* up;
	PuntoVector3D* u;
	PuntoVector3D* v;
	PuntoVector3D* n;

	GLfloat left;
	GLfloat right;
	GLfloat top;
	GLfloat bottom;
	GLfloat Near;
	GLfloat Far;
	GLfloat fovy;
	GLfloat aspect;

	GLfloat V[16];
	GLfloat V´[16];
	

	void darValores();
	void cMatriz();
	void inversa();
	
};

