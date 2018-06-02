#include <iostream>
#include <string>
#include <algorithm>

int main ()
{
  std::string line;
  std::string inv;
  getline(std::cin, line);

  while (line.compare ("XXX") != 0)
  {
    //remove_if(line.begin(), line.end(), isspace);
    line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
    //line[0] = ::tolower(line[0]);
    std::transform(line.begin(), line.end(), line.begin(), ::tolower);
    std::string inv (line.rbegin(), line.rend());

    if (line.compare(inv) == 0)
      std::cout << "SI" << std::endl;
    else
      std::cout << "NO" << std::endl;

    getline(std::cin, line);
  }
}
