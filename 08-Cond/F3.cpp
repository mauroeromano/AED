/*
Ejercicio 3
F3: R-->R / func3(d) = {-d  si  d=[-3;3]}
                  {d   si  otherwise}
*/
#include <cassert>

double func3(double);

int main(){
    assert(-4 == func3(-4));
    assert(3 == func3(-3));
    assert(0 < func3(-2.5));
    assert(2 == func3(-2));
    assert(0 == func3(0));
    assert(-2 == func3(2));
    assert(0 > func3(2.5));
    assert(-3 == func3(3));
    assert(4 == func3(4));
}


double func3(double d){ return (d<=3 and d>=-3) ? -d : d; }
