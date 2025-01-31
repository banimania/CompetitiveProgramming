#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
  int s = 0;

  while (n != 0) {
    s += n % 10;
    n /= 10;
  }

  return s;
}

int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    cout << solve(n) << endl;
  }
  return 0;
}
