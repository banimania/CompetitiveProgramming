#include <iostream>

int main() {
  int tt;
  std::cin >> tt;
  long long int solutions[tt];


  for (int t = 0; t < tt; t++) {
    long long int a, b;
    std::cin >> a >> b;

    long long int max = 0;

    if (a >= b) max = a;
    else {
      /*while (true) {
        a--;
        b -= 2;
        if (a >= b) {
          max = std::max(a, max);
        }
        if (a < 0) break;
      }*/
      long long int aux = b - a;
      if (a - aux <= 0) max = 0;
      else max = a - aux;
    }

    solutions[t] = max;
  }
  
  for (int t = 0; t < tt; t++) {
    std::cout << solutions[t] << std::endl;
  }
  

  return 0;
}
