//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "VerticeNormal.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

VerticeNormal::VerticeNormal(){}

VerticeNormal::~VerticeNormal(){}

VerticeNormal::VerticeNormal(int v, int n) {
    vertice = v;
    normal = n;
}

int VerticeNormal::getVertice(){
    return vertice;
}

int VerticeNormal::getNormal(){
    return normal;
}




