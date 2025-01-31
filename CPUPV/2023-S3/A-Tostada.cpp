#include <iostream>

int main() {
  int l;
  std::cin >> l;
  char t[l * l];
  bool mermelada = false;
  for (int i = 0; i < l; i++) {
    std::string input;
    std::cin >> input;
    char c;
    for (int j = 0; j < l; j++) {
      c = input[j];
      t[i * l + j] = c;
      if (c == '#') mermelada = true;
    }

  }

  bool suerte = true;
  for (int i = 0; i < l; i++) {
    std::string input;
    std::cin >> input;
    char c;
    for (int j = 0; j < l; j++) {
      c = input[j];
      if (t[i * l + j] != c) {
        suerte = false;
      }
    }
  }
  
  if (!mermelada) {
    std::cout << "NO LLEVABA MERMELADA" << std::endl;
    return 0;
  }
  
  std::cout << (suerte ? "HA HABIDO SUERTE" : "TRAGEDIA") << std::endl;


	return 0;
}
