#ifndef PUNTO_INCLUIDO
#define PUNTO_INCLUIDO

#include<math.h>
#include"FuncionesAuxiliares.h"

// Tipo de Dato Punto
// Conjunto de Valores
struct Punto{
    double x,y;
};

// Conjunto de Operaciones (declaracion)
double GetDistancia(const Punto, const Punto);
bool AreEqual(const Punto, const Punto);

// Conjunto de Operaciones (implementacion)
double GetDistancia(const Punto a,const Punto b){
    return hypot((b.x - a.x), (b.y - a.y));
}
bool AreEqual(const Punto a, const Punto b) {
    return AreNear(a.x, b.x) and AreNear(a.y,b.y);
}

#endif