#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

int main() {
  int t;
  std::cin >> t;

  while(t--) {
    std::vector<std::tuple<int, int>> coords;
    for (int i = 0; i < 4; i++) {
      int a, b;
      std::cin >> a >> b;
      coords.push_back(std::make_tuple(a, b));
    }

    float v1 = 0;
    float v2 = 0;
    int cv1 = 0;
    int cv2 = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (i == j) continue;
        int a = std::get<0>(coords[i]);
        int c = std::get<0>(coords[j]);
        int b = std::get<1>(coords[i]);
        int d = std::get<1>(coords[j]);

        float value = std::sqrt(std::pow(a - c, 2) + std::pow(b - d, 2));
        if (value != v1 && v1 == 0) {
          v1 = value;
        } else if (value != v2 && v2 == 0) {
          v2 = value;
        }
        if (v1 == value) cv1++;
        else if (v2 == value) cv2++;
      }
    }
    
    int solution;

    if (cv1 == 8) solution = v1 * v1;
    else solution = v2 * v2;

    std::cout << solution << std::endl;
  }

  return 0;
}
