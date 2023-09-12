#include <iostream>
#include <cassert>
using std::cout;
using std::cin;

bool IsBisiesto(unsigned);
unsigned GetCantidadDeDias(unsigned);

int main() {

    unsigned n;
    cout << "Ingrese un anio: "; cin >> n;
    cout << "Para el anio " << n << ", febrero tiene " << GetCantidadDeDias(n) << " dias.\n";

    // Prueba para años bisiestos

    assert (GetCantidadDeDias(1600) == 29);
    assert (GetCantidadDeDias(1976) == 29);
    assert (GetCantidadDeDias(1988) == 29);

    // Prueba para años no bisiestos

    assert (GetCantidadDeDias(2023) == 28);
    assert (GetCantidadDeDias(2003) == 28);
    assert (GetCantidadDeDias(1200) == 28);
}

bool IsBisiesto(unsigned a){
    return(a > 1582 && a % 4 == 0 && (a % 100 != 0 || a % 400 == 0));
}

unsigned GetCantidadDeDias(unsigned n){
    return( IsBisiesto(n) ? 29 : 28);
}
