#include "Camara.h"


Camara::Camara(PuntoVector3D* eyep, PuntoVector3D* lookp, PuntoVector3D* upp)
{
	eye = eyep;//donde esta
	look = lookp;//donde mira
	up = upp;//donde orienta

	//volumen de vista
	left = 10;
	right = 10;
	top = 10;
	bottom = 10;
	Near = 1;
	Far = 1000;
	fovy = 10;
	aspect = 10;


	//matriz de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye->getX(), eye->getY(), eye->getZ(), look->getX(), look->getY(), look->getZ(), up->getX(), up->getY(), up->getZ());

	//matriz de proyeccion
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(left, right, bottom, top, Near, Far);

	darValores();
	cMatriz();
}


Camara::~Camara()
{
}

void Camara::darValores(){

	///////////////n
	PuntoVector3D* i = new PuntoVector3D(eye->getX() - look->getX(),
		eye->getY() - look->getY(), eye->getZ() - look->getZ(), 0);
	i->normalizar();
	n = i;

	///////////////u
	PuntoVector3D* j = up->productoVectorial(n);
	j->normalizar();


	u = j;

	////////////////v
	v = n->productoVectorial(u);

	
}

void Camara::cMatriz(){

	//u,v,n,e

	V[0] = u->getX();
	V[1] = u->getY();
	V[2] = u->getZ();
	V[3] = 0;

	V[4] = v->getX();
	V[5] = v->getY();
	V[6] = v->getZ();
	V[7] = 0;

	V[8] = n->getX();
	V[9] = n->getY();
	V[10] = n->getZ();
	V[11] = 0;

	V[12] = eye->getX();
	V[13] = eye->getY();
	V[14] = eye->getZ();
	V[15] = 1;

}


void Camara::inversa(){

	//u,v,n,e
	V´[0] = u->getX();
	V´[1] = v->getX();
	V´[2] = n->getX();
	V´[3] = 0;

	V´[4] = u->getY();
	V´[5] = v->getY();
	V´[6] = n->getY();
	V´[7] = 0;

	V´[8] = u->getZ();
	V´[9] = v->getZ();
	V´[10] = n->getZ();
	V´[11] = 0;

	V´[12] = -eye->productoEscalar(u);
	V´[13] = -eye->productoEscalar(v);
	V´[14] = -eye->productoEscalar(n);
	V´[15] = 1;


}
void Camara::movRoll(GLfloat roll){

	glMatrixMode(GL_MODELVIEW); 
	
	///u global
	PuntoVector3D* i = new PuntoVector3D(u->getX()* cos(roll) + v->getX() * sin(roll),
		u->getY()* cos(roll) + v->getY() * sin(roll), u->getZ()* cos(roll) + v->getZ() * sin(roll), 0);
	

	///v global preguntar?¿
	PuntoVector3D* j = new PuntoVector3D(-u->getX()* sin(roll) + v->getX() * cos(roll),
		-u->getY()* sin(roll) + v->getY() * cos(roll), -u->getZ()* sin(roll) + v->getZ() * cos(roll), 0);


	u = i;
	v = j;


	cMatriz();
	inversa();
	glLoadMatrixf(V´);

	


}