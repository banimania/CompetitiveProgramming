#include <iostream>
#include <cmath>

int main() {
  int tt;
  std::cin >> tt;

  bool sol[tt];
  for (int t = 0; t < tt; t++) {
    long long int n, k;
    std::cin >> n >> k;

    /*long long int finalLeaves = 0;

    for (long long int i = n - k; i < n; i++) {
      finalLeaves += pow(i + 1, i + 1);
    }

    sol[t] = finalLeaves % 2 == 0;

    */

    /*int x = 0;

    for (long long int i = n - k; i < n; i++) {
      if (i % 2 == 0) x++;
      else x+=2;
    }

    sol[t] = x % 2 == 0;*/

    bool solucion;

    long long int suma = (n * (n + 1)) / 2 - ((n - k + 1) * (n - k)) / 2;
    solucion = suma % 2 == 0;

    /*if (n % 2 == 0 && k % 2 == 0) solucion = true;
    else if (n % 2 == 0 && k % 2 != 0) solucion = false;
    else if (n % 2 != 0 && k % 2 == 0) solucion = false;
    else solucion = true;*/

    sol[t] = solucion;

    //std::cout << "PARA T = " << t << " FINAL= " << finalLeaves << std::endl;
  }


  for (int t = 0; t < tt; t++) {
    std::cout << (sol[t] ? "YES" : "NO") << std::endl;
  }

  return 0;
}
