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

  ll query(int l, int r, int x) {
    return query(0, 0, n - 1, l, r, x);
  }

  ll query(int node, int start, int end, int L, int R, int x) {
    if (R < start || end < L) {
      return 0;
    }
    if (L <= start && end <= R) {
      return tree[node].size() - (upper_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin());
    }

    int mid = (start + end) / 2;
    int leftChild = 2 * node + 1;
    int rightChild = 2 * node + 2;

    int leftResult = query(leftChild, start, mid, L, R, x);
    int rightResult = query(rightChild, mid + 1, end, L, R, x);

    return leftResult + rightResult;
  }

  ll query2(int l, int r, int x) {
    return query2(0, 0, n - 1, l, r, x);
  }

  ll query2(int node, int start, int end, int L, int R, int x) {
    if (R < start || end < L) {
      return 0;
    }
    if (L <= start && end <= R) {
      return lower_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin();
    }

    int mid = (start + end) / 2;
    int leftChild = 2 * node + 1;
    int rightChild = 2 * node + 2;

    int leftResult = query2(leftChild, start, mid, L, R, x);
    int rightResult = query2(rightChild, mid + 1, end, L, R, x);

    return leftResult + rightResult;
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
  using T = ll;

  T operator()(T a, T b) const {
    return a + b;
  }

  T id() const {
    return 0;
  }
};

struct GreaterOp {
  using T = vector<int>;

  T operator()(T a, T b) const {
    vector<int> ans;
    
    int indexA = 0, indexB = 0;
    while (indexA != a.size() || indexB != b.size()) {
      if (indexA == a.size()) {
        ans.push_back(b[indexB]);
        indexB++;
      } else if (indexB == b.size()) {
        ans.push_back(a[indexA]);
        indexA++;
      } else {
        if (a[indexA] <= b[indexB]) {
          ans.push_back(a[indexA]);
          indexA++;
        } else {
          ans.push_back(b[indexB]);
          indexB++;
        }
      }
    }

    return ans;
  }

  T id() const {
    return {};
  }
};

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(1));
  for (int i = 0; i < n; i++) cin >> a[i][0];

  SegTree<vector<int>, GreaterOp> segTree(a);

  ll ans = 0;

  for (int j = 1; j < n - 1; j++) {
    ll greaterThan = segTree.query(0, j - 1, a[j][0]);
    ll lessThan = segTree.query2(j + 1, a.size() - 1, a[j][0]);

    ans += greaterThan * lessThan;
  }

  cout << ans << endl;
}
