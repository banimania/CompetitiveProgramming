#include <bits/stdc++.h>
using namespace std;

int main() {
  string line;
  while (getline(cin, line)) {
    if (line == "XXX") break;

    string aux;
    for (int i = 0; i < line.size(); i++) {
      if (line[i] != ' ') aux.push_back(tolower(line[i]));
    }

    bool ans = true;

    for (int i = 0; i <= aux.size() / 2; i++) {
      if (aux[i] != aux[aux.size() - 1 - i]) {
        ans = false;
        break;
      }
    }

    cout << (ans ? "SI" : "NO") << endl;
  }
  return 0;
}
