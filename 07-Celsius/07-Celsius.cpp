// Farenheit -> Celcius : ( X°F - 32) * 5/9 = Y°C

#include <cassert>

double Celsius(double);
bool AreNear(double, double, double tol = 0.001);

double Abs(double); // Para no utilizar fabs() de <cmath>

int main() {

    assert(Celsius( 32) ==       0);
    assert(Celsius( 68) ==      20);
    assert(Celsius(-13) ==     -25);

//  assert(Celsius(180) == 82.2222); ERROR (82.2222 != 82.2222)

    assert(AreNear(Celsius(180), 82.2222));
    assert(AreNear(Celsius(-33),-36.1113));
    assert(AreNear(Celsius(0.2),-17.6667));
}

double Celsius(double d){
    return((d-32)*5/9);
}

double Abs(double x){
    return(x < 0) ? -x : x;
}

bool AreNear(double a, double b, double tol){
    return Abs(a-b) < tol;
}
