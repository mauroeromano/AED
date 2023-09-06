#include <cassert>
#include <chrono>

using namespace std::chrono;

bool IsBisiestoStd(year);

int main() {
    assert (IsBisiestoStd(1600y));
    assert (IsBisiestoStd(1976y));
    assert (IsBisiestoStd(1988y));
    assert (IsBisiestoStd(2000y));
    assert (IsBisiestoStd(2004y));
    assert (IsBisiestoStd(2020y));
    assert (not IsBisiestoStd(2023y));
    assert (not IsBisiestoStd(1700y));
    assert (IsBisiestoStd(1200y)); // La funcion de la librería de chronos no tiene como condicion años menores a 1582 por lo tanto es una precondición y por eso da como bisiesto 1200.
    assert (not IsBisiestoStd(1900y));
}

bool IsBisiestoStd(year y){ return y.is_leap(); }