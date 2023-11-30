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

    auto actual {p.primerNodo};
    for(; actual->next; actual = actual->next){
        perimetro += GetDistancia(actual->value, actual->next->value);
    }
    perimetro +=  GetDistancia(actual->value, p.primerNodo->value);
    return perimetro;
}

/*-----------------------------------------------------------------------------------------------*/

unsigned GetCantidadDeLados(const Poligono& p){
    return p.n;
}

/*-----------------------------------------------------------------------------------------------*/

Poligono& Push(Poligono& p, const Punto nuevoPunto){

    if(p.primerNodo) {
        Nodo* actual{p.primerNodo};
        for (; actual->next; actual = actual->next);
        actual->next = new Nodo;
        actual->next->value = nuevoPunto;
    }
    else {
        p.primerNodo = new Nodo;
        p.primerNodo->value = nuevoPunto;
    }
    p.n++;

    return p;
}

/*-----------------------------------------------------------------------------------------------*/

Poligono& Add(Poligono& p, const Punto& punto, unsigned pos){
    if (pos == 0) {
        p.primerNodo = new Nodo{punto, p.primerNodo};
    } else {
        Nodo* actual {p.primerNodo};

        for(unsigned i{1}; i < pos && actual->next; i++){
            actual = actual->next;
        }

        actual->next = new Nodo{punto, actual->next};
    }

    p.n++;
    return p;
}


/*-----------------------------------------------------------------------------------------------*/

Poligono& Pop(Poligono& p){

    if (p.primerNodo->next) {
        Nodo* actual = p.primerNodo;
        for (; actual->next->next; actual = actual->next);
        delete actual->next;
        actual->next = nullptr;
    } else{
        delete p.primerNodo;
        p.primerNodo = nullptr;
    }
    p.n--;
    return p;
}

/*-----------------------------------------------------------------------------------------------*/

Poligono& RemovePorPunto(Poligono& p, const Punto puntoToRemove){
    if (AreEqual(p.primerNodo->value, puntoToRemove)) {
        auto nodeToRemove{p.primerNodo};
        p.primerNodo = nodeToRemove->next;
        p.n--;
        delete nodeToRemove;
        return p;
    }

    for(auto actual {p.primerNodo}; actual; actual = actual ->next){
        if(AreEqual(actual->next->value, puntoToRemove)) {
            auto nodeToRemove = actual->next;
            actual->next = nodeToRemove->next;
            delete nodeToRemove;
            p.n--;
            break;
        }
    }
    return p;
}

/*-----------------------------------------------------------------------------------------------*/

Poligono& RemovePorPosicion(Poligono& p, unsigned pos){
    if (pos == 1){
        auto nodeToRemove {p.primerNodo};
        p.primerNodo = nodeToRemove->next;
        p.n--;
        delete nodeToRemove;
        return p;
    }
    auto actual{p.primerNodo};
    for(unsigned i = 1; i < pos - 1 && actual->next; i++) {
        actual = actual->next;
    }
    if (actual->next) {
        Nodo* nodeToRemove = actual->next;
        actual->next = nodeToRemove->next;
        p.n--;
        delete nodeToRemove;
        return p;
    }
}

/*-----------------------------------------------------------------------------------------------*/

Punto Top(const Poligono& p) {
    auto actual {p.primerNodo};

    for(;actual->next;actual = actual->next);

    return actual->value;
}

/*-----------------------------------------------------------------------------------------------*/

Punto First(const Poligono& p){
    return p.primerNodo->value;
}

/*-----------------------------------------------------------------------------------------------*/

Punto GetPuntoPorPosicion(const Poligono& p, unsigned pos){
    auto actual{p.primerNodo};

    for(unsigned i{1}; i < pos; i++){
        actual = actual->next;
    }
    return actual->value;
}

/*-----------------------------------------------------------------------------------------------*/

int GetPosicionPorPunto(const Poligono& p, const Punto& punto){
    unsigned i{1};

    for(auto actual {p.primerNodo}; actual; actual = actual ->next, i++){
        if(AreEqual(actual->value, punto)) {
            return i;
        }
    }
    return 0;
}

/*-----------------------------------------------------------------------------------------------*/