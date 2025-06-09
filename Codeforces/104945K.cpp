#include <bits/stdc++.h>
using namespace std;

template <typename T, typename Op>
class SegTree {
public:
  vector<T> tree;
  int n;
  Op op;

  SegTree(const vector<T> & v) {
    n = v.size();
    int size = 1;
    while (size < n) size <<= 1;
    tree.resize(2 * size);

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

struct TakenOp {
  using T = int;

  inline T operator()(T a, T b) const {
    return a + b;
  }

  inline T id() const {
    return 0;
  }
};

int findKthRemaining(SegTree<int, TakenOp> &segTree, int n, int k) {
  int curr = 0, low = 0, high = n - 1;
  while (high > low) {
    int mid = (high - low) / 2 + low;
    int leftChild = 2 * curr + 1;

    int takenLeft = segTree.tree[leftChild];
    int remainingLeft = (mid - low + 1) - takenLeft;

    if (remainingLeft >= k) {
      curr = leftChild;
      high = mid;
    } else {
      k -= remainingLeft;
      curr = 2 * curr + 2;
      low = mid + 1;
    }
  }
  return low;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> v(n), a(n / 2), b(n / 2);

  SegTree<int, TakenOp> segTree(v);

  for (int i = 0; i < n / 2; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n / 2; i++) {
    cin >> b[i];
  }

  vector<int> teamA(n / 2), teamB(n / 2);
  for (int k = 0; k < n; k++) {
    int kh = k / 2;
    if (k % 2 == 0) { // team A
      int i = findKthRemaining(segTree, n, a[kh]);
      segTree.update(i, 1);
      teamA[kh] = i;
    } else { // team B
      int i = findKthRemaining(segTree, n, b[kh]);
      segTree.update(i, 1);
      teamB[kh] = i;
    }
  }

  for (int i = 0; i < n / 2; i++) {
    cout << teamA[i] + 1 << (i == n / 2 - 1 ? "" : " ");
  }
  cout << endl;

  for (int i = 0; i < n / 2; i++) {
    cout << teamB[i] + 1 << (i == n / 2 - 1 ? "" : " ");
  }
  cout << endl;
  
  return 0;
}
