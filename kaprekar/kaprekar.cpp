#include <string>
#include <iostream>
#include <vector>

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
void ordAscB(std::vector<int>& digitos)
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


void ordDescB(std::vector<int>& digitos)
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


bool repdigit(int& numero)
{

	int num = numero;

	int ultima = num % 10;
	
	bool es = true;

	num /= 10;

	while (es && num != 0)
	{
		if (ultima != num % 10)
			es = false;
		
		num /= 10;
	}

	return es;
}


 int kaprekar(int& numero)
 {
 		int desc;
		int asc;
		int vueltas = 0;

		std::vector<int> vnumero;
		vnumero = tovector(numero);

		ordDescB(vnumero);
		desc = toint(vnumero);

		ordAscB(vnumero);		
		asc = toint(vnumero);		

		int operar = 0;
		
		while(vueltas <= 6 && operar != 6174)
		{
			operar = desc - asc;

			vnumero = tovector(operar);

			ordDescB(vnumero);
			desc = toint(vnumero);
			
			ordAscB(vnumero);
			asc = toint(vnumero);

			vueltas++;
		}
		
		return vueltas;
 }
 
/*
	obtener el valor de salida de un numero leido
*/
int iteraciones(int& numero)
{
	if (numero == 6174)
		return 0;

	else if (repdigit(numero) && numero >= 1000)
		return 8;

	else
		return kaprekar(numero);
}


void leerFichero()
{
	int numero;

	while(!std::cin.eof())
	{
		std::cin >> numero;
		
		if (!std::cin.eof() && numero >= 1000)
			std::cout << iteraciones(numero) << std::endl;
	}
	
	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	leerFichero();

}











