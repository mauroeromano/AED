# *Precedencia de Operadores — Bisiesto*

#### Objetivos
- Demostrar el uso de operadores booleanos y expresiones complejas
#### Temas
- Expresiones.
- Operadores booleanos: and, or, y not.
- Operador resto: %.
- Asociatividad de Operadores: ID ó DI.
- Precedencia de Operadores.
- Orden de evaluación de Operandos.
- Funciones.
- Precondiciones
  
#### Problema
- Desarrollar una función que dado un año, determine si es bisiesto

#### Restricciones
- El nombre de la función debe ser IsBisiesto 1.
- Aplicar operadores booleanos.
- No aplicar expresión condicional (?:, es decir, el operador ternario).
- No aplicar sentencia condicional (if, if-else, ni switch).
- Las pruebas deben realizarse con assert.

## Autores
- [Acosta, Tomas](https://github.com/Acosta-Tomas)
- [Alonso, David](https://github.com/DavidAlonsoCode)
- [Mardardjian, Joshua](https://github.com/lmardardjian)
- [Mendivil, Matias](https://github.com/MatiasMendivil)
- [Nadir, Maia](https://github.com/Maia18Nadir)
- [Romano, Mauro](https://github.com/mauroeromano)
- [Romero, Vanesa](https://github.com/vanenromero)
- [Simó, Bruno](https://github.com/BrunoSimoCaballero)


## Crédito Extra
9.6.1. Conceptos de Expresiones
Explique en readme.md los siguientes conceptos, haciendo referencia al árbol de expresión:
1. Asociatividad de Operadores.
 La asociatividad en C++ determina en los casos que tienen igualdad de prioridad los operadores, si se resuelve de "izquierda a derecha" o de "derecha a izquierda".
2. Precedencia de Operadores.
 La precedencia en C++ como en matemáticas, se trata del orden de prioridad en el que se evaluaran las operaciones, cuando haya más de un operador.
3. Orden de evaluación de Operandos: En este caso y por el tipo de orden que elegimos expresar. Se resolveria primero el && de izquierda a derecha, en el == eligirá cualquiera de los dos "caminos". En la otra rama, en el || ira de izquierda a derecha nuevamente. En lo siguiente volverá a resolverlo de manera aleatoria.
   
 (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0)

               a    100  a   400
                 \  /     \  /
       a     4     %    0  %    0
        \   /       \  /    \  /
          %      0   !=      ==
           \    /     \     /
             ==         ||
               \      /           
                \    /
                  &&
          
