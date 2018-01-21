#include <iostream>
#include <iterator>

#include <string>

void leerFicheroPrueba ()
{
	
	int16_t size;

	std::cin >> size;
	std::cin.ignore();

	int** values;
	values = new int* [size];

	for (int i = 0; i < size; ++i) {
	  values[i] = new int[size];
	}

	std::cout << size << std::endl;

	std::string linea;
	int16_t aux;
	while ( size != 0 )
	{
		aux = size;
		while ( aux > 0 )
		{
			std::getline( std::cin, linea);
			std::cout << linea << std::endl;

			aux--;
		}

		std::cin >> size;
		std::cin.ignore();

		std::cout<< size << std::endl;
	}
	
}


void leerFicheroIterador ()
{
	int** values;

	std::istream_iterator<int16_t> eos;
  	std::istream_iterator<int16_t> iit (std::cin);

  	int16_t size = *iit;
  	iit++;

	while ( size != 0 )
	{
		values = new int* [size];

		for (int i = 0; i < size; ++i)
		  values[i] = new int[size];


		for ( int i = 0; i < size; ++i )
		{
			for ( int j = 0; j < size; ++j ) 
			{
				values[i][j] = *iit;
				iit++;
			}
			std::cout<< std::endl;
		}

		size = *iit;
		iit++;

		delete[] values;
	}
}



int main ()
{
	//leerFichero();
	leerFicheroIterador();
}