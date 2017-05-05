#pragma once
#include "..\Release\Malla.h"
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
	void rMatriz();


private:

	GLfloat a;
	GLfloat b;
	GLfloat c;

	//ni puta idea de pa q
	GLfloat t;

	GLfloat r;//radio

	int nP;//nº lados poligon
	int nQ;//nº poligon
	GLfloat m[16];
	PuntoVector3D** perfil;

};

