#include <algorithm>
#include <iostream>

int main() {
  int tt;
  std::cin >> tt;
  int sol[tt];

  for (int t = 0; t < tt; t++) {
    int n;
    std::cin >> n;

    int a[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::cin >> a[i][j];
      }
    }

    int result = 0;

    /*for (int i = 0; i < n; i++) {
      int minNumber = a[i][0];
      int aux = 0;
      int j = 0;

      while (i + aux < n && j + aux < n) {
        if (a[i + aux][j + aux] < 0) minNumber = std::min(minNumber, a[i + aux][j + aux]);
        aux++;
      }
      result += -minNumber;
      //if (t == tt - 1) std::cout << "X=" << -minNumber << std::endl;
    }


    for (int j = 1; j < n; j++) {
      
      int minNumber = a[0][j];
      int aux = 0;
      int i = 0;

      while (i + aux < n && j + aux < n) {
        if (a[i + aux][j + aux] < 0) minNumber = std::min(minNumber, a[i + aux][j + aux]);
        aux++;
      }
      result += -minNumber;
      //if (t == tt - 1) std::cout << "Y=" << -minNumber << std::endl;
    }
    /*for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] < 0) {
          int minNumber = a[i][j];
          int aux = 1;
          while (i + aux < n && j + aux < n) {
            if (a[i + aux][j + aux] < 0) minNumber = std::min(minNumber, a[i + aux][j + aux]);
            aux++;
          }
          result += -minNumber;
        }
      }
    }*/

    for (int i = 0; i < n; i++) {
      int minNumber = 0;

      int j = 0;
      int aux = 0;
      while (i + aux < n && j + aux < n) {
        //std::cout << "[" << i << "," << j << "]" << a[i][j] << std::endl;
        if (a[i+aux][j+aux] < 0) minNumber = std::min(minNumber, a[i+aux][j+aux]);
        aux++;
      }
      //std::cout << "i=" << i << " " << -minNumber << std::endl;
      result += -minNumber;
    }

    for (int j = 1; j < n; j++) {
      int minNumber = 0;

      int i = 0;
      int aux = 0;
      while (i + aux < n && j + aux < n) {
        //std::cout << "[" << i << "," << j << "]" << a[i][j] << std::endl;
        if (a[i+aux][j+aux] < 0) minNumber = std::min(minNumber, a[i+aux][j+aux]);
        aux++;
      }
      result += -minNumber;
    }

    sol[t] = result;
  }

  std::cout << std::endl;

  for (int t = 0; t < tt; t++) {
    std::cout << sol[t] << std::endl;
  }

  return 0;
}
