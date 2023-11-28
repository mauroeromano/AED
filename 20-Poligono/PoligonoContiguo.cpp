#include<array>
#include<cassert>
#include"Punto.h"
#include"FuncionesAuxiliares.h"
using std::array;

/*-----------------------------------------------------------------------------------------------*/

struct Poligono{
    array<Punto,100> puntos;
    unsigned n{};
};

/*-----------------------------------------------------------------------------------------------*/

// Funciones para Poligonos

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

int main(){

    // Poligono 1 de prueba

    Poligono p{{{{0, 0}, {3, 0}, {0, 1.5}}},3};

    assert(AreNear(GetPerimetro(p),7.854));
    assert(GetCantidadDeLados(p) == 3);
    assert(Top(p).x == 0 and Top(p).y == 1.5);
    assert(First(p).x == 0 and First(p).y == 0);

    Pop(p);
    assert(AreNear(GetPerimetro(p),6));
    assert(GetCantidadDeLados(p) == 2);
    assert(Top(p).x == 3 and Top(p).y == 0);

    Push(p, {0, 1.5});
    assert(AreNear(GetPerimetro(p),7.854));
    assert(GetCantidadDeLados(p) == 3);
    assert(Top(p).x == 0 and Top(p).y == 1.5);

    assert(GetPuntoPorPosicion(p,2).x == 3 and GetPuntoPorPosicion(p,2).y == 0);
    RemovePorPunto(p,{3,0});
    assert(GetPuntoPorPosicion(p,2).x == 0 and GetPuntoPorPosicion(p,2).y == 1.5);

    assert(GetCantidadDeLados(p) == 2);
    Add(p,{1,5},4);
    Add(p,{1,1},3);
    assert(GetCantidadDeLados(p) == 4);

    assert(GetPuntoPorPosicion(p,1).x == 0 and GetPuntoPorPosicion(p,1).y == 0);
    assert(GetPuntoPorPosicion(p,2).x == 0 and GetPuntoPorPosicion(p,2).y == 1.5);
    assert(GetPuntoPorPosicion(p,3).x == 1 and GetPuntoPorPosicion(p,3).y == 1);

    assert(GetPosicionPorPunto(p,{0,0  }) == 1);
    assert(GetPosicionPorPunto(p,{0,1.5}) == 2);
    assert(GetPosicionPorPunto(p,{1,1  }) == 3);
    assert(GetPosicionPorPunto(p,{1,5  }) == 4);


    // Poligono 2 de prueba

    Poligono p2{{{{0, 0}, {4, 0}, {4, 2},{0,2}}},4};

    assert(AreNear(GetPerimetro(p2),12));
    assert(GetCantidadDeLados(p2) == 4);
    assert(Top(p2).x == 0 and Top(p2).y == 2);
    assert(First(p2).x == 0 and First(p2).y == 0);

    Pop(p2);
    assert(AreNear(GetPerimetro(p2),10.47));
    assert(GetCantidadDeLados(p2) == 3);
    assert(Top(p2).x == 4 and Top(p2).y == 2);

    Push(p2,{0,2});
    assert(AreNear(GetPerimetro(p2),12));
    assert(GetCantidadDeLados(p2) == 4);
    assert(Top(p2).x == 0 and Top(p2).y == 2);

    assert(GetPuntoPorPosicion(p2,2).x == 4 and GetPuntoPorPosicion(p2,2).y == 0);
    RemovePorPosicion(p2,2);
    assert(GetPuntoPorPosicion(p2,2).x == 4 and GetPuntoPorPosicion(p2,2).y == 2);

}

// Funciones p/Poligono

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
