#include<cassert>
#include<math.h>
#include<iostream>

struct Punto{
    double x,y;
};

struct Triangulo{
    Punto a,b,c;
};

double GetDistancia(const Punto&,const Punto&);
double GetPerimetro(const Triangulo&);
double GetArea(const Triangulo&);
bool IsEquilatero(const Triangulo&);
bool IsEscaleno(const Triangulo&);
bool IsIsosceles(const Triangulo&);

int main() {
    assert(GetPerimetro({{ 0,0},{ 3, 0},{0, 4}}) == 12   );
    assert(GetPerimetro({{ 1,1},{-8, 0},{3,-5}}) == 27.46);
    assert(GetPerimetro({{-7,0},{ 1,-1},{0, 0}}) == 16.47);

    assert(GetArea({{ 0,0},{ 3, 0},{0, 4}}) == 6   );
    assert(GetArea({{ 1,1},{-8, 0},{3,-5}}) == 28  );
    assert(GetArea({{-7,0},{ 1,-1},{0, 0}}) == 3.49);

    assert(IsEquilatero({{0,0},{1,sqrt(3)},{2,0}}) == true );
    assert(IsEquilatero({{0,0},{3,         0},{0,4}}) == false);
    assert(IsEquilatero({{0,0},{4,         0},{2,4}}) == false);

    assert(IsEscaleno({{0,0},{3,         0},{0,4}}) == true );
    assert(IsEscaleno({{0,0},{1,sqrt(3)},{2,0}}) == false);
    assert(IsEscaleno({{0,0},{4,         0},{2,4}}) == false);

    assert(IsIsosceles({{0,0},{1,sqrt(3)},{2,0}}) == false);
    assert(IsIsosceles({{0,0},{3,         0},{0,4}}) == false);
    assert(IsIsosceles({{0,0},{4,         0},{2,4}}) == true );

}

double GetDistancia(const Punto& p1,const Punto& p2){
    double d = std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    return(std::round(d*100)/100);
}

double GetPerimetro(const Triangulo& t){
    return (GetDistancia(t.a,t.b)) +
           (GetDistancia(t.b,t.c)) +
           (GetDistancia(t.c,t.a));
}

double GetArea(const Triangulo& t){
    double area = std::sqrt(GetPerimetro(t)/2 * (GetPerimetro(t)/2 - GetDistancia(t.a, t.b)) *
                           (GetPerimetro(t)/2 - GetDistancia(t.b, t.c)) *
                           (GetPerimetro(t)/2 - GetDistancia(t.c, t.a)));
    return(std::round(area*100)/100);
}

bool IsEquilatero(const Triangulo& t){
    double A = GetDistancia(t.a,t.b);
    double B = GetDistancia(t.b,t.c);
    double C = GetDistancia(t.a,t.c);
    return A == B and B == C ? true : false;
}

bool IsEscaleno(const Triangulo& t){
    double A = GetDistancia(t.a,t.b);
    double B = GetDistancia(t.b,t.c);
    double C = GetDistancia(t.a,t.c);
    return A != B and B != C and A != C ? true : false;
}

bool IsIsosceles(const Triangulo& t){
    double A = GetDistancia(t.a,t.b);
    double B = GetDistancia(t.b,t.c);
    double C = GetDistancia(t.a,t.c);
    return (A == B and A != C) or (A == C and A != B) or (B == C and B != A) ? true : false;
}




