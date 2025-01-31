#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::string sol[n];

  for (int i = 0; i < n; i++) {
    std::string input;
    std::cin >> input;

    bool possible = true;

    for (int i = 1; i < input.length(); i++) {
      if (input[i] == input[i - 1] && input[i] != '?') possible = false;
    }

    if (!possible) sol[i] = "-1";
    else {
      for (int i = 0; i < input.length(); i++) {
        if (input[i] == '?') {
          std::vector<char> availableChars = {'a', 'b', 'c'};
          for (int j = 0; j < availableChars.size(); j++) {
            //std::cout << "CHECKING " << availableChars[j] << " I=" << i << std::endl;
            if (i < input.length() - 1 && input[i + 1] == availableChars[j]) {
              //std::cout << "LEFT ERASING " << availableChars[j] << std::endl;
              availableChars.erase(availableChars.begin() + j);
              j--;
              continue;
            }

            if (i > 0 && input[i - 1] == availableChars[j]) {
              //std::cout << "RIGHT ERASING " << availableChars[j] << std::endl;
              availableChars.erase(availableChars.begin() + j);
              j--;
              continue;
            }
          }
          input[i] = availableChars[0];
        }
      }
      sol[i] = input;
    }
  }

  for (int i = 0; i < n; i++) std::cout << sol[i] << std::endl;
  return 0;
}
