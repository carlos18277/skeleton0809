//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Habitaciones.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


Habitacion::Habitacion(int h) {
    nHabitacion = h;
    PV3D* vector;
    if(nHabitacion == 1){
        numObjetos = 1;
        this->matriz = new TAfin();
        objetos = new Objeto3D*[numObjetos];

        objetos[0] = new Tablero(2.5, 2.5, 0.01, 10, 2, 10); //suelo
        objetos[0]->setColor(new Color(0.5, 0, 0.5));
        objetos[0]->setMatriz(new TAfin());
        /*
        //crear paredes
        objetos[2] = new Tablero(0.2, 2.5, 2.5, 10, 2, 10);
        objetos[2]->setColor(new Color(0.5, 0, 0.5));
        objetos[2]->setMatriz(new TAfin());

        objetos[3] = new Tablero(0.7, 0.2, 2.5, 10, 2, 10);
        objetos[3]->setColor(new Color(0.5, 0, 0.5));
        objetos[3]->setMatriz(new TAfin());

        objetos[4] = new Tablero(0.7, 0.2, 2.5, 10, 2, 10);
        objetos[4]->setColor(new Color(0.5, 0, 0.5));
        objetos[4]->setMatriz(new TAfin());
        vector = new PV3D(1.8, 0.0,0.0,1);
        objetos[4]->getM()->trasladar(vector);
        delete vector;

        objetos[5] = new Tablero(2.5, 0.2, 0.7, 10, 2, 10);
        objetos[5]->setColor(new Color(0.5, 0, 0.5));
        objetos[5]->setMatriz(new TAfin());

        objetos[6] = new Tablero(2.5, 0.2, 0.7, 10, 2, 10);
        objetos[6]->setColor(new Color(0.5, 0, 0.5));
        objetos[6]->setMatriz(new TAfin());
        vector = new PV3D(0, 1.8,0.0,1);
        objetos[6]->getM()->trasladar(vector);
        delete vector;


        objetos[7] = new Tablero(0.1, 0.8, 0.8, 10, 2, 10);  //cuadro
        objetos[7]->setColor(new Color(0.5, 0.5, 0.5));
        objetos[7]->setMatriz(new TAfin());
        vector = new PV3D(0.2, 1.5,1.0,1);
        objetos[7]->getM()->trasladar(vector);
        delete vector;
          */
    }
    else{
        numObjetos =  1;
        this->matriz = new TAfin();
        vector = new PV3D(2.5, 0.0, 0.0, 1);
        matriz->trasladar(vector);
        delete vector;

        objetos = new Objeto3D*[numObjetos];
        //crear paredes
        objetos[0] = new Tablero(2.5, 2.5, 0.01, 10, 2, 10); //suelo
        objetos[0]->setColor(new Color(0.2, 0, 0.3));
        objetos[0]->setMatriz(new TAfin());
        /*
        objetos[1] = new Tablero(0.7, 0.2, 2.5, 10, 2, 10);
        objetos[1]->setColor(new Color(0.2, 0, 0.3));
        objetos[1]->setMatriz(new TAfin());

        objetos[2] = new Tablero(0.7, 0.2, 2.5, 10, 2, 10);
        objetos[2]->setColor(new Color(0.2, 0, 0.3));
        objetos[2]->setMatriz(new TAfin());
        vector = new PV3D(1.8, 0.0,0.0,1);
        objetos[2]->getM()->trasladar(vector);
        delete vector;

        objetos[3] = new Tablero(2.5, 0.2, 0.7, 10, 2, 10);
        objetos[3]->setColor(new Color(0.2, 0, 0.3));
        objetos[3]->setMatriz(new TAfin());

        objetos[4] = new Tablero(2.5, 0.2, 0.7, 10, 2, 10);
        objetos[4]->setColor(new Color(0.2, 0, 0.3));
        objetos[4]->setMatriz(new TAfin());
        vector = new PV3D(0, 1.8,0.0,1);
        objetos[4]->getM()->trasladar(vector);
        delete vector;

        objetos[5] = new Tablero(0.2, 0.8, 2.5, 10, 2, 10);
        objetos[5]->setColor(new Color(0.2, 0, 0.3));
        objetos[5]->setMatriz(new TAfin());

        objetos[6] = new Tablero(0.2, 0.8, 2.5, 10, 2, 10);
        objetos[6]->setColor(new Color(0.2, 0, 0.3));
        objetos[6]->setMatriz(new TAfin());
        vector = new PV3D(0.0, 0.0,1.7,1);
        objetos[6]->getM()->trasladar(vector);
        delete vector;

        objetos[7] = new Tablero(0.2, 2.5, 0.3, 10, 2, 10);
        objetos[7]->setColor(new Color(0.2, 0, 0.3));
        objetos[7]->setMatriz(new TAfin());
        vector = new PV3D(0.0, 2.2,0.0,1);
        objetos[7]->getM()->trasladar(vector);
        delete vector;
        */
    }
}

//---------------------------------------------------------------------------

void Habitacion::dibujar() {
    glMatrixMode(GL_MODELVIEW);

    for(int i= 0; i < numObjetos;i++) {
        glPushMatrix();
		    glMultMatrixd(objetos[i]->getM()->getMatriz());
		    objetos[i]->dibujar();
	    glPopMatrix();
    }
}

//---------------------------------------------------------------------------
Habitacion::~Habitacion() {

    for(int i = 0; i< numObjetos;i++) {
        delete objetos[i]->getColor();
        delete objetos[i]->getM();
        delete objetos[i];
    }
    delete []objetos;
    delete matriz;
}

//---------------------------------------------------------------------------


 