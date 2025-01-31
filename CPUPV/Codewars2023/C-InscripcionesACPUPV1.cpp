#include <iomanip>
#include <iostream>

int main() {
  long long int n;
  std::cin >> n;

  std::string letras = "TRWAGMYFPDXBNJZSQVHLCKE";

  char letra = letras[n % 23];

  std::cout << std::setw(8) << std::setfill('0') << n << letra << std::endl;
  return 0;
}
