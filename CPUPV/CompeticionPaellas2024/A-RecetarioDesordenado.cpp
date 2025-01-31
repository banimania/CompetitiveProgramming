#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>

int compararStrings(std::string a, std::string b) {
  int minLength = fmin(a.length(), b.length());
  for (int i = 0; i < minLength; i++) {
    if (a[i] != b[i]) {
      return a[i] - b[i];
    }
  }
  return a.length() - b.length();
} 

int main() {
  std::string in;
  std::getline(std::cin, in);
  std::istringstream iss(in);

  std::vector<std::string> orden;
  std::string p;
  while (iss >> p) {
    int index = 0;
    for (int i = 0; i < orden.size(); i++) {
      std::string otherString = orden[i];
      if (compararStrings(p, otherString) < 0) {
        index = i;
        break;
      } else index = i + 1;
    } 
    orden.insert(orden.begin() + index, p);
  }

  for (int i = 0; i < orden.size(); i++) {
    std::cout << orden[i] << (i == orden.size() - 1 ? "" : " ");
  }
  std::cout << std::endl;
  return 0;
}
