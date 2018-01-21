#include <iostream>
#include <string>


void leerFichero ()
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

int main ()
{
	leerFichero();

}