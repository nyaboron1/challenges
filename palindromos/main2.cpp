#include <iostream>
#include <cinttypes>
#include <string>

// guardar la frase sin espacios y en minusculas
void LeerFrase (char* frase, int16_t& size)
{
	size = 0;

	int8_t letra = tolower (std::cin.get ());
	while (letra != '\n')
	{
		if (letra != ' ')
			*(frase+(size++)) = letra;

		letra = std::cin.get();
	}
}

int main ()
{
	char* frase = new char [200];
	int16_t size = 0;

	std::ios::sync_with_stdio (false);

	LeerFrase (frase, size);
	std::cout << "FRASE: \n" << frase << std::endl;
	
	std::string salida;

	while (frase[1] != 'X')
	{
		char* p_iz = nullptr;
		char* p_de = nullptr;
		bool ok = false;
		bool stop = false;
		for (int i = 0; i < size && stop == false; ++i)
		{
			p_iz = (frase + i);
			p_de = (frase + (size-i-1));

			if (p_iz == p_de || (p_iz + 1) == p_de)
				ok = true;

			else if (*p_iz != *p_de)
				stop = true;
		}

		if (ok == false)
			salida += "NO\n";
			
		else
			salida += "SI\n";

		if (frase != nullptr)
		{
			delete frase;
			frase = nullptr;
			frase = new char [200];
		}

		LeerFrase(frase, size);
		std::cout << "FRASE: \n" << frase << std::endl;
	}
	
	std::cout << salida;
}
