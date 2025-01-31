#include <algorithm>
#include <iostream>

int main() {
  int n;
  std::cin >> n;
 
  int prices[n];
  for (int i = 0; i < n; i++) {
    std::cin >> prices[i];
  }
 
  int q;
  std::cin >> q;
 
  int dailyCoins[q];
  for (int i = 0; i < q; i++) {
    std::cin >> dailyCoins[i];
  }
 
  std::sort(prices, prices + n, [](int a, int b) { return a < b; });
 
  //for (int i = 0; i < n; i++) std::cout << prices[i] << std::endl; 
  int drinksPerDay[q];
  for (int i = 0; i < q; i++) {
    int coins = dailyCoins[i];
    int nShops = std::upper_bound(prices, prices + n, coins) - prices;

    drinksPerDay[i] = nShops;
  }

  for (int i = 0; i < q; i++) {
    std::cout << drinksPerDay[i] << std::endl;
  }
}
