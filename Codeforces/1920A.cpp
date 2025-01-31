#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> ints_not_equal;
    int lowestGreater = INT_MAX;
    int greatestLower = INT_MIN;
    for (int i = 0; i < n; i++) {
      int a, x;
      std::cin >> a >> x;
      if (a == 3) {
        if (std::find(ints_not_equal.begin(), ints_not_equal.end(), x) == ints_not_equal.end()) {
          ints_not_equal.push_back(x);
        }
      } else if (a == 2) {
        if (x < lowestGreater) lowestGreater = x;
      } else if (a == 1) {
        if (x > greatestLower) greatestLower = x;
      }
    }

    int solution = 0;

    for (int x : ints_not_equal) {
      if (lowestGreater >= x && x >= greatestLower) solution--;
    }

    solution += lowestGreater - greatestLower + 1;
    if (lowestGreater < greatestLower) solution = 0;
    
    std::cout << solution << std::endl;
  }

  return 0;
}
