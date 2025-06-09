#include <bits/stdc++.h>
using namespace std;

int main() {
  int ans = 0;

  string line;

  while (getline(cin, line)) {
    int vowels = 0;
    bool oneDouble = false;

    for (int i = 0; i < line.size(); i++) {
      if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u') {
        vowels++;
      }

      if (i > 0) {
        if (line[i] == line[i - 1]) oneDouble = true;
      }
    }

    if (!oneDouble) continue;
    if (vowels < 3) continue;

    if (line.find("ab") != string::npos
    || line.find("cd") != string::npos
    || line.find("pq") != string::npos
    || line.find("xy") != string::npos) {
      continue;
    }

    ans++;
  }

  cout << ans << endl;

  return 0;
}
