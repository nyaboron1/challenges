#include <iostream>
#include <iterator>

#include <inttypes.h>

#define fori(x) for (int16_t i=0; i < x; ++i)
#define forj(x) for (int16_t j=0; j < x; ++j)

void identidad ( int16_t** matrix, int16_t size )
{
	int16_t aux = 0;
	int16_t aux1 = 0;

	fori(size)
	{
		forj(size) 
		{
			if ( i == j && matrix[i][j] != 1 )
				aux++;
			
			else if ( matrix[i][j] != 0 && (i != j) )
				aux1++;
		}
	}

	if ( aux != 0 || aux1 != 0 )
		std::cout << "NO" << std::endl;
	else
		std::cout << "SI" << std::endl;
}

void leerFichero ()
{
	int16_t** values;

	std::istream_iterator<int16_t> eos;
  	std::istream_iterator<int16_t> iit (std::cin);

  	int16_t size = *iit;
  	iit++;

	while ( size != 0 )
	{
		values = new int16_t* [size];

		fori(size) {
		  values[i] = new int16_t[size];
        }

		fori(size)
		{
			forj(size) 
			{
				values[i][j] = *iit;
				iit++;
			}
		}
		
		identidad(values, size);

		size = *iit;
		iit++;

		delete[] values;
	}
}

int main ()
{
	leerFichero();
}
