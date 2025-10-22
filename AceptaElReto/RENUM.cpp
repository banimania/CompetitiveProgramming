#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    unordered_map<int, int> renum;
    int nextLine = 10;
    vector<tuple<int, string, int>> program;

    while (true) {
      int ln;
      cin >> ln;
      if (ln == 0) break;

      string instr;
      cin >> instr;
      if (instr == "RETURN") {
        program.emplace_back(ln, instr, -1);
      } else {
        int dest;
        cin >> dest;
        program.emplace_back(ln, instr, dest);
      }
    }

    for (const tuple<int, string, int>& p : program) {
      int ln = get<0>(p);
      string instr = get<1>(p);
      int dest = get<2>(p);
      if (!renum.count(ln)) {
        renum[ln] = nextLine;
        nextLine += 10;
      }
    }

    for (const tuple<int, string, int>& p : program) {
      int ln = get<0>(p);
      string instr = get<1>(p);
      int dest = get<2>(p);
      if (dest != -1 && !renum.count(dest)) {
        renum[dest] = nextLine;
        nextLine += 10;
      }
    }

    for (const tuple<int, string, int>& p : program) {
      int ln = get<0>(p);
      string instr = get<1>(p);
      int dest = get<2>(p);
      cout << renum[ln] << " " << instr;
      if (dest != -1) cout << " " << renum[dest];
      cout << "\n";
    }
    cout << "---\n";
  }

  return 0;
}
