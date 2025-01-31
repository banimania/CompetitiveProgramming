#include <iostream>

int main() {
  int tt;
  std::cin >> tt;

  int sol[tt];
  for (int t = 0; t < tt; t++) {
    int n, k;
    std::cin >> n >> k;

    int nPeople = 0;
    int gold[n];
    int goldStolen = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> gold[i];
      if (gold[i] >= k) goldStolen += gold[i];
      else if (gold[i] == 0) {
        if (goldStolen > 0) {
          goldStolen--;
          nPeople++;
        }
      }
    }


    

    sol[t] = nPeople;

  }

  for (int t = 0; t < tt; t++) {
    std::cout << sol[t] << std::endl;
  }

  return 0;
}
