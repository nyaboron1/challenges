#include <iostream>
#include <iterator>

struct Coord
{
  int x1 = 0;
  int x2 = 0;
  int y1 = 0;
  int y2 = 0;

  friend std::istream&
  operator >> (std::istream& in, Coord& p_c)
  {
    return in >> p_c.x1
              >> p_c.y1
              >> p_c.x2
              >> p_c.y2;
  }

  inline Coord& operator = (Coord c)
  {
    x1 = c.x1;
    x2 = c.x2;
    y1 = c.y1;
    y2 = c.y2;
    return *this;
  }
};

int main ()
{
  std::istream_iterator<Coord> iit (std::cin);
  Coord c = *iit;

  while (!(c.x2 < c.x1) || !(c.y2 < c.y1))
  {
    std::cout << (c.x2 - c.x1) * (c.y2 - c.y1) << std::endl;
    c = *(++iit);
  }

  return 0;
}
