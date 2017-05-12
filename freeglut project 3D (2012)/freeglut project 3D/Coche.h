#ifndef COCHE_H
#define COCHE_H
#include "Malla.h"
#include "GL\glut.h"


class Chasis:
	public Malla
{
	int radio_;
public:
	Chasis(GLfloat r);
	virtual ~Chasis(void) {};

};

class Rueda :
	public Malla
{
public: 
	Rueda(void);
	virtual ~Rueda(void) {};
};



class Coche
{
public:
	Coche(GLfloat r);
	~Coche();
};

#endif