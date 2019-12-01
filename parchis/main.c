#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define INT_DIGITS 5

int size = 262144;
int16_t valores[ 3 ] = { 0 }; // casillas - posicion - tirada
char linea[ 20 ] = { 0 };

char *itoa(int i, int* size)
{
  /* Room for INT_DIGITS digits, - and '\0' */
  static char buf[INT_DIGITS + 2];
  char *p = buf + INT_DIGITS + 1; /* points to terminating '\0' */
  int s = 0;
  
  *--p = '\n';
  do {
    s++;
    *--p = '0' + (i % 10);
    i /= 10;
  } while (i != 0);

  *size = s;
  
  return p;
}

void separarLinea() {
  int i = 0;
  valores[ 0 ] = atoi( linea );
  for ( ; linea[ i ] != ' '; ++i );
  ++i;
  valores[ 1 ] = atoi( linea + i );
  for ( ; linea[ i ] != ' '; ++i );
  ++i;
  valores[ 2 ] = atoi( linea + i );
} // end separarLinea

int main( void )
{
  unsigned int i;
  int posNueva;
  char bufferSalida[ size ];
  char *bufferPtr = bufferSalida;

  setvbuf(stdout, bufferSalida, _IOFBF, sizeof(bufferSalida));
  
  do {
    fgets( linea, 20, stdin );
    separarLinea();
    //printf( "%d %d %d", valores[ 0 ], valores[ 1 ], valores[ 2 ] );
    
    if ( valores[ 0 ] == 0 ) break;
    
    posNueva = valores[ 1 ] + valores[ 2 ];
    if ( posNueva > valores[ 0 ] ) {
      posNueva = valores[ 0 ] - ( posNueva - valores[ 0 ] );
    } // end if
    else if ( posNueva == valores[ 0 ] ) {
      posNueva = valores[ 0 ];
    } // end else
    
    strcpy( bufferPtr, itoa( posNueva, &i ) );
    //printf( "%d\n", i );
    bufferPtr[ i++ ] = '\n';
    bufferPtr += i;
  } while( 1 );

  printf( "%s", bufferSalida );
  return 0;
} // end main
