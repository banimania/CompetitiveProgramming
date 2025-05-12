#include <bits/stdc++.h>
using namespace std;

template<typename T>
void make_set(vector<T> &dsu, vector<T> &size, T v) {
  dsu[v] = v;
  size[v] = 1;
}

template<typename T>
int find_set(vector<T> &dsu, T v) {
  if (v == dsu[v]) return v;
  return dsu[v] = find_set(dsu, dsu[v]);
}

template<typename T>
void union_sets(vector<T> &dsu, vector<T> &size, T a, T b) {
  a = find_set(dsu, a);
  b = find_set(dsu, b);
  if (a != b) {
    if (size[a] < size[b]) swap(a, b);
    dsu[b] = a;
    size[a] += size[b];
  }
}

int main() {
  int n;
  while (cin >> n) {
    vector<int> a(n), dsu(n), size(n);
    for (int i = 0; i < n; i++) {
      make_set(dsu, size, i);
      cin >> a[i];
      a[i]--;
    }
    
    vector<bool> visited(n);
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        visited[i] = true;

        stack<int> st;
        st.push(i);
        while (!st.empty()) {
          int curr = st.top();
          st.pop();

          int neighbour = a[curr];
          union_sets(dsu, size, neighbour, curr);
          if (!visited[neighbour]) {
            visited[neighbour] = true;
            st.push(neighbour);
          }
        }
      }
    }

    set<int> seen;
    int ans = 0;

    for (int i = 0; i < n; i++) {
      if (!seen.count(find_set(dsu, i))) {
        seen.insert(find_set(dsu, i));
        ans++;
      }
    }

    cout << ans << endl;

  }
  return 0;
}
