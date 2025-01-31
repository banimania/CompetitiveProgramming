#include <cmath>
#include <iostream>

bool isPrime(long long int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }

  return true;
}

int main() {
  int tt;
  std::cin >> tt;
  std::string sol[tt];

  for (int t = 0; t < tt; t++) {
    long long int a, b;
    std::cin >> a >> b;
    
    sol[t] = (a - b == 1 && isPrime(a + b)) ? "YES" : "NO";
  }

  for (int t = 0; t < tt; t++) std::cout << sol[t] << std::endl;
  return 0;
}
