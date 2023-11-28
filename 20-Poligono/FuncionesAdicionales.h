#include<math.h>

struct Punto{
    double x,y;
};



// Prototipos

// Distancia entre dos puntos
double GetDistancia(const Punto&, const Punto&);

// Devuelve el valor absoluto (modulo)
double Abs(double);

// Dado dos valores, redondea con una tolerancia de 0.01 (defecto)
bool AreNear(const double&, const double&, const double = 0.01);

// Compara si dos puntos son iguales
bool AreEqual(const Punto&, const Punto&);



// Funciones

double Abs(double x){
    return (x>0) ? x : -x;
}

bool AreNear(const double& a, const double& b, const double tolerance){
    return Abs(a-b) < tolerance;
}

double GetDistancia(const Punto& p1, const Punto& p2){
    return (std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2)));
}
bool AreEqual(const Punto& a, const Punto& b){
    return AreNear(a.x, b.x) and AreNear(a.y,b.y);
}