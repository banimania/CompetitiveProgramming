#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n,  m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    
    vector<int> dp(m + 1, 0);
    
    for (int i = 1; i <= m; i++) {
      dp[i] = dp[i - 1];
      
      if (b[i - 1] == a[dp[i - 1]]) dp[i]++;
    }
    
    cout << dp[m] << endl;
  }
  return 0;
}
