
#include <stdio.h>
#include <uchar.h>

//int leerEntrada( char16_t *c, char16_t *p, char16_t *t );

int main( void )
{
  char16_t casillas,
     posicion,
     tirada,
     posNueva,
   aux;
  
  while ( scanf( "%d %d %d", &casillas, &posicion, &tirada ) && ( casillas != 0 ) ) {

    aux = posicion + tirada;

    if ( aux > casillas ) {
      //posNueva = casillas - ( aux - casillas );
       printf( "%d\n", casillas - ( aux - casillas ) );
    } // end if
    else if ( aux == casillas ) {
      //posNueva = casillas;
       printf( "%d\n", casillas );
    } // end else
    else {
      //posNueva = aux;
       printf( "%d\n", aux );
    } // end else

    //printf( "%d\n", posNueva );
  } // end while

  return 0;
} // end main

//int leerEntrada( char16_t *c, char16_t *p, char16_t *t )
//{
//  return ( 0 != ( scanf( "%u %u %u", c, p, t ) ) && ( *c != 0 ) );
//} // end leerEntrada
