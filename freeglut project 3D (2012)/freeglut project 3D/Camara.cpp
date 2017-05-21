#include "Camara.h"


Camara::Camara(PuntoVector3D* eyep, PuntoVector3D* lookp, PuntoVector3D* upp)
{
	eye = eyep;//donde esta
	look = lookp;//donde mira
	up = upp;//donde orienta

	//volumen de vista
	left = 5;
	right = 5;
	top = 5;
	bottom = 5;
	Near = 1;
	Far = 10;
	fovy = 5;
	aspect = 5;

	//matriz de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye->getX(), eye->getY(), eye->getZ(), look->getX(), look->getY(), look->getZ(), up->getX(), up->getY(), up->getZ());

	//matriz de proyeccion
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(left, right, bottom, top, Near, Far);
}


Camara::~Camara()
{
}
