/* 
Ejercicio 1:
abs: Z -> Z/ abs(x)= |x| = {-x  x<0
                          {x  e.o.c 
*/
#include<cassert>

int abs(int);

int main() {
    assert( 88 == abs(-88));
    assert(88 == abs(88));
    assert(56 == abs(56));
    assert(56 == abs(-56));
    assert( 0 == abs(0));

}

int abs(int n){ return n<0? -n : n; }
