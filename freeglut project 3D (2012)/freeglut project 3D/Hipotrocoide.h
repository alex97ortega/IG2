#pragma once
#include "Malla.h"
#include "GL\freeglut.h"
class Hipotrocoide : public Malla
{
public:
	Hipotrocoide(int nump, int numq, GLfloat aparam, GLfloat bparam, GLfloat cparam);
	virtual ~Hipotrocoide();
	PuntoVector3D* C(GLfloat t);
	PuntoVector3D* C’(GLfloat t);
	PuntoVector3D* C’’(GLfloat t);
	PuntoVector3D* T(GLfloat t);
	PuntoVector3D* B(GLfloat t);
	PuntoVector3D* N(GLfloat t);

	void cPerfil();


private:

	GLfloat a;
	GLfloat b;
	GLfloat c;

	GLfloat r;

	GLfloat t;

	GLfloat tGrados;

	int nP;//nº lados poligon
	int nQ;//nº poligon
	GLfloat m[16];
	PuntoVector3D** perfil;

	PuntoVector3D* transformar(PuntoVector3D* i);
	void cMatriz(GLfloat t);
	PuntoVector3D* norWell(Cara* c);

};

