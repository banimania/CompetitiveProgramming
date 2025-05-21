#include <bits/stdc++.h>
using namespace std;

struct Team {
  string name;
  int score, index;
};

int main() {
  int n;
  cin >> n;
  
  map<string, pair<int, int>> scores;
  for (int i = 0; i < n; i++) {
    string c;
    int p;
    cin >> c >> p;
    
    int cSum = 0, cMax = INT_MIN, cMin = INT_MAX;
    
    for (int i = 0; i < 6; i++) {
      int x;
      cin >> x;
      
      cSum += x;
      
      cMax = max(cMax, x);
      cMin = min(cMin, x);
    }
    
    cSum -= cMax;
    cSum -= cMin;
    
    scores[c] = {p * 10 + cSum, i};
  }
  
  vector<Team> v;
  
  for (auto [name, scoreIndex] : scores) {
    v.push_back({name, scoreIndex.first, scoreIndex.second});
  }
  
  sort(v.begin(), v.end(), [](const Team &a, const Team &b) {
    if (a.score == b.score) return a.index < b.index;
    return a.score > b.score;
  });
  
  for (int i = 0; i < v.size(); i++) {
    if (i != 0 && v[i].score < v[i - 1].score && i > 2) break;
    cout << v[i].name << " " << v[i].score << endl;
  }
  return 0;
}
