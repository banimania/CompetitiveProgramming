#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  char k;
  string s;
  cin >> n >> k >> s;

  for (int i = 0; i < n; i++) {
    if (k == s[i]) {
      cout << "Unnar fann hana!" << endl;
      return 0;
    }
  }

  cout << "Unnar fann hana ekki!" << endl;
  return 0;
}
