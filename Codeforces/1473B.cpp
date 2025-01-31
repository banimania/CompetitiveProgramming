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

int lcm(int a, int b) {
	vector<int> divisoresA, divisoresB;
	
	bool prime = false;
	while (a != 1 && !prime) {
		prime = true;
		for (int i = 2; i <= a; i++) {
			if (a % i == 0) {
				prime = false;
				a /= i;
				divisoresA.push_back(i);
			}
		}	
	}
	
	prime = false;
	while (b != 1 && !prime) {
		prime = true;
		for (int i = 2; i <= b; i++) {
			if (b % i == 0) {
				prime = false;
				b /= i;
				divisoresB.push_back(i);
			}
		}	
	}
	
	int lcm = 1;
	
	vector<int> divisores;
	for (int i = 0; i < divisoresA.size(); i++) {
		divisores.push_back(divisoresA[i]);
	}
	for (int i = 0; i < divisoresB.size(); i++) {
		int occurrencias = 0;
		int occurrenciasB = 0;
		for (int j = 0; j < divisores.size(); j++) {
			if (divisoresB[i] == divisoresB[j]) occurrenciasB++;
		}
		for (int j = 0; j < divisores.size(); j++) {
			if (divisoresB[i] == divisores[j]) occurrencias++;
		}
		if (occurrenciasB > occurrencias) divisores.push_back(divisoresB[i]);
	}
	
	for (int i = 0; i < divisores.size(); i++) lcm *= divisores[i];
	
	return lcm;
}

void solve() {
	string s1, s2;
	cin >> s1 >> s2;
	
	if (s2.length() > s1.length()) {
		swap(s2, s1);
	}
	
	bool s1MultiLetter = false, s2MultiLetter = false;
	REP (i, 1, s1.length()) {
		if (s1[i] != s1[i - 1]) s1MultiLetter = true;
	}
	
	REP (i, 1, s2.length()) {
		if (s2[i] != s2[i - 1]) s2MultiLetter = true;
	}
	
	int rel = 0;
	
	REP (i, 0, s1.length()) {
		if (s1[i] != s2[i % s2.length()]) {
			cout << -1 << endl;
			return;
		}
		
		if (i % s2.length() - 1 == 0) rel++;
	}
	
	if (s1MultiLetter || s2MultiLetter) {
		int length = lcm(s1.length(), s2.length());
		
		REP (i, 0, s1.length() * s2.length()) {
			if (s1[i % s1.length()] != s2[i % s2.length()]) {
				cout << -1 << endl;
				return;
			}
		}
		
		string ans = "";
		for (int i = 0; i < length; i++) {
			ans += s2[i % s2.length()];
		}
		cout << ans << endl;
		
		return;
	}
	
	if (!s1MultiLetter && !s2MultiLetter) {
		string ans = "";
		
		REP (i, 0, s1.length() * s2.length()) {
			if (s1[i % s1.length()] != s2[i % s2.length()]) {
				cout << -1 << endl;
				return;
			}
		}
		
		int rep = lcm(s2.length(), s1.length());
		REP (i, 0, rep) {
			if (s1[i % s1.length()] != s2[i % s2.length()]) {
				cout << -1 << endl;
				return;
			}
			ans += s1[i % s1.length()];
		}
		cout << ans << endl;
		return;
	}
}
 
int main() {
	ll t;
	cin >> t;
	
	while (t--) {
		solve();
	}
	
	return 0;
}
