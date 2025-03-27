#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    string s1, s2;
    cin >> s1 >> s2;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    cout << (s1 == s2 ? "GANA" : "PIERDE") << endl;
  }
  return 0;
}
