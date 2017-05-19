#include "Coche.h"


Coche::Coche(GLdouble s)
{
	dibuja(s);
}


Coche::~Coche()
{
}


void Coche::dibuja(GLdouble s){
	GLUquadric* o;
	o = gluNewQuadric();


	glPushMatrix();
	glScaled(s, s, s);
	glTranslated(-3, 0, -3);

	glColor3d(0, 0.7, 0.3);

//ruedas
	glPushMatrix();
	gluCylinder(o, 1, 1, 1, 20, 1);
	gluDisk(o, 0, 1, 20, 1);
	glTranslated(0, 0, 1);
	gluDisk(o, 0, 1, 20, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(6, 0, 1);
	gluCylinder(o, 1, 1, 1, 20, 1);
	gluDisk(o, 0, 1, 20, 1);
	glTranslated(0, 0, 1);
	gluDisk(o, 0, 1, 20, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, 5);
	gluCylinder(o, 1, 1, 1, 20, 1);
	gluDisk(o, 0, 1, 20, 1);
	glTranslated(0, 0, 1);
	gluDisk(o, 0, 1, 20, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(6, 0, 4);
	gluCylinder(o, 1, 1, 1, 20, 1);
	gluDisk(o, 0, 1, 20, 1);
	glTranslated(0, 0, 1);
	gluDisk(o, 0, 1, 20, 1);
	glPopMatrix();

	//chasis
	glPushMatrix();
	glColor3d(0.8, 0.4, 0.2);
	glTranslated(-1, 2.5, 3);
	glRotated(-10, 0, 0, 1);
	glRotated(45, 1, 0, 0);
	glRotated(90, 0, 1, 0);
	gluCylinder(o, 3.5, 1.5, 10, 4, 1);
	gluDisk(o, 0, 3.5, 4, 1);
	glTranslated(0, 0, 10);
	gluDisk(o, 0, 1.5, 4, 1);
	glPopMatrix();


	glPopMatrix();

	glColor3d(0, 0, 1);

}