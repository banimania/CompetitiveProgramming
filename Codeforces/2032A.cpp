#include <cmath>
#include <iostream>

typedef long long int ll;

int main() {
  int tt;
  std::cin >> tt;
  std::string sol[tt];

  for (int t = 0; t < tt; t++) {
    int n;
    std::cin >> n;

    int a[2*n];
    int encendidos = 0;
    for (int i = 0; i < 2 * n; i++) {
      std::cin >> a[i];
      if (a[i]) encendidos++;
    }

    int min = encendidos % 2;
    int max = 0;
    if (n >= encendidos) {
      max = encendidos;
    } else {
      max = n - encendidos % n;
    }

    if (2 * n == encendidos) max = 0;

    sol[t] = std::string(std::to_string(min) + " " + std::to_string(max));
  }
  for (int i = 0; i < tt; i++) {
    std::cout << sol[i] << std::endl;
  }

  return 0;
}
