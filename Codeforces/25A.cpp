#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int a[n];
  int evens = 0;
  int odds = 0;
  bool isEvenList = false;
 
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];

    if (a[i] % 2 == 0) evens++;
    else odds++;
    
    if (i >= 2) isEvenList = evens > odds;
  }

  int sus = 0;
  for (int i = 0; i < n; i++) {
    if (isEvenList && a[i] % 2 != 0) {
      sus = i;
      break;
    } else if (!isEvenList && a[i] % 2 == 0) {
      sus = i;
      break;
    }
  }
  sus++;
  std::cout << sus << std::endl;
}
