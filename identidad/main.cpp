#include <iostream>
#include <iterator>

void print ( int16_t** matrix, int16_t size )
{
	for ( int i = 0; i < size; ++i )
	{
		for ( int j = 0; j < size; ++j )
			std::cout << matrix[i][j]; 

		std::cout << std::endl;
	}
}


bool identidad ( int16_t** matrix, int16_t size )
{
	int16_t aux = 0;
	int16_t aux1 = 0;

	for ( int i = 0; i < size; ++i )
	{
		for ( int j = 0; j < size; ++j ) 
		{
			if ( i == j && matrix[i][j] != 1 )
				aux++;
			
			else if ( matrix[i][j] != 0 && (i != j))
				aux1++;
		}
	}

	if ( aux != 0 || aux1 != 0 )
		return false;
	else
		return true;
}

void leerFicheroIterador ()
{
	int16_t** values;

	std::istream_iterator<int16_t> eos;
  	std::istream_iterator<int16_t> iit (std::cin);

  	int16_t size = *iit;
  	iit++;

	while ( size != 0 )
	{
		//std::cout << "size:" << size << std::endl;

		values = new int16_t* [size];

		for ( int i = 0; i < size; ++i )
		  values[i] = new int16_t[size];


		for ( int i = 0; i < size; ++i )
		{
			for ( int j = 0; j < size; ++j ) 
			{
				values[i][j] = *iit;
				iit++;
			}
		}
		
		if ( identidad(values, size) == true )
			std::cout << "SI" << std::endl;
		else
			std::cout << "NO" << std::endl;

		size = *iit;
		iit++;

		delete[] values;
	}
}



int main ()
{
	leerFicheroIterador();
}