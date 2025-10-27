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

struct SumOp {
  using T = int;

  T operator()(T a, T b) const {
    return a + b;
  }

  T id() const {
    return 0;
  }
};

struct HasZero {
  using T = bool;

  T operator()(T a, T b) const {
    return a | b;
  }
  
  T id() const {
    return false;
  }
};


int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, c;
  while (cin >> n >> c) {
    if (!n && !c) break;

    vector<int> countNeg(n);
    vector<bool> hasZero(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;

      countNeg[i] = (x < 0 ? 1 : 0);
      hasZero[i] = (x == 0);
    }

    SegTree<int, SumOp> negTree(countNeg);
    SegTree<bool, HasZero> zeroTree(hasZero);

    for (int i = 0; i < c; i++) {
      char ch;
      cin >> ch;

      if (ch == 'C') {
        int pos, val;
        cin >> pos >> val;

        pos--;
        negTree.update(pos, (val < 0 ? 1 : 0));
        zeroTree.update(pos, (val == 0));
      } else if (ch == '?') {
        int a, b;
        cin >> a >> b;
        a--, b--;

        bool z = zeroTree.query(a, b);

        if (z) {
          cout << '0';
        } else {
          int negs = negTree.query(a, b);

          cout << (negs % 2 ? '-' : '+');
        }
      }
    }
    cout << "\n";
  }
  return 0;
}
