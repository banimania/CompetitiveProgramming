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

int main() {
  string s1;
  cin >> s1;
  string s2;
  cin >> s2;
  string text;
  cin >> text;

  for (int i = 0; i < s1.length(); i++) {
    s1[i] = tolower(s1[i]);
    s2[i] = tolower(s2[i]);
  }

  string answer = "";
  for (int i = 0; i < text.length(); i++) {
    int index = find(s1.begin(), s1.end(), tolower(text[i])) - s1.begin();
    if (index == s1.length()) answer += text[i];
    else answer += isupper(text[i]) ? toupper(s2[index]) : tolower(s2[index]);
  }

  cout << answer << endl;
}
