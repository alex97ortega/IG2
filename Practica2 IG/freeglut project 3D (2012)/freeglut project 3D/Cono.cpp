#include "Cono.h"

/*


PuntoVector3D** normal;
Cara** cara;        
*/
Cono::Cono(int p, int r, int h)
{
	/*
	numeroCaras = 2*p;
	numeroNormales = 2 * p;
	numeroVertices = p + 2;
	vertice[0] = new PuntoVector3D(0, 0, 0, 1);
	vertice[1] = new PuntoVector3D(0, h, 0, 1);

	for (int i = 2; i < p; i++)
		vertice[i] = new PuntoVector3D(r*cos(i * 2 * 3.14 / p), 0, r*sin(i * 2 * 3.14 / p), 1);

	for (int i = 0; i < p-1; i++){

		VerticeNormal** aVN = new VerticeNormal*[3];
		aVN[0] = new VerticeNormal(0, 0);
		aVN[1] = new VerticeNormal(i + 1, 0);
		aVN[2] = new VerticeNormal(i , 0);
		cara[i] = new Cara(3, aVN);
		delete aVN;

		VerticeNormal** aVN = new VerticeNormal*[3];
		aVN[0] = new VerticeNormal(1, 0);
		aVN[1] = new VerticeNormal(i + 1, 0);
		aVN[2] = new VerticeNormal(i , 0);
		cara[p+i] = new Cara(3, aVN);
		delete aVN;

	}
		VerticeNormal** aVN = new VerticeNormal*[3];
		aVN[0] = new VerticeNormal(0, 0);
		aVN[1] = new VerticeNormal(numeroVertices-1, 0);
		aVN[2] = new VerticeNormal(2, 0);
		cara[numeroCaras-2] = new Cara(3, aVN);
		delete aVN;

		VerticeNormal** aVN = new VerticeNormal*[3];
		aVN[0] = new VerticeNormal(1, 0);
		aVN[1] = new VerticeNormal(numeroVertices-1, 0);
		aVN[2] = new VerticeNormal(2, 0);
		cara[numeroCaras-1] = new Cara(3, aVN);
		delete aVN;
		*/

		


}


Cono::~Cono()
{
}
