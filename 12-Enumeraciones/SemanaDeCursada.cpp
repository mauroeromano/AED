#include<cassert>

enum struct Asignatura{Algoritmos, Sintaxis, Ninguna};
enum struct Turno{Mañana, Tarde, Noche};
enum struct Dia{Domingo, Lunes, Martes, Miércoles, Jueves, Viernes, Sabado};

Turno TurnoQueCurso(Asignatura);
Dia DíaQueCurso(Asignatura);
Asignatura AsignaturaQueCurso(Dia,Turno);
bool TengoQueCursar(Dia, Turno);

int main(){

    assert( Dia::Jueves == DíaQueCurso(Asignatura::Algoritmos));
    assert( Dia::Lunes  == DíaQueCurso(Asignatura::Sintaxis  ));

    assert( Turno::Noche == TurnoQueCurso(Asignatura::Sintaxis  ));
    assert( Turno::Noche == TurnoQueCurso(Asignatura::Algoritmos));

    assert( TengoQueCursar(Dia::Lunes  ,Turno::Noche));
    assert( TengoQueCursar(Dia::Jueves ,Turno::Noche));

    assert( not TengoQueCursar(Dia::Lunes   ,Turno::Tarde ));
    assert( not TengoQueCursar(Dia::Jueves  ,Turno::Mañana));
    assert( not TengoQueCursar(Dia::Domingo ,Turno::Mañana));

    assert(Asignatura::Sintaxis   == AsignaturaQueCurso(Dia::Lunes   ,Turno::Noche  ));
    assert(Asignatura::Algoritmos != AsignaturaQueCurso(Dia::Lunes   ,Turno::Noche  ));
    assert(Asignatura::Algoritmos == AsignaturaQueCurso(Dia::Jueves  ,Turno::Noche  ));
    assert(Asignatura::Algoritmos != AsignaturaQueCurso(Dia::Viernes ,Turno::Mañana ));
    assert(Asignatura::Ninguna    == AsignaturaQueCurso(Dia::Sabado  ,Turno:: Mañana));
}


bool TengoQueCursar(Dia d, Turno t){
    return
            DíaQueCurso(Asignatura::Sintaxis) == d and
            TurnoQueCurso(Asignatura::Sintaxis) == t
            or
            DíaQueCurso(Asignatura::Algoritmos) == d and
            TurnoQueCurso(Asignatura::Algoritmos) == t;
}

bool TengoQueCursarBis(Dia d, Turno t){
    return
            d==Dia::Lunes and t==Turno::Noche
                              or
                              d==Dia::Jueves and t==Turno::Noche;
}

Dia DíaQueCurso(Asignatura a){return
            a == Asignatura::Algoritmos ? Dia::Jueves :
            Dia::Lunes ;}

Turno TurnoQueCurso(Asignatura a){return Turno::Noche;}

Asignatura AsignaturaQueCurso (Dia d,Turno t){
    return d == Dia::Lunes  and t == Turno::Noche ? Asignatura::Sintaxis
         : d == Dia::Jueves and t == Turno::Noche ? Asignatura::Algoritmos
         : Asignatura::Ninguna;

}
