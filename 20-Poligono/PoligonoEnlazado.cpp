#include<array>
#include<cassert>
#include"Punto.h"
#include"FuncionesAuxiliares.h"
using std::array;

/*-----------------------------------------------------------------------------------------------*/

// Tipos de Datos

struct Punto{
    double x,y;
};

struct Nodo{
    Punto value;
    Nodo* next{nullptr};
};

struct Poligono{
    Nodo* primerNodo{nullptr};
    unsigned n{};
};

/*-----------------------------------------------------------------------------------------------*/

// Funciones Adicionales

// Distancia entre dos puntos
double GetDistancia(const Punto&, const Punto&);

// Devuelve el valor absoluto (modulo)
double Abs(double);

// Dado dos valores, redondea con una tolerancia de 0.01 (defecto)
bool AreNear(const double&, const double&, const double = 0.01);

/*-----------------------------------------------------------------------------------------------*/

// Funciones para Poligonos

// Perimetro
double GetPerimetro(const Poligono&);

// Cantidad de Lados
unsigned GetCantidadDeLados(const Poligono&);

// Push
Poligono& Push(Poligono&, const Punto);

// Pop
Poligono& Pop(Poligono&);

int main() {

    // Poligono 1 de prueba

    Poligono p;

    p.primerNodo = new Nodo;
    p.primerNodo->value = {0,0};
    p.primerNodo->next = new Nodo;
    p.primerNodo->next->value = {3, 0};
    p.primerNodo->next->next = new Nodo;
    p.primerNodo->next->next->value = {0, 1.5};
    p.n = 3;

    assert(AreNear(GetPerimetro(p), 7.854));
    assert(GetCantidadDeLados(p) == 3);

    Push(p,{})

    // Poligono 2 de prueba

    Poligono p2;

    p2.primerNodo = new Nodo{0, 0};
    p2.primerNodo->next = new Nodo{4, 0};
    p2.primerNodo->next->next = new Nodo{4, 2};
    p2.primerNodo->next->next->next = new Nodo{0, 2};
    p2.n = 4;

    assert(AreNear(GetPerimetro(p2), 12));
    assert(GetCantidadDeLados(p2) == 4);
}

// Funciones Adicionales

    double Abs(double x){
        return (x>0) ? x : -x;
    }

    bool AreNear(const double& a, const double& b, const double tolerance){
        return Abs(a-b) < tolerance;
    }

    double GetDistancia(const Punto& p1, const Punto& p2){
        return (std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2)));
    }

/*-----------------------------------------------------------------------------------------------*/

// Funciones p/Poligono

// Perimetro

double GetPerimetro(const Poligono& p){
    double perimetro {};

    if(p.primerNodo != nullptr){
        auto actual {p.primerNodo};

        for(; actual->next; actual = actual->next)
            perimetro += GetDistancia(actual->value,actual->next->value);

        perimetro += GetDistancia(actual->value,p.primerNodo->value);

        return perimetro;
    }
}

// Cantidad de Lados

unsigned GetCantidadDeLados(const Poligono& p){
    return p.n;
}

// Agregar punto al final del poligono

Poligono& Push(Poligono& p, const Punto nuevoPunto){

    Nodo* nuevoNodo = new Nodo{nuevoPunto};

    if(p.primerNodo == nullptr){
        p.primerNodo = nuevoNodo;
    }
    else{
        Nodo* ultimoNodo = p.primerNodo;
        for(;ultimoNodo->next != nullptr;ultimoNodo = ultimoNodo -> next){
        }
        ultimoNodo->next = nuevoNodo;
    }
    ++p.n;
    return p;
}

Poligono& Pop(Poligono& p){

    if(p.primerNodo == nullptr){
        return p;
    }
    else{

    }
}
