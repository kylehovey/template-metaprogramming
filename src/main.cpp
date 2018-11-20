#include <iostream>
#include "../dimensional.hpp"

int main() {
  meter<int> x = 2;
  seconds<int> y = 4;
  joule<int> z = 100;
  kilogram<int> w = 1;

  auto thing = z + ((w * x * x) / (y * y));

  std::cout << thing << std::endl;

  return EXIT_SUCCESS;
}
