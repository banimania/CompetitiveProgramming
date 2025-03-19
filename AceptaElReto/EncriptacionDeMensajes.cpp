#include <bits/stdc++.h>
using namespace std;

int negMod(int a, int m) {
  return ((a % m) + m) % m;
}

int main() {
  string s;
  while (getline(cin, s)) {
    char pc = s[0];

    s = s.substr(1, s.size() - 1);

    int dif = pc - 'p';

    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122)) {

        if (islower(s[i])) s[i] = negMod((s[i] - 'a') - dif, 26) + 'a';
        else s[i] = negMod((s[i] - 'A') - dif, 26) + 'A';

        char letra = tolower(s[i]);
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
          ans++;
        }
      }
    }
    if (s == "FIN") break;
    cout << ans << endl;
  }
  return 0;
}
