#include "Hipotrocoide.h"
#include <math.h>

const GLfloat PI = 3.1415;

Hipotrocoide::Hipotrocoide(int nump, int numq, GLfloat aparam, GLfloat bparam, GLfloat cparam)
{
	nP = nump;
	nQ = numq;
	a = aparam;
	b = bparam;
	c = cparam;
	r = 20;

	numeroVertices = nP * nQ;
	numeroNormales = numeroVertices;
	numeroCaras = (nP -1) * (nQ - 1);
	vertice = new PuntoVector3D*[numeroVertices];
	normal = new PuntoVector3D*[numeroNormales];
	cara = new Cara*[numeroCaras];

/*	for (int i = 0; i <4; i++){
		for (int j = 0; j < 4; j++){
			switch (i)
			{
			case 0: 
				if (j == 3) m[i + j] = 0;
				else m[i + j] = B(t)->getX();
				break;
			case 1:
				if (j == 3) m[i + j] = 0;
				else m[i + j] = N(t)->getX();
				break;
			case 2:
				if (j == 3) m[i + j] = 0;
				else m[i + j] = T(t)->getX();
				break;
			case 3:
				if (j == 3) m[i + j] = 1;
				else m[i + j] = C(t)->getX();
				break;
			default:
				break;
			}			
		}
		    
	}
	*/

	


	/*
	for (int i = 2; i < p; i++)
		vertice[i] = new PuntoVector3D(r*cos(i * 2 * 3.14 / p), 0, r*sin(i * 2 * 3.14 / p), 1);

	for (int i = 0; i < p - 1; i++){

		VerticeNormal** aVN = new VerticeNormal*[3];
		aVN[0] = new VerticeNormal(0, 0);
		aVN[1] = new VerticeNormal(i + 1, 0);
		aVN[2] = new VerticeNormal(i, 0);
		cara[i] = new Cara(3, aVN);
		delete aVN;

		VerticeNormal** aVN = new VerticeNormal*[3];
		aVN[0] = new VerticeNormal(1, 0);
		aVN[1] = new VerticeNormal(i + 1, 0);
		aVN[2] = new VerticeNormal(i, 0);
		cara[p + i] = new Cara(3, aVN);
		delete aVN;

	}
	VerticeNormal** aVN = new VerticeNormal*[3];
	aVN[0] = new VerticeNormal(0, 0);
	aVN[1] = new VerticeNormal(numeroVertices - 1, 0);
	aVN[2] = new VerticeNormal(2, 0);
	cara[numeroCaras - 2] = new Cara(3, aVN);
	delete aVN;

	VerticeNormal** aVN = new VerticeNormal*[3];
	aVN[0] = new VerticeNormal(1, 0);
	aVN[1] = new VerticeNormal(numeroVertices - 1, 0);
	aVN[2] = new VerticeNormal(2, 0);
	cara[numeroCaras - 1] = new Cara(3, aVN);
	delete aVN;
	*/



}


Hipotrocoide::~Hipotrocoide()
{
}

PuntoVector3D* Hipotrocoide::C(GLfloat t){
	//Funcion de la curva
	return ((a - b)*cos(t) + c*cos(t*((a - b) / b)), 0, (a - b)*sin(t) - c*sin(t *((a - b) / b)), 0);
}
PuntoVector3D* Hipotrocoide::C’(GLfloat t){
	//1º derivada
	return(-1 * (a - b)*sin(t) + (-c*sin(t*((a - b) / b)) * ((a - b) / b)), 
		0, (a - b)*cos(t) - (c*cos(t*((a - b) / b)) * ((a - b) / b)), 0);

}
PuntoVector3D* Hipotrocoide::C’’(GLfloat t){
	//2º derivada
	return(-1 * (a - b)*cos(t) + (-c*cos(t*((a - b) / b))*((a - b) / b) * ((a - b) / b)), 0,
		-1 * (a - b)*sin(t) + (c*sin(t*((a - b) / b))*((a - b) / b)*((a - b) / b)), 0);
}
PuntoVector3D* Hipotrocoide::T(GLfloat t){
	
	PuntoVector3D* j = C’(t)->clonar();
	j->normalizar();
	return j;
}
PuntoVector3D* Hipotrocoide::B(GLfloat t){
	
	PuntoVector3D* j = C’’(t)->clonar();
	PuntoVector3D* i = C’(t)->clonar();
	PuntoVector3D* l = i->productoVectorial(j);
	l->normalizar();
	return l;
}
PuntoVector3D* Hipotrocoide::N(GLfloat t){

	PuntoVector3D* j = B(t)->clonar();
	PuntoVector3D* i = T(t)->clonar();
	PuntoVector3D* l = j->productoVectorial(i);
	return l;
}


void Hipotrocoide::cPerfil(){
	

	GLfloat inc = (2 * PI / nP);

	for (int i = 0; i < nP; i++){
		perfil[i] = new PuntoVector3D(r*cos(i*inc), r*sin(i*inc), 0, 1);
	}

}

void Hipotrocoide::rMatriz(){

	PuntoVector3D* b = B(t);
	PuntoVector3D* n = N(t);
	PuntoVector3D* tp = T(t);
	PuntoVector3D* c = C(t);

	m[0] = b->getX();
	m[1] = b->getY();
	m[2] = b->getZ();
	m[3] = 0;
	m[4] = n->getX();
	m[5] = n->getY();
	m[6] = n->getZ();
	m[7] = 0;
	m[8] = tp->getX();
	m[9] = tp->getY();
	m[10] = tp->getZ();
	m[11] = 0;
	m[12] = c->getX();
	m[13] = c->getY();
	m[14] = c->getZ();
	m[15] = 1;

	

}