#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include <ctime>

/*
	5  -> 5000 - 5
	completar los ceros antes no significativos del numero
	despúes de ser ordenado de forma ascendente
*/
void completarCeros(std::vector<int>& digitos)
{
	int completar;

	completar = 4 - digitos.size();

	while (completar != 0)
	{
		digitos.push_back(0);
		completar--;	
	}
}

/*
	bubble short
*/
void ordAsc(std::vector<int>& digitos)
{
	for (unsigned int i = 0; i < digitos.size() - 1; ++i)
	{
		for (unsigned int j = i+1; j < digitos.size(); ++j)
		{
			if (digitos[i] > digitos[j])
			{
				int aux = digitos[i];
				digitos[i] = digitos[j];
				digitos[j] = aux;
			}
		}
	}
}

void ordDesc(std::vector<int>& digitos)
{
	for (unsigned int i = 0; i < digitos.size() - 1; ++i)
	{
		for (unsigned int j = i + 1; j < digitos.size(); ++j)
		{
			if (digitos[i] < digitos[j])
			{
				int aux = digitos[i];
				digitos[i] = digitos[j];
				digitos[j] = aux;
			}
		}
	}

	completarCeros(digitos);

}

/*
	separar el int por digitos, empezando por el ultimo,
	y por tanto insertando al principio del vector a  devolver
*/
std::vector<int> tovector(int numero)
{
	std::vector<int> digitos;
	
	while (numero > 0)
	{
		digitos.insert(digitos.begin(), numero%10);
		numero /= 10;
	}

	return digitos;
}

/*
	calcular el valor numerico en función de los dígitos
	del vector
*/
int toint(std::vector<int>& digitos)
{

	int factor = 1;
	int numero = 0;

	for (int i = digitos.size() - 1; i >= 0; --i)
	{
		numero += factor * digitos[i];
		factor *= 10;
	}

	return numero;
}

/*
	devuelve true si todos los digitos de la
	cifra son iguales
	
	5 => 0005 => false
*/
bool repdigit(int numero)
{
	int ultima = numero % 10;
	
	bool es = true;

	numero /= 10;

	while (es && numero != 0)
	{
		if (ultima != numero % 10)
			es = false;
		
		numero /= 10;
	}

	return es;
}

/*
	funcion aux: calcula kaprekar y devuelve el
	numero de iteraciones totales 
*/
 int kaprekar(int& numero)
 {
 		int desc;
		int asc;
		int vueltas = 0;

		std::vector<int> vnumero;
		vnumero = tovector(numero);

		ordDesc(vnumero);
		desc = toint(vnumero);

		ordAsc(vnumero);		
		asc = toint(vnumero);		

		int operar = 0;
		
		while(vueltas <= 6 && operar != 6174)
		{
			operar = desc - asc;

			vnumero = tovector(operar);

			ordDesc(vnumero);
			desc = toint(vnumero);
			
			ordAsc(vnumero);
			asc = toint(vnumero);

			vueltas++;
		}
		
		return vueltas;
 }
 
/*
	obtener el valor de salida de un numero leido
*/
int iteraciones(int numero)
{
	int vueltas = 0;

	if (numero == 6174)
		return 0;

	if (repdigit(numero) && numero >= 1000)
		return 8;

	else
		return kaprekar(numero);
}

/*
	leer cada cifra y obtener su valor de salida
*/
void leerFichero(char* namefich)
{
	std::string texto;

	int numero;

	std::ifstream file;

	file.open(namefich,std::ios::in);

	while (!file.eof())
	{
		std::getline(file, texto);
		
		if (file.eof())
			break;
			
		numero = std::stoi(texto);

		std::cout << iteraciones(numero) << std::endl;
	}

	std::cout << std::endl;

	file.close();
}

int main(int argc, char *argv[])
{
	double t0;
	double t1;
	double time;

	t0 = clock();
	
	leerFichero(argv[1]);
	
	t1 = clock();
	
	time = (t1-t0) / CLOCKS_PER_SEC;
	
	std::cout << "tiempo CPU: " << time << std::endl;
}



