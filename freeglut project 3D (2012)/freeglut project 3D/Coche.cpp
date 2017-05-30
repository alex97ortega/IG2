#include "Coche.h"


Coche::Coche()
{
	o = gluNewQuadric();
	
}


Coche::~Coche()
{
	gluDeleteQuadric(o);
}


void Coche::dibuja(GLdouble s, GLdouble rot){
	
	//glPopMatrix();//activar y desactivar para pintar el coche mejor
	
	glPushMatrix();
	glScaled(s, s, s);
	glColor3d(0, 0.7, 0.3);



//ruedas
	glPushMatrix();
	glRotated(rot, 0, 0, 1);
	gluCylinder(o, 1, 1, 1, 20, 1);
	gluDisk(o, 0.5, 1, 4, 1);
	glTranslated(0, 0, 1);
	gluDisk(o, 0.5, 1, 4, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(6, 0, 1);
	glRotated(rot, 0, 0, 1);
	gluCylinder(o, 1, 1, 1, 20, 1);
	gluDisk(o, 0.5, 1, 4, 1);
	glTranslated(0, 0, 1);
	gluDisk(o, 0.5, 1, 4, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, 5);
	glRotated(rot, 0, 0, 1);
	gluCylinder(o, 1, 1, 1, 20, 1);
	gluDisk(o, 0.5, 1, 4, 1);
	glTranslated(0, 0, 1);
	gluDisk(o, 0.5, 1, 4, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(6, 0, 4);
	glRotated(rot, 0, 0, 1);
	gluCylinder(o, 1, 1, 1, 20, 1);
	gluDisk(o, 0.5, 1, 4, 1);
	glTranslated(0, 0, 1);
	gluDisk(o, 0.5, 1, 4, 1);
	glPopMatrix();



	//chasis
	glPushMatrix();
	glColor3d(0.8, 0.1, 0.8);
	glTranslated(-1, 2.5, 3);
	glRotated(-10, 0, 0, 1);
	glRotated(45, 1, 0, 0);
	glRotated(90, 0, 1, 0);
	gluCylinder(o, 3.5, 1.5, 10, 4, 1);
	gluDisk(o, 0, 3.5, 4, 1);
	glTranslated(0, 0, 10);
	gluDisk(o, 0, 1.5, 4, 1);
	glPopMatrix();

	//faros
	glPushMatrix();
	glColor3d(0, 1, 0);
	glTranslated(8.5, 1.2, 2.4);
///////
	
	GLfloat amb[] = { 1, 1, 0, 1.0 };
	GLfloat dif[] = { 1, 1, 1, 1 };
	GLfloat spc[] = { 1, 1, 1, 1 };


	glLightfv(GL_LIGHT1, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, dif);
	glLightfv(GL_LIGHT1, GL_SPECULAR, spc);

	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 50);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 4);

	GLfloat p[] = { 0.2, 0, 0, 1 };
	GLfloat dir[] = { 1.0, 0.0, 0.0 };	
	glLightfv(GL_LIGHT1, GL_POSITION, p);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dir);
	
	glRotated(90, 0, 1, 0);
	gluCylinder(o, 0.5, 0.5, 1, 20, 1);

	
	glTranslated(-1, 0, 0);
	glRotated(-90, 0, 1, 0);

	

	glLightfv(GL_LIGHT2, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, dif);
	glLightfv(GL_LIGHT2, GL_SPECULAR, spc);

	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 50);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 4);

	glLightfv(GL_LIGHT2, GL_POSITION, p);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, dir);


	glRotated(90, 0, 1, 0);
	gluCylinder(o, 0.5, 0.5, 1, 20, 1);
	glPopMatrix();


	glPopMatrix();


	glColor3d(1, 1, 1);

}