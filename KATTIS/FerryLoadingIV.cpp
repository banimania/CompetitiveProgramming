#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
  int l, m;
  cin >> l >> m;
  l *= 100;
  int ans = 0;
  string currentDir = "left";
  int currentTot = 0;
  queue<int> leftQ, rightQ;
  for (int i = 0; i < m; i++) {
    int a;
    string dir;
    cin >> a >> dir;
    if (dir == "right") rightQ.push(a);
    else leftQ.push(a);
  }

  while (!leftQ.empty() || !rightQ.empty()) {
    if (currentDir == "left") {
      if (!leftQ.empty()) {
        if (currentTot + leftQ.front() <= l) {
          currentTot += leftQ.front();
          leftQ.pop();
          continue;
        }
      }
    } else {
      if (!rightQ.empty()) {
        if (currentTot + rightQ.front() <= l) {
          currentTot += rightQ.front();
          rightQ.pop();
          continue;
        }
      }
    }


    currentDir = (currentDir == "left" ? "right" : "left");
    ans++;
    currentTot = 0;
  }

  if (currentTot > 0) ans++;

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  for(int i = 0;i<t;i++){
    solve();
  }
  return 0;
}
