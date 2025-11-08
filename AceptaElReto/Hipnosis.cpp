#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string to_base_9(ll n) {
  string aux = "";
  while (n > 0) {
    aux += (char)((n % 9) + '0');
    n /= 9;
  }

  reverse(aux.begin(), aux.end());
  return aux;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, d;
  while (cin >> n >> d) {
    if (!n && !d) break;
    string b9 = to_base_9(n);
    char x = d + '0';

    for (int i = 0; i < b9.size(); i++) {
      if (b9[i] >= x) b9[i]++;

    }

    cout << b9 << "\n";
  }
  return 0;
}
