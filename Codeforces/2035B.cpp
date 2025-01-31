#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

typedef long long int ll;
/*bool checkDiv(ll num) {
  return num % 33 == 0 && num % 66 == 0;
}*/

/*bool only36(long long int num) {
  while (num > 0) {
    int dig = num % 10;
    if (dig != 3 && dig != 6) return false;
    num /= 10;
  }
  return true;
}

long long int solve(long long int n) {
  if (n == 1) return -1;

  for (long long int i = pow(10, n - 1); i < pow(10, n); i++) {
    if (!only36(i)) continue;
    if (checkDiv(i)) return i;
  }

  return -1;
}

int main() {
  int tt;
  std::cin >> tt;
  long long int sol[tt];

  for (int t = 0; t < tt; t++) {
    int n;
    std::cin >> n;
    sol[t] = solve(n);
  }

  for (int t = 0; t < tt; t++) {
    std::cout << sol[t] << std::endl;
  }
}*/

std::string decimalABinario(ll dec, ll n) {
  if (dec == 0) return "0";
  std::string binario = "";
  ll cociente = dec;
  while (dec > 0) {
    binario.push_back((dec % 2) == 1 ? '1' : '0');
    dec /= 2;
  }


  std::reverse(binario.begin(), binario.end());

  while (binario.length() < n) {
    binario.insert(0, 1, '0');
  }
  return binario;
}

std::string gen36(int n) {
  std::vector<ll> generados;

  for (ll i = 0; i < pow(2, n); i++) {
    std::string binario = decimalABinario(i, n);
    for (ll j = 0; j < binario.length(); j++) {
      if (binario[j] == '0') binario[j] = '3';
      else binario[j] = '6';
    }
    if (binario.length() == n) {
      if (binario[binario.length() - 1] != '6') continue;
      // suma de los digitos
      int sumaDig = 0;
      int sumaDigPar = 0;
      int sumaDigImpar = 0;
      for (ll j = 0; j < binario.size(); j++) {
        sumaDig += binario[j] - '0';
        if (j % 2 != 0) sumaDigPar += binario[j] - '0';
        else sumaDigImpar += binario[j] - '0';
      }
      if (sumaDig % 3 == 0 && (sumaDigPar - sumaDigImpar) % 11 == 0) return binario;
    }
  }

  return "-1";
}

int main() {
  int tt;
  std::cin >> tt;
  std::string sol[tt];

  for (int t = 0; t < tt; t++) {
    int n;
    std::cin >> n;
    
    sol[t] = gen36(n);
  }

  for (int t = 0; t < tt; t++) {
    std::cout << sol[t] << std::endl;
  }



  return 0;
}
