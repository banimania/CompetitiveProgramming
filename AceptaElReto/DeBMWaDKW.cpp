#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int letrCode(char a) {
  int N = a - 'A';
  if (a > 'A') N--;
  if (a > 'E') N--;
  if (a > 'I') N--;
  if (a > 'O') N--;
  if (a > 'U') N--;
  if (a > 'Q') N--;
  return N;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    string num1;
    string letr1;
    string guion;
    string num2;
    string letr2;
    cin >> num1 >> letr1 >> guion >> num2 >> letr2;

    ll c1 = letrCode(letr1[0]) * 10000LL * 20LL * 20LL + letrCode(letr1[1]) * 10000LL * 20LL + letrCode(letr1[2]) * 10000LL + stoi(num1);
    ll c2 = letrCode(letr2[0]) * 10000LL * 20LL * 20LL + letrCode(letr2[1]) * 10000LL * 20LL + letrCode(letr2[2]) * 10000LL + stoi(num2);

    cout << abs(c2 - c1) + 1 << "\n";
  }
  return 0;
}
