#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  while (cin >> t && t) {
    int x = 0, sum = 0;
    do {
      cin >> x;

      sum += x;
    } while (x);

    int totalSec = sum * t;

    int sec = totalSec % 60;
    int min = (totalSec / 60) % 60;
    int hrs = (totalSec / 3600);

    string secStr = (sec <= 9 ? "0" : "") + to_string(sec);
    string minStr = (min <= 9 ? "0" : "") + to_string(min);
    string hrsStr = (hrs <= 9 ? "0" : "") + to_string(hrs);

    cout << hrsStr << ":" << minStr << ":" << secStr << endl;
  }

  return 0;
}
