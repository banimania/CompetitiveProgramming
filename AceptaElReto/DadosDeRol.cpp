#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;

    map<int, int> freq;
    int maxVeces = 0;

    for (int i = 1; i <= a; i++) {
      for (int j = 1; j <= b; j++) {
        int suma = i + j;
        freq[suma]++;
        maxVeces = max(maxVeces, freq[suma]);
      }
    }

    vector<int> sol;
    for (pair<int, int> f : freq) {
      if (f.second == maxVeces) {
        sol.push_back(f.first);
      }
    }
    for (int i = 0; i < sol.size(); i++) {
      cout << sol[i] << (i != sol.size() - 1 ? " " : "");
    }
    cout << endl;
  }
  return 0;
}
