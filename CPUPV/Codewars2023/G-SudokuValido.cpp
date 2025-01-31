#include <algorithm>
#include <iostream>
#include <vector>

// TODO: arreglar

int main() {
  int sudoku[9][9];

  for (int i = 0; i < 9; i++) {
    std::string fila;
    std::cin >> fila;
    for (int j = 0; j < fila.length(); j++) {
      sudoku[i][j] = fila[j] - 48;
    }
  }

  for (int i = 0; i < 9; i++) {
    std::vector<int> ints;
    std::vector<int> ints2;
    for (int j = 0; j < 9; j++) {
      int n = sudoku[i][j];
      int n2 = sudoku[j][i];
      if (std::find(ints.begin(), ints.end(), n) != ints.end()) {
        std::cout << "No" << std::endl;
        return 0;
      } else ints.push_back(n);
      if (std::find(ints2.begin(), ints2.end(), n2) != ints2.end()) {
        std::cout << "No" << std::endl;
        return 0;
      } else ints2.push_back(n2);
    }
  }
  

  std::cout << "Si" << std::endl;



  return 0;
}
