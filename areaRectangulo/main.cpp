#include <iostream>
#include <string>

int main() 
{
 uint16_t x1;
 uint16_t x2;
 uint16_t y1;
 uint16_t y2;
 
 std::ios::sync_with_stdio (false);
 
 std::string salida = "";
 int a = 0;
 
 while (std::cin >> x1 >> y1 >> x2 >> y2)
 {
	if (y2 >= y1 && x2 >= x1)
	{
		salida += std::to_string((y2 - y1) * (x2 - x1))+"\n";
	}
    
    else 
    	break;
 }
	std::cout << salida;

 return 0;

}