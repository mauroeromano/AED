#include<cassert>
#include"Punto.h"
#include"FuncionesAuxiliares.h"
#include"PoligonoContiguo.h"

// Pruebas sobre Poligonos

int main(){

    // Poligono 1 de prueba

    Poligono p;

    Push(p,{0,0});
    Push(p,{3,0});
    Push(p,{0,1.5});

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

    Poligono p2;

    Push(Push(Push(Push(p2,{0,0}),{4,0}),{4,2}),{0,2});

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