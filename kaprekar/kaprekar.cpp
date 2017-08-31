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
		--completar;	
	}
}

void mergeDsc (std::vector<uint8_t>& vl, 
		  	std::vector<uint8_t>& vr,
		  	std::vector<uint8_t>& vs)
{

	uint8_t s = 0;
	uint8_t l = 0;
	uint8_t r = 0;

	while (l < vl.size() && r < vr.size())
	{
		if (vl[l] > vr[r])
		vs[s++] = vl[l++];
			
		else
			vs[s++] = vr[r++];
	}
	
		while (l < vl.size())
		vs[s++] = vl[l++];
		
		while (r < vr.size())
		vs[s++] = vr[r++];
		
		completarCeros(vs);
}

void mergeAsc (std::vector<uint8_t>& vl, 
		  	std::vector<uint8_t>& vr,
		  	std::vector<uint8_t>& vs)
{

	uint8_t s = 0;
	uint8_t l = 0;
	uint8_t r = 0;

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

void mergeSort (std::vector<uint8_t>& v, bool flag)
{
	uint16_t vsize = v.size();	
	
	if (vsize < 2)
		return;

	else
	{
		uint16_t mid = v.size() / 2;
		uint16_t ls = mid;
		uint16_t rs = vsize - mid;
	
		std::vector<uint8_t> lv;
		std::vector<uint8_t> rv;

		for (uint8_t i = 0; i < ls; ++i)
			lv.push_back(v[i]);
		
		for (uint8_t i = mid; i < vsize; ++i)
			rv.push_back(v[i]);
		
		mergeSort(lv,flag);
		mergeSort(rv,flag);
		
		if (flag)
			mergeAsc(lv, rv, v);
		else
			mergeDsc(lv, rv, v);


	}
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
		int16_t operar = 0;
		
		int8_t vueltas = 0;

		std::vector<uint8_t> vnumero;
		vnumero = tovector(numero);

		mergeSort(vnumero, true);		
		asc = toint16_t(vnumero);

		mergeSort(vnumero, false);
		desc = toint16_t(vnumero);		
		
		
		while (operar != 6174)
		{
			operar = desc - asc;
			
			vnumero = tovector(operar);
			
			mergeSort(vnumero, true);
			asc = toint16_t(vnumero);
			
			mergeSort(vnumero, false);
			desc = toint16_t(vnumero);
			
			++vueltas;
		}
		
		return vueltas;
 }
 

int16_t iteraciones(int16_t numero)
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

























