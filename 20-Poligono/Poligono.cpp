#include<array>
#include<cassert>
#include<cmath>
using std::array;

// Tipos de Datos

struct Punto{
    double x,y;
};

struct Poligono{
    unsigned n;
    array <Punto,100> puntos;
};


// Prototipo de Funciones Adicionales

double GetDistancia(const Punto&, const Punto&);


// Prototipo de Funciones s/Poligono

// Poligono x Punto -> Poligono,
void Push(Poligono&,const Punto&);       // modificamos el Poligono, no creamos uno nuevo
// Push(p,{1,2}); *Invocacion

// Otras versiones de Push

Poligono Push(Poligono,Punto);           // copio el poligono y creo uno nuevo (ocupa mas y tarda mas)
// p=Push(p,{1,2}); *Invocacion

Poligono& Push(Poligono&,const Punto&);  // INTERFAZ FLUIDA, retorna referencia
// Notacion pre-fijo (nombre de la funcion adelante)
// Push(p,{1,2}); *Invocacion
// Push(Push(p,{1,2}),{3,4});            // concatenacion de funciones

// Notacion su-fijo (nombre de la funcion detras)
// p.Push({1,2});                        // equivale a 35
// p.Push({1,2}).Push({3,4});            // equivale a 36

void Pop(Poligono&,const Punto&);
unsigned GetCantLados(const Poligono&);
double GetPerimetro(const Poligono&);
Punto Top(const Poligono&);
Punto First(const Poligono&);
Punto GetPuntoPorPosicion(const Poligono&, const unsigned&);
unsigned GetPosicionPorPunto(const Poligono&, const Punto&);



// Funcion Principal

int main(){

    // Creo un Poligono de 3 lados

    Poligono p;
    p.n = 3;

    p.puntos.at(0).x = 0;
    p.puntos.at(0).y = 0;

    p.puntos.at(1).x = 3;
    p.puntos.at(1).y = 0;

    p.puntos.at(2).x = 0;
    p.puntos.at(2).y = 4;

    // Otra forma de declararlo

    Poligono p2 = {4,{{{0, 0},{2, 0},{2, 2},{0,2}}}};

    // Pruebo Funciones

    assert(3  == GetCantLados(p));
    assert(4  == GetCantLados(p2));

    assert(3  == GetDistancia(p.puntos.at(0),p.puntos.at(1)));
    assert(4  == GetDistancia(p.puntos.at(0),p.puntos.at(2)));
    assert(5  == GetDistancia(p.puntos.at(1),p.puntos.at(2)));

    assert(12 == GetPerimetro(p));

    Punto primerPunto = First(p);
    assert(0  == primerPunto.x);
    assert(0  == primerPunto.y);

    Punto ultimoPunto = Top(p);
    assert(0  == ultimoPunto.x);
    assert(4  == ultimoPunto.y);
}


// Funciones Adicionales

double GetDistancia(const Punto& punto1, const Punto& punto2){
    return std::sqrt(std::pow(punto2.x - punto1.x, 2) + std::pow(punto2.y - punto1.y, 2));
}


// Funciones s/Poligonos

void Push(Poligono& p,const Punto& punto){

}

void Pop(Poligono& p,const Punto& punto){
    p.n--;
}

unsigned GetCantLados(const Poligono& p){
    return p.n;
}

double  GetPerimetro(const Poligono& p){
    return GetDistancia(p.puntos.at(0),p.puntos.at(1)) +
           GetDistancia(p.puntos.at(0),p.puntos.at(2)) +
           GetDistancia(p.puntos.at(1),p.puntos.at(2));
}

Punto Top(const Poligono& p){
    return p.puntos.at(p.n-1);
}

Punto First(const Poligono& p){
    return p.puntos.at(0);
}



/*
Punto GetPuntoPorPosicion(const Poligono& p, const unsigned& pos){
    for(int i{};i<p.n;i++)
    {
        return p.puntos.at(i);
    }
}
*/

// GetPosicionPorPunto : Poligono X Punto -> N

unsigned GetPosicionPorPunto(const Poligono& p,const Punto& punto){

    for(unsigned i{};i<p.n;i++){
        if(punto.x == p.puntos.at(i).x && punto.y == p.puntos.at(i).y) {
            return i;
        }
    }
    //return noesta;
}

// Arreglamos el problema en el caso que no se encuentre la posicion
// GetPosicionPorPunto : Poligono X Punto -> B X N

// Devuelve
bool GetPosicionPorPunto(const Poligono& p,const Punto& punto,unsigned& Pos);

// Ejemplo de uso
/*
unsigned n;
if(Posicion(p,a,n))
    cout<<n;
else
    cout<<"No esta";
*/

// Otra forma de hacerlo (al reves)
unsigned GetPosicionPorPunto(const Poligono& p,const Punto& punto,bool& Esta);

// Ejemplo de uso
/*
bool esta;
unsigned n = posicion(p,a,esta);
if(esta)
    cout<<n;
else
    cout<<"No esta";
*/



