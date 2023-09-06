/*
Un año es bisiesto en el calendario Gregoriano, si es divisible entre 4 y no divisible entre 100, 
y también si es divisible entre 400.
*/
#include <cassert>

bool IsBisiesto(unsigned);

int main(){
    assert (IsBisiesto(1600));
    assert (IsBisiesto(1976));
    assert (IsBisiesto(1988));
    assert (IsBisiesto(2004));
    assert (IsBisiesto(2020));
    assert (not IsBisiesto(2023));
    assert (not IsBisiesto(2003));
    assert (not IsBisiesto(1200));
    assert (!IsBisiesto(1582));
    assert (IsBisiesto(2016));
    assert (IsBisiesto(2052));
}

bool IsBisiesto(unsigned a) {
    return (a > 1582 && a % 4 == 0 && (a % 100 != 0 || a % 400 == 0));
}
