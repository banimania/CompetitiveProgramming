#include <algorithm>
#include <cmath>
#include <iostream>

int main() {

  int n;
  std::cin >> n;

  int children[n];
  for (int i = 0; i < n; i++){
    std::cin >> children[i];
  };

  std::sort(children, children + n, [](int a, int b) { return a > b; });

  int s = 0, e = n - 1;

  int minTaxis = 1;

  // 3 2 2 1 1 1 1 1
  int currentPointer = children[s];
  while (s <= e) {
    if (s == e) {
      minTaxis++;
      break;
    }
    if (currentPointer + children[e] <= 4) {
      //std::cout << "Emparejado " << children[s] << " con " << children[e] << " S = " << s << " E = " << e << std::endl;
      currentPointer += children[e];
      e--;
    }

    if (currentPointer + children[e] > 4){
      minTaxis++;
      s++;
      currentPointer = children[s];
    }
  }

  std::cout << minTaxis - 1 << std::endl;

  return 0;
}
