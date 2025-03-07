#include <bits/stdc++.h>
using namespace std;

#define TESTCASES 1

void solve(int tt){
  int n; cin >> n;
  int moves = 0;
  while (n!=1) {
    if (n % 6 == 0) n /= 6;
    else if (n % 3 == 0) n *= 2;
    else {
      cout << -1 << endl;
      return;
    }
    moves++;
  }
  cout << moves << endl;
}



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  if (TESTCASES) {
    int tt; cin >> tt;
    for (int i = 1; i <= tt; i++) {
      solve(i);
    }
  } else solve(1);

  return 0;
}
