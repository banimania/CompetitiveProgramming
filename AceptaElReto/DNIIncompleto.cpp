#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> letraM = {
  {'T', 0},
  {'R', 1},
  {'W', 2},
  {'A', 3},
  {'G', 4},
  {'M', 5},
  {'Y', 6},
  {'F', 7},
  {'P', 8},
  {'D', 9},
  {'X', 10},
  {'B', 11},
  {'N', 12},
  {'J', 13},
  {'Z', 14},
  {'S', 15},
  {'Q', 16},
  {'V', 17},
  {'H', 18},
  {'L', 19},
  {'C', 20},
  {'K', 21},
  {'E', 22}
};

vector<int> pot10 = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

void solve(int i, const string &num, const char &letra, int &currNum, int &ans) {
  if (i == num.size()) {
    int mod = currNum % 23;

    if (letraM[letra] == mod) ans++;
    return;
  }

  if (num[i] == '?') {
    char start = '0';
    char end = '9';
    for (char x = start; x <= end; x++) {
      int pot = pot10[num.size() - 1 - i];

      int add = pot * (x - '0');

      currNum += add;

      solve(i + 1, num, letra, currNum, ans);

      currNum -= add;
    }
  } else {
    int pot = pot10[num.size() - 1 - i];

    int add = pot * (num[i] - '0');

    currNum += add;

    solve(i + 1, num, letra, currNum, ans);

    currNum -= add;
  }
  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    
    string num = s.substr(0, s.size() - 1);
    char letra = s[s.size() - 1];

    int currNum = 0;
    int ans = 0;

    solve(0, num, letra, currNum, ans);

    cout << ans << "\n";
  }
}
