#include "Hipotrocoide.h"
#include <math.h>
#include <iostream>



Hipotrocoide::Hipotrocoide(int nump, int numq, GLfloat aparam, GLfloat bparam, GLfloat cparam)
{
	nP = nump;
	nQ = numq;
	a = aparam;
	b = bparam;
	c = cparam;

	r = 1;

	numeroVertices = nP * nQ;
	numeroNormales = numeroVertices;
	numeroCaras = numeroVertices - nP; 
	vertice = new PuntoVector3D*[numeroVertices];
	normal = new PuntoVector3D*[numeroNormales];
	cara = new Cara*[numeroCaras];
	perfil = new PuntoVector3D*[nP];

	t = 0;

	tGrados = (5 * (2 * 3.1415926 / nQ));


	cPerfil();//creamos el perfil cuyo vertices dependen de nP
	//y luego calculamos la matriz
	cMatriz(t);// angulo cero
	
	//aplicamos a los vertices del primer pefil la transfaormacion (mover los vertices a la curva)
	for (int i = 0; i < nP; i++){
		vertice[i] = transformar(perfil[i]);
	}
	
	
	for (int i = 1; i < nQ; i++){//numero poligonos en la hipotrocoide 
		//sumamos el angulo y transformamos para dibujar en la curva
		t += tGrados;
		//Calcular los nuevos vertices
		cMatriz(t);
		for (int j = 0; j < nP; j++){//numero de caras cuadrangulares de cada poligono
			vertice[i * nP + j] = transformar(perfil[j]);

				VerticeNormal** verNor = new VerticeNormal*[4];
				verNor[0] = new VerticeNormal(i * nP + j, (i - 1) * nP + j);
				verNor[1] = new VerticeNormal((i * nP + j - nP), (i - 1) * nP + j);
				verNor[2] = new VerticeNormal((i * nP + j - nP + 1) % nP + (nP * (i - 1)), (i - 1) * nP + j);
				verNor[3] = new VerticeNormal((i * nP + j + 1) % nP + (nP * i), (i - 1) * nP + j);
				cara[(i - 1) * nP + j] = new Cara(4, verNor);

		}

	}
		
	for (int c = 0; c < numeroCaras; c++) {
		normal[c] = norWell(cara[c]);
	}
	
}


Hipotrocoide::~Hipotrocoide()
{
}

PuntoVector3D* Hipotrocoide::C(GLfloat t){
	
	return new PuntoVector3D((a - b)*cos(t) + c*cos(t*((a - b) / b)), 0, (a - b)*sin(t) - c*sin(t *((a - b) / b)), 0);
}
PuntoVector3D* Hipotrocoide::C’(GLfloat t){
	
	return new PuntoVector3D(-1 * (a - b)*sin(t) + (-c*sin(t*((a - b) / b)) * ((a - b) / b)), 
		0, (a - b)*cos(t) - (c*cos(t*((a - b) / b)) * ((a - b) / b)), 0);

}
PuntoVector3D* Hipotrocoide::C’’(GLfloat t){

	return new PuntoVector3D(-1 * (a - b)*cos(t) + (-c*cos(t*((a - b) / b))*((a - b) / b) * ((a - b) / b)), 0,
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

PuntoVector3D* Hipotrocoide::transformar(PuntoVector3D* p){

	 return new PuntoVector3D(m[0] * p->getX() + m[4] * p->getY() + m[8] * p->getZ() + m[12],
		m[1] * p->getX() + m[5] * p->getY() + m[9] * p->getZ() + m[13],
		m[2] * p->getX() + m[6] * p->getY() + m[10] * p->getZ() + m[14],
		1);

}

void Hipotrocoide::cPerfil(){
	GLfloat inc = (2 * 3.1415926 / nP);
	for (int i = 0; i < nP; i++){
		perfil[i] = new PuntoVector3D(r*cos(i*inc), r*sin(i*inc), 0, 1);
	}
}

void Hipotrocoide::cMatriz(GLfloat t){
	PuntoVector3D* n = N(t);
	PuntoVector3D* b = B(t);
	PuntoVector3D* tp = T(t);
	PuntoVector3D* c = C(t);

	/// (N,B,T,C)
	m[0] = n->getX();
	m[1] = n->getY();
	m[2] = n->getZ();	
	m[3] = 0;
	
	m[4] = b->getX();
	m[5] = b->getY();
	m[6] = b->getZ();
	m[7] = 0;

	m[8] = tp->getX();
	m[9] = tp->getY();
	m[10] = tp->getZ();
	m[11] = 0;

	m[12] = c->getX();
	m[13] = c->getY();
	m[14] = c->getZ();
	m[15] = 1;

	delete n;
	delete b;
	delete tp;
	delete c;

}

PuntoVector3D * Hipotrocoide::norWell(Cara * c)
{
	//{x,y,z}
	GLfloat nx = 0;
	GLfloat ny = 0;
	GLfloat nz = 0;

	PuntoVector3D* vertActual;
	PuntoVector3D* vertSiguiente;
	for(int i = 0; i < c->getNumeroVertices(); i++){

	vertActual = vertice[c->getIndiceVerticeK(i)];
	vertSiguiente = vertice[c->getIndiceVerticeK((i + 1) % c->getNumeroVertices())];

	nx += (vertActual->getY() - vertSiguiente->getY()) * (vertActual->getZ() + vertSiguiente->getZ());
	ny += (vertActual->getZ() - vertSiguiente->getZ()) * (vertActual->getX() + vertSiguiente->getX());
	nz += (vertActual->getX() - vertSiguiente->getX()) * (vertActual->getY() + vertSiguiente->getY());

	}
	PuntoVector3D* nNormal = new PuntoVector3D(nx, ny, nz, 0);
	nNormal->normalizar();
	return nNormal;
}
