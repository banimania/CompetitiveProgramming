#include <iostream>

void solve() {
  int n, k;
  std::cin >> n >> k;
  
  int diags = 0;

  int i = 0;
  bool it = false;
  while (k > 0 && n - i != 0) {
    int diagSize = n - i;
    k -= diagSize;
    diags++;
    if (i == 0) i++;
    else {
      if (it) {
        it = false;
        i++;
      } else it = true;
    }
  }

  std::cout << diags << std::endl;
}
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
