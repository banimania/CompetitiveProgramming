#include <bits/stdc++.h>
using namespace std;

string toBinary(int n, int k) {
  string a(k, '0');

  int x = 0;
  while (n > 0) {
    a[k - 1 - x] = (n % 2) + '0';
    n /= 2;
    x++;
  }

  return a;
}

bool solve(int curr, vector<bool> &visited, int &visitedN, int n, vector<int> &path) {
  if (visitedN == visited.size()) return true;

  for (int i = 0; i < n; i++) {
    int newCurr = curr ^ (1 << i);
    if (!visited[newCurr]) {
      visited[newCurr] = true;
      path.push_back(newCurr);
      visitedN++;
      if (solve(newCurr, visited, visitedN, n, path)) return true;
      visitedN--;
      path.pop_back();
      visited[newCurr] = false;
    }
  }

  return false;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;

  vector<bool> visited(1 << n);
  visited[0] = true;
  vector<int> path = {0};
  int visitedN = 1;
  solve(0, visited, visitedN, n, path);

  for (int i = 0; i < path.size(); i++) {
    cout << toBinary(path[i], n) << "\n";
  }

  return 0;
}
