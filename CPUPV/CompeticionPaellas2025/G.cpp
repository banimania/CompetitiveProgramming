#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename T, typename Op>
class SegTree {
public:
  vector<T> tree;
  int n;
  Op op;

  SegTree(const vector<T> & v) {
    n = v.size();
    tree.resize(4 * n);

    build(v, 0, 0, v.size() - 1);
  }

  void build(const vector<T>& arr, int node, int start, int end) {
    if (start == end) {
      tree[node] = arr[start];
    } else {
      int mid = (start + end) / 2;
      int leftChild = 2 * node + 1;
      int rightChild = 2 * node + 2;
      
      build(arr, leftChild, start, mid);
      build(arr, rightChild, mid + 1, end);

      tree[node] = op(tree[leftChild], tree[rightChild]);
    }
  }

  T query(int l, int r) {
    return query(0, 0, n - 1, l, r);
  }

  T query(int node, int start, int end, int L, int R) {
    if (R < start || end < L) {
      return op.id();
    }
    if (L <= start && end <= R) {
      return tree[node];
    }

    int mid = (start + end) / 2;
    int leftChild = 2 * node + 1;
    int rightChild = 2 * node + 2;

    T leftResult = query(leftChild, start, mid, L, R);
    T rightResult = query(rightChild, mid + 1, end, L, R);

    return op(leftResult, rightResult);
  }

  void update(int idx, T val) {
    update(0, 0, n - 1, idx, val);
  }

  void update(int node, int start, int end, int idx, T val) {
    if (start == end) {
      tree[node] = val;
    } else {
      int mid = (start + end) / 2;
      int leftChild = 2 * node + 1;
      int rightChild = 2 * node + 2;

      if (start <= idx && idx <= mid) {
        update(leftChild, start, mid, idx, val);
      } else {
        update(rightChild, mid + 1, end, idx, val);
      }

      tree[node] = op(tree[leftChild], tree[rightChild]);
    }
  }
};

struct MinOp {
  using T = int;

  T operator()(T a, T b) const {
    return min(a, b);
  }

  T id() const {
    return INT_MAX;
  }
};

struct MaxOp {
  using T = int;

  T operator()(T a, T b) const {
    return max(a, b);
  }

  T id() const {
    return INT_MIN;
  }
};

int main() {
  int n, d;
  cin >> n >> d;

  vector<int> pitch(n), beauty(n);
  for (int i = 0; i < n; i++) {
    cin >> pitch[i] >> beauty[i];
  }

  SegTree<int, MinOp> minPitchST(pitch), minBeautyST(beauty);
  SegTree<int, MaxOp> maxPitchST(pitch);

  vector<ll> dp(n + 1, -1);
  dp[n] = 0;

  for (int i = n - 2; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      ll k = j - i + 1;

      ll maxPitch = maxPitchST.query(i, j), minPitch = minPitchST.query(i, j);
      if (maxPitch - minPitch <= d && dp[j + 1] != -1) {
        ll harmony = (k - 1) * minBeautyST.query(i, j);
        dp[i] = max(dp[i], harmony + dp[j + 1]);
      }
    }
  }
  cout << max(dp[0], 0LL) << endl;

  return 0;
}
