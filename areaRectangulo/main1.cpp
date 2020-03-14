#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define INT_DIGITS 5

int size = 362144;
uint16_t x1;
uint16_t x2;
uint16_t y_1;
uint16_t y2;
char linea[ 24 ] = { 0 }; // 10000_10000_10000_10000\n

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
  x1 = atoi( linea );
  for ( ; linea[ i ] != ' '; ++i );
  ++i;
  y_1 = atoi( linea + i );
  for ( ; linea[ i ] != ' '; ++i );
  ++i;
  x2 = atoi( linea + i );
  for ( ; linea[ i ] != ' '; ++i );
  ++i;
  y2 = atoi( linea + i );
} // end separarLinea

int main( void )
{
  int i;
  char bufferSalida[ size ];
  char *bufferPtr = bufferSalida;

  setvbuf(stdout, bufferSalida, _IOFBF, sizeof(bufferSalida));
  
  do {
    fgets( linea, 24, stdin );
    separarLinea();
    //printf( "%d %d %d", valores[ 0 ], valores[ 1 ], valores[ 2 ] );
    
    if ( y2 < y_1 || x2 < x1 ) break;
    
    strcpy( bufferPtr, itoa( (y2 - y_1) * (x2 - x1), &i ) );
    //printf( "%d\n", i );
    bufferPtr[ i++ ] = '\n';
    bufferPtr += i;
  } while( 1 );

  printf( "%s", bufferSalida );
  return 0;
} // end main
