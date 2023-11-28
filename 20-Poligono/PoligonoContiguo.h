#include<array>
#include"Punto.h"
#include"FuncionesAuxiliares.h"
using std::array;

// Tipo de Dato Poligono Contiguo
// Conjunto de Valores

struct Poligono{
    array<Punto,100> puntos;
    unsigned n{};
};

// Conjunto de Operaciones (declaracion)

// Perimetro
double GetPerimetro(const Poligono&);

// Cantidad de Lados
unsigned GetCantidadDeLados(const Poligono&);

// Agregar punto al final de poliogono
Poligono& Push(Poligono&, const Punto);

// Agregar punto por posicion
Poligono& Add(Poligono&, const Punto&, unsigned);

// Eliminar ultimo punto del poligono
Poligono& Pop (Poligono&);

// Remover punto dado
Poligono& RemovePorPunto(Poligono&, const Punto);

// Remueve un punto dada una posicion
Poligono& RemovePorPosicion(Poligono&, unsigned);

// Muestra el ultimo punto
Punto Top(const Poligono&);

// Muestra el primer punto
Punto First(const Poligono&);

// Muestra el punto que hay en esa posicion
Punto GetPuntoPorPosicion(const Poligono&, unsigned);

// Muestra la posicion donde se encuentra ese punto
int GetPosicionPorPunto(const Poligono&, const Punto&);


// Conjunto de Operaciones (implementacion)

double GetPerimetro(const Poligono& p){
    double perimetro {};

    for(unsigned i{}; i < p.n - 1; i++)
        perimetro += GetDistancia(p.puntos.at(i), p.puntos.at(i + 1));

    perimetro += GetDistancia(p.puntos.at((p.n) - 1), p.puntos.at(0));

    return perimetro;
}

/*-----------------------------------------------------------------------------------------------*/

unsigned GetCantidadDeLados(const Poligono& p){
    return p.n;
}

/*-----------------------------------------------------------------------------------------------*/

Poligono& Push(Poligono& p, const Punto nuevoPunto){
    if(p.n < p.puntos.size()){
        p.puntos.at(p.n) = nuevoPunto;
        p.n++;
    }
    return p;
}

/*-----------------------------------------------------------------------------------------------*/

Poligono& Add(Poligono& p, const Punto& punto, unsigned pos) {
    if (p.n < p.puntos.size()) {
        for (unsigned i=p.n; i > pos; i--) {
            p.puntos.at(i) = p.puntos.at(i-1);
        }
        p.puntos.at(pos-1) = punto;
        p.n++;
        return p;
    }
    return p;
}

/*-----------------------------------------------------------------------------------------------*/

Poligono& Pop(Poligono& p){
    if(p.n > 0){
        p.n--;
    }
    return p;
}

/*-----------------------------------------------------------------------------------------------*/

Poligono& RemovePorPunto(Poligono& p, const Punto puntoToRemove){
    for(unsigned i{}; i<p.n; i++){
        if(AreEqual(p.puntos.at(i),puntoToRemove)){
            for(unsigned j=i; j<p.n; j++){
                p.puntos.at(j) = p.puntos.at(j+1);
            }
            p.n--;
            return p;
        }
    }
    return p;
}

/*-----------------------------------------------------------------------------------------------*/

Poligono& RemovePorPosicion(Poligono& p, unsigned pos) {
    for (unsigned i{}; i < p.n; i++) {
        if (i == pos-1) {
            for (unsigned j = i; j < p.n; j++) {
                p.puntos.at(j) = p.puntos.at(j + 1);
            }
            p.n--;
            return p;
        }
    }
    return p;
}

/*-----------------------------------------------------------------------------------------------*/

Punto Top(const Poligono& p){
    return p.puntos.at(p.n-1);
}

/*-----------------------------------------------------------------------------------------------*/

Punto First(const Poligono& p){
    return p.puntos.at(0);
}

/*-----------------------------------------------------------------------------------------------*/

Punto GetPuntoPorPosicion (const Poligono& p, unsigned pos){
    return p.puntos.at(pos-1);
}

/*-----------------------------------------------------------------------------------------------*/

int GetPosicionPorPunto(const Poligono& p, const Punto& punto){
    for(unsigned i{}; i<p.n; i++){
        if(AreEqual(p.puntos.at(i),punto)){
            return i+1;
        }
    }
    return -1;
}

/*-----------------------------------------------------------------------------------------------*/
