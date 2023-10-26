#include<cassert>
#include<numbers>
#include<cmath>

struct Punto{
    double x,y;
};

struct Circulo{
    Punto p;
    double r;
};

double GetCircunferencia(const Circulo&);
double GetArea(const Circulo&);
double GetDistancia(const Punto&,const Punto&);
bool IsDentro(const Circulo&, const Punto&);
Circulo& Mover(Circulo&,const Punto&);  // Interfaz fluida

int main(){
    assert(GetCircunferencia({{ 0,  0},0.5}) ==  3.14);
    assert(GetCircunferencia({{ 1,  1},  2}) == 12.57);
    assert(GetCircunferencia({{-2,  1},  4}) == 25.13);
    assert(GetCircunferencia({{ 8, -5},  1}) ==  6.28);

    assert(GetArea({{ 0,  0},0.5}) ==  0.79);
    assert(GetArea({{ 1,  1},  2}) == 12.57);
    assert(GetArea({{-2,  1},  4}) == 50.27);
    assert(GetArea({{ 8, -5},  1}) ==  3.14);

    assert(IsDentro({{ 0, 0},2},{1,1}) == true );
    assert(IsDentro({{ 4, 4},8},{2,0}) == true );
    assert(IsDentro({{-2,-3},1},{0,0}) == false);

    Circulo c = {{0,0},2};
    assert(IsDentro(c,{0,0}) == true );
    assert(IsDentro(c,{5,3}) == false);
    Mover(c,{6,4});
    assert(IsDentro(c,{0,0}) == false);
    assert(IsDentro(c,{5,3}) == true );
}

double GetCircunferencia(const Circulo& c){
    double circunf = (std::numbers::pi*(c.r)*2);
    return((round(circunf*100))/100);
}

double GetArea(const Circulo& c){
    double area = (std::numbers::pi*pow(c.r,2));
    return((round(area*100))/100);
}

double GetDistancia(const Punto& p1,const Punto& p2){
    double d = std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    return(std::round(d*100)/100);
}

bool IsDentro(const Circulo& c, const Punto& p){
    double d = GetDistancia(c.p,p);
    return d<c.r ? true : false;
}

Circulo& Mover(Circulo& c,const Punto& p){
    return c = {{p},{c.r}};
}
