#include <iostream>
#include <cassert>
using std::cout;
using std::cin;

int sumarEnteros(int,int);

int main(){
    int a, b;
    cout << "Ingrese dos valores enteros: "; cin>>a>>b;
    cout << "La suma es: " << sumarEnteros(a,b);

    assert(sumarEnteros( 1, 2) ==  3);
    assert(sumarEnteros(-1, 2) ==  1);
    assert(sumarEnteros( 1,-2) == -1);
    assert(sumarEnteros(-1,-2) == -3);
    assert(sumarEnteros( 0, 2) ==  2);
    assert(sumarEnteros( 1, 0) ==  1);
};

int sumarEnteros(int a,int b){
    return(a + b);
}

