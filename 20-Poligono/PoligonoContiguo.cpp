#include<array>
#include<math.h>
#include<cassert>
using std::array;

/*-----------------------------------------------------------------------------------------------*/

// Tipos de Datos

struct Punto{
    double x,y;
};

struct Poligono{
    array<Punto,100> puntos;
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

// Agregar punto al final de poliogono
void Push(Poligono&, const Punto);

// Agregar punto por posicion
void Add(Poligono&, const Punto&, unsigned);

// Eliminar ultimo punto del poligono
void Pop (Poligono&);

// Remover punto dado
void RemovePorPunto(Poligono&, const Punto);

// Remueve un punto dada una posicion
void RemovePorPosicion(Poligono&, unsigned);

// Muestra el ultimo punto
Punto Top(const Poligono&);

// Muestra el primer punto
Punto First(const Poligono&);

// Muestra el punto que hay en esa posicion
Punto GetPuntoPorPosicion(const Poligono&, unsigned);

// Muestra la posicion donde se encuentra ese punto
int GetPosicionPorPunto(const Poligono&, const Punto&);

// Indica si un punto esta o no dentro del poligono (ray casting)
bool PuntoDentroDePoligono(const Punto&, const Poligono&);


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

    for(unsigned i{}; i < p.n - 1; i++)
        perimetro += GetDistancia(p.puntos.at(i), p.puntos.at(i + 1));

    perimetro += GetDistancia(p.puntos.at((p.n) - 1), p.puntos.at(0));

    return perimetro;
}

/*-----------------------------------------------------------------------------------------------*/

// Cantidad de Lados

unsigned GetCantidadDeLados(const Poligono& p){
    return p.n;
}

/*-----------------------------------------------------------------------------------------------*/

// Agregar punto al final del poligono

void Push(Poligono& p, const Punto nuevoPunto){
    if(p.n < p.puntos.size()){
        p.puntos.at(p.n) = nuevoPunto;
        p.n++;
    }
}

/*-----------------------------------------------------------------------------------------------*/

// Agregar punto por posicion

void Add(Poligono& p, const Punto& punto, unsigned pos) {
    if (p.n < p.puntos.size()) {
        for (unsigned i=p.n; i > pos; i--) {
            p.puntos.at(i) = p.puntos.at(i-1);
        }
        p.puntos.at(pos-1) = punto;
        p.n++;
    }
}

/*-----------------------------------------------------------------------------------------------*/

// Eliminar ultimo punto del poligono

void Pop(Poligono& p){
    if(p.n > 0){
        p.n--;
    }
}

/*-----------------------------------------------------------------------------------------------*/

// Remover punto dado

void RemovePorPunto(Poligono& p, const Punto puntoToRemove){
    for(unsigned i{}; i<p.n; i++){
        if(p.puntos.at(i).x == puntoToRemove.x and p.puntos.at(i).y == puntoToRemove.y){
            for(unsigned j=i; j<p.n; j++){
                p.puntos.at(j) = p.puntos.at(j+1);
            }
            p.n--;
        }
    }
}

/*-----------------------------------------------------------------------------------------------*/

// Remueve un punto dada una posicion

void RemovePorPosicion(Poligono& p, unsigned pos) {
    for (unsigned i{}; i < p.n; i++) {
        if (i == pos-1) {
            for (unsigned j = i; j < p.n; j++) {
                p.puntos.at(j) = p.puntos.at(j + 1);
            }
            p.n--;
        }
    }
}

/*-----------------------------------------------------------------------------------------------*/

// Muestra el ultimo punto

Punto Top(const Poligono& p){
    return p.puntos.at(p.n-1);
}

/*-----------------------------------------------------------------------------------------------*/

// Muestra el primer punto

Punto First(const Poligono& p){
    return p.puntos.at(0);
}

/*-----------------------------------------------------------------------------------------------*/

// Muestra el punto que hay en esa posicion

Punto GetPuntoPorPosicion (const Poligono& p, unsigned pos){
    return p.puntos.at(pos-1);
}

/*-----------------------------------------------------------------------------------------------*/

// Muestra la posicion donde se encuentra ese punto

int GetPosicionPorPunto(const Poligono& p, const Punto& punto){
    for(unsigned i{}; i<p.n; i++){
        if(p.puntos.at(i).x == punto.x and p.puntos.at(i).y == punto.y){
            return i+1;
        }
    }
    return -1;
}

/*-----------------------------------------------------------------------------------------------*/
