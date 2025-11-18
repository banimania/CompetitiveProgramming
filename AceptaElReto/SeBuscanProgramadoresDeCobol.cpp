#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    string line;

    unordered_map<string, ll> variables;

    while (true) {
      getline(cin, line);

      if (line == "STOP.") break;

      vector<string> words;

      string curr = "";
      for (int i = 0; i < (int) line.size(); i++) {
        if (i == line.size() - 1) {
          words.push_back(curr);
        }
        if (line[i] == ' ') {
          words.push_back(curr);
          curr = "";
        } else {
          curr += line[i];
        }
      }

      if (words[0] == "MOVE") {
        variables[words[3]] = stoll(words[1]) % 100000LL;
      } else if (words[0] == "ADD") {
        bool giving = false;
        for (int i = 1; i < (int) words.size(); i++) {
          if (words[i] == "GIVING") {
            giving = true;
            break;
          }
        }

        ll suma = 0;
        bool sumando = true;

        int i;
        for (i = 1; i < (int) words.size(); i++) {
          if (words[i] == "TO") {
            sumando = false;
            break;
          } else {
            suma = (suma + variables[words[i]]) % 100000LL;
          }
        }
        i++;

        if (giving) {
          suma += variables[words[i]];
          i++;
          i++;

          for (; i < (int) words.size(); i++) {
            variables[words[i]] = suma % 100000LL;
          }
        } else {
          for (; i < (int) words.size(); i++) {
            variables[words[i]] = (variables[words[i]] + suma) % 100000LL;
          }
        }
      } else if (words[0] == "DISPLAY") {
        for (int i = 1; i < (int) words.size(); i++) {
          cout << (variables[words[i]] % 100000) << (i == (int) words.size() - 1 ? "" : " ");
        }
        cout << "\n";
      }
    }

    cout << "---\n";
  }

  return 0;
}
