#include <iostream>
#include <string>
#include <algorithm>

int main ()
{
  std::string line;
  getline(std::cin, line);

  while (line.compare ("XXX") != 0)
  {
    remove_if(line.begin(), line.end(), isspace);
    std::transform(line.begin(), line.end(), line.begin(), ::tolower);
    std::string inv (line.rbegin(), line.rend());

    std::cout << line << std::endl;
    std::cout << inv << std::endl;
    std::cout << std::endl;

    getline(std::cin, line);
  }
}
/*






*/
