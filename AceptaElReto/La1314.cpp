#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  string s;
  cin >> t;
  while (t--) {
    cin >> s;
    int g = s.find("-");

    int n1 = stoi(s.substr(0, g));
    int n2 = stoi(s.substr(g + 1));

    if (n1 > n2) swap(n1, n2);

    cout << (n2 == n1 + 1 && (n1 % 2 == 0) ? "SI" : "NO") << "\n";
  }
  return 0;
}
