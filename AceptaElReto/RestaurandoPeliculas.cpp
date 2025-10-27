#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int f, c;
  while (cin >> f >> c) {
    if (!f && !c) break;

    vector<pair<int, int>> fotogramasCopia;
    for (int i = 0; i < c; i++) {
      int aprovechables;
      cin >> aprovechables;
      for (int j = 0; j < aprovechables; j++) {
        string str;
        cin >> str;

        int coma = str.find(",");
        int ini = stoi(str.substr(0, coma));
        int fin = stoi(str.substr(coma + 1, str.size() - coma - 1));

        fotogramasCopia.push_back({ini, fin});
      }
    }

    sort(fotogramasCopia.begin(), fotogramasCopia.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
      if (a.first == b.first) return a.second > b.second;
      return a.first < b.first;
    });

    int siguiente = 1;

    for (int j = 0; j < fotogramasCopia.size(); j++) {
      if (fotogramasCopia[j].first <= siguiente) {
        siguiente = max(siguiente, fotogramasCopia[j].second + 1);
      } else break;
    }

    cout << (siguiente > f ? "SI\n" : "NO\n");

  }
  return 0;
}
