#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<ll> vll;
 
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define SCAN(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define PRINT(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; }
#define PRINTLN(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout << endl
#define SORTASC(a) sort(a.begin(), a.end(), [](int x, int y) { return x < y; })
#define SORTDESC(a) sort(a.begin(), a.end(), [](int x, int y) { return x > y; })
#define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()
#define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()
#define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
#define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))

#define TESTCASES true

void solve() {
  ll n, x;
  cin >> n >> x;
  
  vector<ll> v1(n), v2(n), v3(n);

  REP (i, 0, n) {
    cin >> v1[n - i - 1];
  }
  REP (i, 0, n) {
    cin >> v2[n - i - 1];
  }
  REP (i, 0, n) {
    cin >> v3[n - i - 1];
  }

  stack<ll> stack1, stack2, stack3;
  REP (i, 0, n) {
    stack1.push(v1[i]);
    stack2.push(v2[i]);
    stack3.push(v3[i]);
  }

  int knowledge = 0;

  while ((!stack1.empty() || !stack2.empty() || !stack3.empty()) && knowledge < x) {
    bool hasRead = false;
    if (!stack1.empty()) {
      if ((stack1.top() | x) == x) {
        knowledge |= stack1.top();
        hasRead = true;
        stack1.pop();
        continue;
      }
    }
    if (!stack2.empty()) {
      if ((stack2.top() | x) == x) {
        knowledge |= stack2.top();
        hasRead = true;
        stack2.pop();
        continue;
      }
    }
    if (!stack3.empty()) {
      if ((stack3.top() | x) == x) {
        knowledge |= stack3.top();
        hasRead = true;
        stack3.pop();
        continue;
      }
    }

    if (!hasRead) break;
    /*if (stack1.empty() && !stack2.empty() && !stack3.empty()) {
      if ((knowledge | stack3.top()) == x) knowledge |= stack3.top(), stack3.pop();
      else if ((knowledge | stack2.top()) == x) knowledge |= stack2.top(), stack2.pop();
      else {
        if ((knowledge | stack3.top()) > x) knowledge |= stack2.top(), stack2.pop();
        else if ((knowledge | stack2.top()) > x) knowledge |= stack3.top(), stack3.pop();
        else {
          if ((knowledge | stack3.top()) > (knowledge | stack2.top())) {
            knowledge |= stack3.top();
            stack3.pop();
          } else {
            knowledge |= stack2.top();
            stack2.pop();
          }
        }
      }
    } else if (stack2.empty() && !stack1.empty() && !stack3.empty()) {
      if ((knowledge | stack3.top()) == x) knowledge |= stack3.top(), stack3.pop();
      else if ((knowledge | stack1.top()) == x) knowledge |= stack1.top(), stack1.pop();
      else {
        if ((knowledge | stack3.top()) > x) knowledge |= stack1.top(), stack1.pop();
        else if ((knowledge | stack1.top()) > x) knowledge |= stack3.top(), stack3.pop();
        else {
          if ((knowledge | stack3.top()) > (knowledge | stack1.top())) {
            knowledge |= stack3.top();
            stack3.pop();
          } else {
            knowledge |= stack1.top();
            stack1.pop();
          }
        }
      }
    } else if (stack3.empty() && !stack2.empty() && !stack1.empty()) {
      if ((knowledge | stack2.top()) == x) knowledge |= stack2.top(), stack2.pop();
      else if ((knowledge | stack1.top()) == x) knowledge |= stack1.top(), stack1.pop();
      else {
        if ((knowledge | stack2.top()) > x) knowledge |= stack1.top(), stack1.pop();
        else if ((knowledge | stack1.top()) > x) knowledge |= stack2.top(), stack2.pop();
        else {
          if ((knowledge | stack2.top()) > (knowledge | stack1.top())) {
            knowledge |= stack2.top();
            stack2.pop();
          } else {
            knowledge |= stack1.top();
            stack1.pop();
          }
        }
      }
    } else if (stack1.empty() && stack2.empty() && !stack3.empty()) {
      knowledge |= stack3.top();
      stack3.pop();
    } else if (stack2.empty() && stack3.empty() && !stack1.empty()) {
      knowledge |= stack1.top();
      stack1.pop();
    } else {
      knowledge |= stack2.top();
      stack2.pop();
    }*/
  }

  cout << (knowledge == x ? "YES" : "NO") << endl;
}

int main(){
  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
