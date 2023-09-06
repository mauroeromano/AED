/*
01-EjemplosTipo.cpp
Team 1
*/
#include <string>
#include <cassert>

int main (){
  /* Examples with "int" */
  assert (1 > 0); // Mayor que cero
  assert(1 <= 2); // Número entero sea menor o igual que otro número
  assert(2 == 2); // Número entero sea igual a un valor específico.
  assert(3 > 2);
  assert(1-2==-1);
  assert(3%2==1);
  assert(6%3 - 6%2- 6%1==0);
  assert(6/(-3)==-2);

  /* Examples with "unsigned" */
  assert((8u + 15u) != (10u + 14u));
  assert((8u + 5u * 5u) == 33u);
  assert((100u % 20u) < 2u);
  assert(1040u >= 1040u);
  assert(5u+7u == 12u);
  assert(7u-5u == 2u);
  assert(7u*5u == 35u);
  
  /* Examples with "boolean" */
  assert(true != false);
  assert( not(true) == false);
  assert(true || !true); // Uso un OR, true o no true - por propiedades logicas, da verdadero 
  assert(true && !false); // Uso un AND, true y no false 
  assert( !!true && not(false || false)); // !(!true) = true, not(false o false) = true, true y true = true

  /* Examples with "char" */
  assert('A' >= 'A' && 'A' <= 'Z'); // Verifica Si el caracter es una letra mayuscula.
  assert('d' >= 'a' && 'd' <= 'z'); //  Verifica si el caracter es una letra minuscula.
  assert('a' == 'a' || 'a' == 'e' || 'a' == 'i' || 'a' == 'o' || 'a' == 'u'); // Verifica si el caracter es una vocal.
  assert('D' >= 'A' && 'D' <= 'H'); // Verifica si el caracter está en un rango definido.
  assert('+' == '+' || '+' == '-' || '+' == '*' || '+' == '/'); // Verifica si el caracter es un operador.

  /* Examples with "string" */
  assert("Algoritmos" == "Algoritmos"); // Verificar si dos cadenas son iguales
  assert("Hola" != "Chau"); //  Verificar si dos cadenas son dinsintas	
  assert(std::string("Microprocesador") > std::string("Memoria")); // Verificar el orden alfabetico de dos cadenas (respecto valor ASCII)
  assert(std::string("AMD") < std::string("Intel")); // Verificar el orden alfabetico de dos cadenas (respecto valor ASCII)

  assert(std::string("Hola") + std::string(" como estas?") == std::string("Hola como estas?")); // Verificar la correcta concatenacion de dos cadenas
  assert(std::string("A") + std::string("B") != std::string("A B")); // Verificar la correcta concatenacion de dos cadenas

  assert(std::string("Sintaxis").length() == 8u); // Verificar el tamaño de la cadena /*OBS: la funcion length retorna un valor tipo unsigned
  assert(std::string("UTN FRBA").size() > std::string("UTN").size()); //  Verificar si una cadena tiene mas caracteres que otra /*OBS: la funcion size retorna un valor tipo unsigned
  assert(std::string("").empty() == true); // Verificar si la cadena esta vacia /*OBS: la funcion empty retorna un valor tipo bool*/
  
  /* Examples with "double" */
  assert(0.9 == (0.5 + 0.4)); // Se corrobora que 0,9 es igual a la suma de 0,5 con 0,4
  assert(0.54 < 0.81); // Si un número es mas chico que otro
  assert(1.5 != (0.2 * 0.8)); // Si un número es distinto a la multiplicación de dos valores.
  assert((4.4 / 2) == 2.2); // Si la division de dos valores es igual a un numero.
  assert(3.7 != (3.8 - 0.2)); // Si un numero es distinto a la resta de de dos valores.
  
  /* 
  Credito Extra  1
    Se observa que éste assert dá error, ya que la suma de diez veces un décimo, se acerca al número 1, pero no llega a serlo.
  */
  assert(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 == 1.0);

  /*
  Credito Extra 2
    No, estos no son los únicos datos que vimos pero si que probamos en clase relacionados a c++. Tambien vimos otros tipos de datos los cuales no 
    estan contemplados tales como:
      - Colores
      - Fechas
  */

  /*
  Credito Extra 3
  */
  assert('\x68'== 'h' );  // Cuando se carga '\x68' en char toma el codigo ascii y lo convierte al caracter
  assert('\x68'== 104u);  // Cuando se carga '\x68' en unsigned toma el hexadecimal y lo convierte a decimal

  assert(0x7f + 0xa == 0x89);  // 7f (hexa) + a (hexa) = 89 (hexa)
  assert(127u + 10u == 137u);  // 127 + 10 = 137 (ejemplo anterior en valores naturales correspondientes)
};
