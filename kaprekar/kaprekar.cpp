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

void merge (std::vector<int>& vl, 
		  std::vector<int>& vr,
		  std::vector<int>& vs)
{

	int s = 0;
	int l = 0;
	int r = 0;

	while (l < vl.size() && r < vr.size())
	{
		if (vl[l] < vr[r])
			vs[s++] = vl[l++];
			
		else
			vs[s++] = vr[r++];
	}
	
	while (l < vl.size())
		vs[s++] = vl[l++];
	
	while (r < vr.size())
		vs[s++] = vr[r++];
}

std::vector<int> merge_sort(std::vector<int> v)
{
	unsigned n = v.size();
	
	if (n < 2)
		return v;
	
	unsigned mid = n / 2;
	unsigned sleft = mid;
	unsigned sright = n - mid;
	
	unsigned i;
	
	std::vector<int> vleft;
	std::vector<int> vright;
	std::vector<int> salida;
	
	vleft.resize(sleft);
	vright.resize(sright);
		
	for (i = 0; i < sleft; ++i)
		vleft.push_back(v[i]);
	
	for (i = mid; i < n; ++i)
		vright.push_back(v[i]);
	
	vleft = merge_sort(vleft);
	vright = merge_sort(vright);
	merge(vleft, vright, v);
	
	return v;
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
int iteraciones(int numero)
{
	if (numero == 6174)
		return 0;

	else if (repdigit(numero) && numero >= 1000)
		return 8;

	else
		return kaprekar(numero);
}



void leerFicheroIF(char* namefich)
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
			
		else
		{
			numero = std::stoi(texto);
			std::cout << iteraciones(numero) << std::endl;
		}
	}

	std::cout << std::endl;

	file.close();
}


void leerFichero()
{
	std::string linea;
	int numero;


	while(!std::cin.eof())
	{
		std::cin.get();
		std::cin >> numero;
		std::cout << iteraciones(numero) << std::endl;
	}
	
	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	//leerFichero();
	
	
	std::vector<int> l = {0,0};
	std::vector<int> r = {0,0};
	std::vector<int> s = {0,0,0,0};
	
	std::vector<int> ordena = {8,5,4,1};
	
	merge_sort(ordena);

	for (int it : s)
		std::cout << it;
		
	
}











