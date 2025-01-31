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

void solve() {
	ll n;
	cin >> n;
	vll h(n);
	SCAN(h, n);
	
	unordered_map<ll, ll> repetitions;
	int maxCount = 0;
	int masFrecuente = h[0];
	REP (i, 0, n) {
		repetitions[h[i]]++;
	}
	
	for (pair<ll, ll> par : repetitions) {
		if (par.second > maxCount) {
			maxCount = par.second;
			masFrecuente = par.first;
		}
	}
	
	/*int ans = 0;
	REP (i, 1, n) {
		if (h[i - 1] > h[i]) {
			h[i] = masFrecuente;
			ans++;
		}
	}*/
	cout << n - maxCount << endl;
}

int main() {
	ll t;
	cin >> t;
	
	while (t--) {
		solve();
	}
	
	return 0;
}
