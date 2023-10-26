#include<cassert>
#include<math.h>
// Punto = { (x,y) e RxR}

struct Punto{
    double x,y;
};

// ParteDelPlano = { (CuadranteI,...,CuadranteIV,EjeX,EjeY,Origen) e enum}

enum struct ParteDelPlano{
    Origen,
    CuadranteI,
    CuadranteII,
    CuadranteIII,
    CuadranteIV,
    EjeX,
    EjeY,
};

// GetParteDelPlano: Punto -> ParteDelPlano
ParteDelPlano GetParteDelPlano(const Punto&);

// Punto Extra
double GetDistanciaDosPuntos(const Punto&,const Punto&);
unsigned GetDistanciaAlOrigen(const Punto&);


int main(){

    assert(GetParteDelPlano({ 0, 0}) == ParteDelPlano::Origen)      ;
    assert(GetParteDelPlano({ 1, 1}) == ParteDelPlano::CuadranteI)  ;
    assert(GetParteDelPlano({-8, 2}) == ParteDelPlano::CuadranteII) ;
    assert(GetParteDelPlano({-5,-3}) == ParteDelPlano::CuadranteIII);
    assert(GetParteDelPlano({ 5,-7}) == ParteDelPlano::CuadranteIV) ;
    assert(GetParteDelPlano({ 4, 0}) == ParteDelPlano::EjeX)        ;
    assert(GetParteDelPlano({ 0,-3}) == ParteDelPlano::EjeY)        ;
    assert(GetParteDelPlano({ 1, 1}) != ParteDelPlano::Origen)      ;

    assert(GetDistanciaDosPuntos({3,0},{0,4}) == 5);

    assert(GetDistanciaAlOrigen({6,8}) == 10);


    // Falta probar estas dos ultimas con valores flotantes (redondeados?)
}

ParteDelPlano GetParteDelPlano(const Punto& p){
    if(p.x==0 and p.y==0){
        return ParteDelPlano::Origen;
    }
    else if(p.x>0 and p.y>0){
        return ParteDelPlano::CuadranteI;
    }
    else if(p.x<0 and p.y>0){
        return ParteDelPlano::CuadranteII;
    }
    else if(p.x<0 and p.y<0){
        return ParteDelPlano::CuadranteIII;
    }
    else if(p.x>0 and p.y<0){
        return ParteDelPlano::CuadranteIV;
    }
    else if(p.x!=0 and p.y==0){
        return ParteDelPlano::EjeX;
    }
    else if(p.x==0 and p.y!=0){
        return ParteDelPlano::EjeY;
    }
}

double GetDistanciaDosPuntos(const Punto& p1,const Punto& p2){
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

unsigned GetDistanciaAlOrigen(const Punto& p){
    return GetDistanciaDosPuntos(p,{0,0});
}