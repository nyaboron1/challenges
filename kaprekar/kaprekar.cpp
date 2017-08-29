#include <string>
#include <iostream>
#include <vector>

void completarCeros(std::vector<uint8_t>& digitos)
{
	int16_t completar;

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
void ordAscB(std::vector<uint8_t>& digitos)
{
	for (uint16_t i = 0; i < digitos.size() - 1; ++i)
	{
		for (uint16_t j = i+1; j < digitos.size(); ++j)
		{
			if (digitos[i] > digitos[j])
			{
				int16_t aux = digitos[i];
				digitos[i] = digitos[j];
				digitos[j] = aux;
			}
		}
	}
}


void ordDescB(std::vector<uint8_t>& digitos)
{
	for (uint16_t i = 0; i < digitos.size() - 1; ++i)
	{
		for (uint16_t j = i + 1; j < digitos.size(); ++j)
		{
			if (digitos[i] < digitos[j])
			{
				int16_t aux = digitos[i];
				digitos[i] = digitos[j];
				digitos[j] = aux;
			}
		}
	}

	completarCeros(digitos);
}

std::vector<uint8_t> tovector(int16_t numero)
{
	std::vector<uint8_t> digitos;
	
	while (numero > 0)
	{
		digitos.insert(digitos.begin(), numero%10);
		numero /= 10;
	}

	return digitos;
}


int16_t toint16_t(std::vector<uint8_t>& digitos)
{

	int16_t factor = 1;
	int16_t numero = 0;

	for (int16_t i = digitos.size() - 1; i >= 0; --i)
	{
		numero += factor * digitos[i];
		factor *= 10;
	}

	return numero;
}


bool repdigit(int16_t& numero)
{

	int16_t num = numero;

	int16_t ultima = num % 10;
	
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


 int16_t kaprekar(int16_t& numero)
 {
 		int16_t desc;
		int16_t asc;
		int16_t vueltas = 0;
		int16_t operar = 0;

		std::vector<uint8_t> vnumero;
		vnumero = tovector(numero);

		ordDescB(vnumero);
		desc = toint16_t(vnumero);

		ordAscB(vnumero);		
		asc = toint16_t(vnumero);		
		
		while (operar != 6174)
		{
			operar = desc - asc;

			vnumero = tovector(operar);

			ordDescB(vnumero);
			desc = toint16_t(vnumero);
			
			ordAscB(vnumero);
			asc = toint16_t(vnumero);
			
			vueltas++;
		}
		
		return vueltas;
 }
 
/*
	obtener el valor de salida de un numero leido
*/
int16_t iteraciones(int16_t& numero)
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
	int16_t numero;

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
