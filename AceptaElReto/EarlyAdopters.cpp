#include <bits/stdc++.h>
using namespace std;

#define TESTCASES 1

typedef long long ll;

bool canBuildTree(int n, int k) {
  return (n < (1 << k));
}

bool solve(int low, int high, int k, vector<int> &orden, int currHeight) {
  if (!canBuildTree(high - low + 1, k - currHeight + 1)) return false;
  if (high == low) {
    orden.push_back(low);
    return true;
  }
  // cout << "T = " << low << " " << high << " " << currHeight << endl;

  int ini = low;
  int fin = (high - low) / 2 + low;

  int ans = fin;
  while (fin >= ini) {
    int mid = (fin - ini) / 2 + ini;

    int nL = mid - ini + 1;
    int nR = high - mid;

    bool canBuild = canBuildTree(nL, k - currHeight) && canBuildTree(nR, k - currHeight);

    if (canBuild) {
      fin = mid - 1;
      ans = mid;
    } else {
      ini = mid + 1;
    }
  }

  // cout << "X = " << ans << endl;

  orden.push_back(ans);
  if (ans == low) {
    solve(ans + 1, high, k, orden, currHeight + 1);
  } else if (ans == high) {
    solve(low, ans - 1, k, orden, currHeight + 1);
  } else {
    solve(low, ans - 1, k, orden, currHeight + 1);
    solve(ans + 1, high, k, orden, currHeight + 1);
  }

  return true;
}

// bool solve(int low, int high, int k, vector<int> &orden, int currHeight) {
//   if (low > high) return true;
//   if (currHeight > k) return false;

//   int lowest = INT_MAX;
//   for (int i = low; i <= high; i++) {
//     int sz = orden.size();
//     orden.push_back(i);

//     if (solve(low, i - 1, k, orden, currHeight + 1) && solve(i + 1, high, k, orden, currHeight + 1)) {
//       return true;
//     }

//     while (orden.size() != sz) orden.pop_back();
//   }

//   return false;
// }

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> orden;

  if (!solve(1, n, k, orden, 1)) {
    cout << "IMPOSIBLE" << "\n";
    return;
  }

  for (int i = 0; i < orden.size(); i++) {
    cout << orden[i] << (i != orden.size() - 1 ? " " : "");
  }
  cout << "\n";
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t = 1;
  if (TESTCASES) cin >> t;
  for (int i = 0; i < t; i++) solve();
  return 0;
}
