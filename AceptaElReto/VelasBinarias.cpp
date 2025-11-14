#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string decToBin(ll n) {
  string ans = "";

  while (n > 0) {
    ans += (n % 2 == 0 ? '0' : '1');
    n /= 2;
  }

  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  ll n;
  while (cin >> n && n) {
    string bin = decToBin(n);

    int lastOne = 0;
    for (int i = bin.size() - 1; i >= 0; i--) {
      if (bin[i] == '1') {
        lastOne = i;
        break;
      }
    }

    string aux = bin.substr(0, lastOne + 1);

    bool ans = true;
    for (int i = 0; i < aux.size(); i++) {
      if (aux[i] != aux[aux.size() - 1 - i]) {
        ans = false;
        break;
      }

    }
    cout << (ans ? "SI\n" : "NO\n");
  }

  return 0;
}
