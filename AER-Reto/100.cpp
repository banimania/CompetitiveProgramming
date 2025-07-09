#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int kaprekar(string nStr) {
  nStr.insert(nStr.begin(), 4 - nStr.size(), '0');
  if (nStr[0] == nStr[1] && nStr[2] == nStr[3] && nStr[0] == nStr[3]) return 8;

  if (nStr == "6174") return 0;

  sort(nStr.begin(), nStr.end());
  int b = stoi(nStr);
  reverse(nStr.begin(), nStr.end());
  int a = stoi(nStr);

  string newN = to_string(a - b);

  return 1 + kaprekar(newN);
}

void solve() {
  string n;
  cin >> n;

  cout << kaprekar(n) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}
