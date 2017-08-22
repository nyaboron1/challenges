#include <iostream>
#include <fstream>

void imprimir_mensaje ()
{
	std::cout << "Hola mundo." << std::endl;
}

void emitir (int veces)
{
	for (int i = 0; i < veces; ++i)
	{
		imprimir_mensaje();
	}
}

void procesar_fichero (char* nArchivo)
{
	std::ifstream file;
	
	file.open(nArchivo);
	
	std::string numero;
	
	while (!file.eof())
	{
		if (file.eof())
			break;	

		file >> numero;
		
		emitir(std::stoi(numero));
	}
	
	file.close();
}

int main (int argc, char* argv[])
{
	procesar_fichero(argv[1]);
}
