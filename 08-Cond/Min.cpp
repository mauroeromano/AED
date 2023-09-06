/*
Ejercicio 2:
Min: Z -> Z / Min(x,y) = { x   x<y
			   { y   e.o.c
*/
#include<cassert>

int Min(int,int);

int main(){
	assert( Min( 1, 2) ==  1 );
	assert( Min( 2, 1) ==  1 );
	assert( Min( 2, 2) ==  2 );
	assert( Min(-2, 0) == -2 );
	assert( Min(-1,-5) == -5 );
	assert( Min( 0, 2) ==  0 );
}

int Min(int x,int y){ return x<y ? x : y; }
