#include <iostream>
#include "../dimensional.hpp"

int main() {
  meter<int> x = 2;
  seconds<int> y = 4;

  auto z = x * y;

  std::cout << z << std::endl;

  return EXIT_SUCCESS;
}
