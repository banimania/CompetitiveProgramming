#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  map<string, int> freq;
  for (int i = 0; i < n; i++) {
    string name, place;
    cin >> name >> place;

    freq[place]++;
  }

  for (auto [name, num] : freq) {
    cout << name << " " << num << endl;
  }
  return 0;
}
