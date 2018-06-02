#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

void
CompletarCeros (std::vector<uint8_t>& digitos)
{
	int16_t completar;

	completar = 4 - digitos.size();

	while (completar != 0)
	{
		digitos.push_back(0);
		--completar;
	}
}


void
MergeSort (std::vector<uint8_t>& v)
{
	if (v.size() < 2)
		return;

	else
	{
		uint16_t vsize = v.size();
		uint16_t mid = v.size() / 2;
		uint16_t ls = mid;
		uint16_t rs = vsize - mid;

		std::vector<uint8_t> vl;
		std::vector<uint8_t> vr;

		for (uint8_t i = 0; i < ls; ++i)
			vl.push_back(v[i]);

		for (uint8_t i = mid; i < vsize; ++i)
			vr.push_back(v[i]);

		MergeSort(vl);
		MergeSort(vr);

		uint8_t s = 0;
		uint8_t l = 0;
		uint8_t r = 0;

		while (l < vl.size() && r < vr.size())
		{
			if (vl[l] > vr[r])
				v[s++] = vl[l++];

			else
				v[s++] = vr[r++];
		}

		while (l < vl.size())
			v[s++] = vl[l++];

		while (r < vr.size())
			v[s++] = vr[r++];
	}

	CompletarCeros(v);
}


std::vector<uint8_t>
ToVector (int16_t numero)
{
	std::vector<uint8_t> digitos;

	while (numero > 0)
	{
		digitos.insert(digitos.begin(), numero%10);
		numero /= 10;
	}

	return digitos;
}


int16_t
ToInt (std::vector<uint8_t>& digitos)
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

int16_t Kaprekar (int16_t& numero)
{
	int8_t vueltas = 0;

	std::vector<uint8_t> v = ToVector(numero);

	std::sort (v.begin(), v.end());
	int16_t asc = ToInt(v);

	std::sort (v.begin(), v.end(), std::greater<uint8_t>());
	int16_t desc = ToInt(v);

	while ((desc - asc) != 6174)
	{
		v = ToVector((desc - asc));

		std::sort (v.begin(), v.end());
		asc = ToInt(v);

		MergeSort(v);
		desc = ToInt(v);

		++vueltas;
	}

	return vueltas+1;
}

void LeerFichero()
{
	int16_t num;
	int entradas;
	std::cin >> entradas;

	for (int i = 0; i < entradas; ++i)
	{
		std::cin >> num;

		if (num == 6174)
			std::cout << 0 << std::endl;

		else if ((num % ((int)pow (10, (int)(log10(num)) - 1) / 9)) == 0)
			std::cout << 8 << std::endl;

		else
			std::cout << Kaprekar(num) << std::endl;
	}

	std::cout << std::endl;
}

int main()
{
	LeerFichero();
	return 0;
}
