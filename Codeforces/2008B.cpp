#include <cmath>
#include <iostream>

typedef long long int ll;

int main() {
  int tt;
  std::cin >> tt;
  std::string res[tt];

  for (int t = 0; t < tt; t++) {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    bool answer = false;
    
    if (sqrt(n) - (int)sqrt(n) == 0) { // CUADRADO PERFECTO
      int l = sqrt(n);

      answer = true;
      for (int i = 0; i < n; i++) {
        if (l > i && s[i] == '0') answer = false;
        else if (i > n - l - 1 && s[i] == '0') answer = false;
        else if ((i % l == 0 || i % l == l - 1) && s[i] == '0') answer = false;
        else if ((i >= l && n - l - 1 >= i && i % l != 0 && i % l != l - 1) && s[i] == '1') answer = false;

        if (!answer) break;
      }
    };

    res[t] = (answer ? "Yes" : "No");
  }

  for (int t = 0; t < tt; t++) {
    std::cout << res[t] << std::endl;
  }

  return 0;
}
