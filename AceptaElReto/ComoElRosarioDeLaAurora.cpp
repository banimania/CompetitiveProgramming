// TODO: arreglar

#include <bits/stdc++.h>
using namespace std;

template<typename T>
void make_set(vector<T> &dsu, T v) {
  dsu[v] = v;
}

template<typename T>
int find_set(vector<T> &dsu, T v) {
  if (v == dsu[v]) return v;
  return find_set(dsu, dsu[v]);
}

template<typename T>
void union_sets(vector<T> &dsu, T a, T b) {
  a = find_set(dsu, a);
  b = find_set(dsu, b);
  if (a != b) dsu[b] = a;
}

int main() {
  int n, p, a;
  while (cin >> n >> p >> a) {
    vector<int> dsu(n);
    for (int i = 0; i < n; i++) {
      make_set(dsu, i);
    }

    map<int, int> enemy;
    for (int i = 0; i < p; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;

      if (!enemy.count(a)) {
        enemy[a] = b;
      }

      if (!enemy.count(b)) {
        enemy[b] = a;
      }

      if (a != enemy[b]) {
        union_sets(dsu, enemy[b], a);
      }
      if (b != enemy[a]) {
        union_sets(dsu, enemy[a], b);
      }

    }

    map<int, int> sizes;
    for (int i = 0; i < n; i++) {
      sizes[find_set(dsu, i)]++;
    }

    vector<int> a1, a2;

    set<int> used;
    for (pair<int, int> size : sizes) {
      int group = size.first;
      int groupSize = size.second;

      if (!enemy.count(group)) {
        a1.push_back(groupSize);
        a2.push_back(groupSize);
        continue;
      }

      int enemyGroup = enemy[size.first];
      int enemyGroupSize = sizes[enemyGroup];

      if (used.count(group) || used.count(enemyGroup)) continue;

      used.insert(group);
      used.insert(enemyGroup);

      a1.push_back(groupSize);
      a2.push_back(enemyGroupSize);

    }

    int maxSum = 0;

    vector<vector<bool>> dp(a + 1, vector<bool>(a1.size() + 1, false));

    dp[0][0] = true;

    for (int j = 1; j <= a1.size(); j++) {
      for (int i = a; i >= 0; i--) {
        if (dp[i][j - 1]) {
          dp[i][j] = true;
          if (i + a1[j - 1] <= a) dp[i + a1[j - 1]][j] = true;
          if (i + a2[j - 1] <= a) dp[i + a2[j - 1]][j] = true;
        }
      }
    }

    for (int i = a; i >= 0; i--) {
      if (dp[i][a1.size()]) {
        maxSum = i;
        break;
      }
    }

    cout << maxSum << endl;
  }
  return 0;
}
