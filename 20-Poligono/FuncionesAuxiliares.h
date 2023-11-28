#ifndef FUNCIONES_AUXILIARES_INCLUIDA
#define FUNCIONES_AUXILIARES_INCLUIDA

// Conjunto de Operaciones (declaracion)
double Abs(double);
bool AreNear(const double, const double, const double = 0.01);

// Conjunto de Operaciones (implementacion)
double Abs(double x){
    return (x>0) ? x : -x;
}

bool AreNear(const double a, const double b, const double tolerance){
    return Abs(a-b) < tolerance;
}

#endif