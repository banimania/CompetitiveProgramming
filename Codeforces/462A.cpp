#include <iostream>

int main() {
  int n;
  std::cin >> n;

  char map[n][n];


  for (int i = 0; i < n; i++) {
    std::string input;
    std::cin >> input;
    for (int j = 0; j < n; j++) {
      map[i][j] = input[j];
    }
  }

  bool res = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int no = 0;
      if (i > 0 && map[i - 1][j] == 'o') no++;
      if (i < n - 1 && map[i + 1][j] == 'o') no++;
      if (j > 0 && map[i][j - 1] == 'o') no++;
      if (j < n - 1 && map[i][j + 1] == 'o') no++;
      if (no % 2 != 0) res = false;
    }
  }

  std::cout << (res ? "YES" : "NO") << std::endl;

  return 0;
}

/*
#include <iostream>

int main() {
  int n;
  std::cin >> n;

  char map[n * n];


  for (int i = 0; i < n; i++) {
    std::string input;
    std::cin >> input;
    for (int j = 0; j < n; j++) {
      map[i * n + j] = input[j];
    }
  }

  bool res = true;
  for (int i = 0; i < n * n; i++) {
    int no = 0;

    if (i > 0 && map[i - 1] == 'o') no++;
    if (i < n * n - 1 && map[i + 1] == 'o') no++;
    if (i - n > 0 && map[i - n] == 'o') no++;
    if (i + n < n * n - 1 && map[i + n] == 'o') no++;

    if (i % n == 0) std::cout << std::endl;
    std::cout << no << " ";
    if (no % 2 != 0) res = false;
  }

  std::cout << (res ? "YES" : "NO") << std::endl;

  return 0;
}
*/
