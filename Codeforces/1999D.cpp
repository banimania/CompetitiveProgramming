#include <iostream>
#include <vector>
#include <string>
using namespace std;


typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vint;

#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define P(v) cout << #v << ": " << (v) << endl
// #define FILL(list) for (auto elem : list) cin>>elem
#define FILL(list) for (int i = 0; i < list.size(); ++i) cin >> list[i]
#define REPLIST(i, list) for (auto i : list)

#define PRINTLIST(a) cout << #a << ": "; for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout<<endl;
#define PRINT(v) cout << v << endl

#define SORTINCR(a) sort(a.begin(), a.end(), [](int x, int y) { return x < y; })
#define SORTDECR(a) sort(a.begin(), a.end(), [](int x, int y) { return x > y; })
#define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()

#define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
#define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))

#define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()

#define TESTCASES true

/*
accumulate
max_element
upper_bound
sortв
*/

// int repString(string k, string search){
//     int cnt = 0;
//     REP(i,0,k.size()){
//         if (k.substr(i,search.size()) == search) cnt++;
//     }
//     return cnt;
// }

// bool isEven(int num){
//     if (num % 2 == 0){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// int prefix_sum(vint a, int l, int r){
//     // l, r -> [0,+inf]
//     vint pref_sum(a.size());
//     pref_sum[0] = a[0];
//     REP(i, 1, a.size()){
//         pref_sum[i] = pref_sum[i - 1] + a[i];
//     }
//     return pref_sum[r] - (l == 0 ? 0:pref_sum[l-1]);
// }

void solve(int tt){
  string s, t;
  cin >> s;
  cin >> t;
  // P(s);
  int cnt = 0;
  REP(i,0, s.size()){
    if((s[i] =='?' || s[i] == t[cnt]) && cnt <= t.size()-1){
      s[i] = t[cnt];
      cnt++;
    }
    else if (s[i] == '?' && cnt >= t.size()){s[i] = 'x';}
  }
  // P(cnt);
  // P(t.size());
  // if(cnt >= t.size()-1){
  //     s.replace(i,(s.size()-(i)), (s.size()-(i)), 'x');
  // }
  if(cnt < t.size()){
    PRINT("NO");
  }
  else{
    PRINT("YES");
    PRINT(s);
  }
}



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  if (TESTCASES) {
    int tt; cin >> tt;
    REP(i, 1, tt+1) {
      solve(i);
    }
  } else solve(1);

  return 0;
}
