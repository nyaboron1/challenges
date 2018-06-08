#include <iostream>
#include <string>
#include <algorithm>

int main ()
{
  std::string line;
  std::string inv;
  std::string sal;
  getline(std::cin, line);

  while (line.compare ("XXX") != 0)
  {
    line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
    std::transform(line.begin(), line.end(), line.begin(), ::tolower);
    std::string inv (line.rbegin(), line.rend());

    if (line.compare(inv) == 0)
      sal += "SI\n";
    else
      sal += "NO\n";

    getline(std::cin, line);
  }
  
  std::cout << sal;
}