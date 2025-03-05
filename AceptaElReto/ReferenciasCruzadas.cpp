#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define TESTCASES 0

int main() {
  int n;
  while (cin >> n && n) {
    map<string, set<int>> ref;

    cin.ignore();

    string line;
    for (int i = 1; i <= n; i++) {
      getline(cin, line);
      line += " ";
      
      string current;
      for (int j = 0; j < line.size(); j++) {
        if (line[j] == ' ') {
          if (current.size() > 2) {
            ref[current].insert(i);
          }
          current.clear();
        } else {
          current += tolower(line[j]);
        }
      }
    }

    for (pair<string, set<int>> referencia : ref) {
      cout << referencia.first << " ";
      for (auto it = referencia.second.begin(); it != referencia.second.end();) {
        cout << *it << ((++it) == referencia.second.end() ? "" : " ");
      }
      cout << endl;
    }
    cout << "----" << endl;
    
  }
  return 0;
}
