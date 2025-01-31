#include <bits/stdc++.h>
#include <deque>
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

#define TESTCASES false

void solve() {
  ll n, k1, k2;
  cin >> n;
  cin >> k1;
  vll d1(k1);
  SCAN(d1, k1);
  cin >> k2;
  vll d2(k2);
  SCAN(d2, k2);

  deque<ll> deck1(d1.begin(), d1.end());
  deque<ll> deck2(d2.begin(), d2.end());

  int i = 0;
  while (!deck1.empty() && !deck2.empty() && i < 1000) {
    ll card1 = deck1.front(), card2 = deck2.front();
    //cout << "TURN #" << i << endl;
    //cout << "DECK1: " << deck1.size() << " DECK2: " << deck2.size() << endl;
    //cout << "FRONT1: " << card1 << " FRONT2: " << card2 << endl;
    if (card1 > card2) {
      deck2.pop_front();
      deck1.pop_front();
      deck1.push_back(card2);
      deck1.push_back(card1);
      //cout << "CARD1 WINS CARD2 " << endl;
    } else {
      deck2.pop_front();
      deck1.pop_front();
      deck2.push_back(card1);
      deck2.push_back(card2);
      //cout << "CARD2 WINS CARD1 " << endl;
    }
    i++;
  }

  if (deck1.empty() || deck2.empty()) {
    cout << i << " " << (deck2.empty() ? "1" : "2") << endl;
  } else cout << -1 << endl;

}

int main(){
  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
