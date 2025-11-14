#include <bits/stdc++.h>
using namespace std;

vector<int> prefSum;
bool contiene(int l, int r, int indice) {
  return (indice >= l && indice <= r);
}

int sumaRango(int l, int r) {
  return prefSum[r] - (l > 0 ? prefSum[l - 1] : 0);
}

int solve(int l, int r) {
  int ans = 0;

  ans++;
  if (!sumaRango(l, r)) {
    return ans;
  }

  if (l == r) return ans;

  int mid = (r - l) / 2 + l;
  ans += solve(l, mid);
  ans += solve(mid + 1, r);
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  while (cin >> n && n) {
    cin.ignore();

    string s;
    cin >> s;

    prefSum = vector<int>(n);
    int suma = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') {
        suma++;
      }

      prefSum[i] = suma;
    }

    cout << solve(0, n - 1) << "\n";
  }
  return 0;
}
