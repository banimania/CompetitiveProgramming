#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  vector<vector<bool>> lights(1'000, vector<bool>(1'000));

  string line;
  while (getline(cin, line)) {
    stringstream ss(line);

    string first;
    ss >> first;

    if (first == "toggle") {
      string start;
      ss >> start;

      int idx = start.find(",");
      int startX = stoi(start.substr(0, idx));
      int startY = stoi(start.substr(idx + 1, start.size() - idx));

      string through;
      ss >> through;

      string end;
      ss >> end;
      int idx2 = end.find(",");
      int endX = stoi(end.substr(0, idx2));
      int endY = stoi(end.substr(idx2 + 1, end.size() - idx2));

      for (int i = startX; i <= endX; i++) {
        for (int j = startY; j <= endY; j++) {
          lights[i][j] = !lights[i][j];
        }
      }
    } else {
      string state;
      ss >> state;

      string start;
      ss >> start;

      int idx = start.find(",");
      int startX = stoi(start.substr(0, idx));
      int startY = stoi(start.substr(idx + 1, start.size() - idx));

      string through;
      ss >> through;

      string end;
      ss >> end;
      int idx2 = end.find(",");
      int endX = stoi(end.substr(0, idx2));
      int endY = stoi(end.substr(idx2 + 1, end.size() - idx2));

      bool stateB = (state == "on");
      for (int i = startX; i <= endX; i++) {
        for (int j = startY; j <= endY; j++) {
          lights[i][j] = stateB;
        }
      }
    }

  }
  int cnt = 0;
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      cnt += lights[i][j];
    }
  }

  cout << cnt << endl;
  return 0;
}
