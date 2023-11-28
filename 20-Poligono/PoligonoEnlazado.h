#include"Punto.h"
#include"FuncionesAuxiliares.h"

// Tipo de Dato Poligono Contiguo
// Conjunto de Valores

struct Nodo{
    Punto value;
    Nodo* next{nullptr};
};

struct Poligono{
    Nodo* primerNodo{nullptr};
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

    if(p.primerNodo != nullptr){
        auto actual {p.primerNodo};

        for(; actual->next; actual = actual->next)
            perimetro += GetDistancia(actual->value,actual->next->value);

        perimetro += GetDistancia(actual->value,p.primerNodo->value);

        return perimetro;
    }
}

/*-----------------------------------------------------------------------------------------------*/

unsigned GetCantidadDeLados(const Poligono& p){
    return p.n;
}

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

/*-----------------------------------------------------------------------------------------------*/

Poligono& Pop(Poligono& p){

    if(p.primerNodo == nullptr){
        return p;
    }
    else{

    }
}

/*-----------------------------------------------------------------------------------------------*/

