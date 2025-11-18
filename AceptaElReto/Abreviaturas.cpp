#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    string s;
    getline(cin, s);
    stringstream ss(s);
    string a;
    vector<string> v;
    while (ss >> a) {
      v.push_back(string(1, a[0]) + string(1, a[0]) + string(1, '.'));
    }

    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << (i == v.size() - 1 ? "\n" : " ");
    }
  }

  return 0;
}
