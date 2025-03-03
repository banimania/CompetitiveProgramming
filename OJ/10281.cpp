#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  string line;
  double travelled = 0;
  double lastTime = -1;
  double factor = 1000.0f / (60.0f * 60.0f);
  double speed = 0;
  while (getline(cin, line)) {
    bool query = true;
    string time, change;
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == ' ') {
        query = false;
        time = line.substr(0, i);
        change = line.substr(i + 1, line.size() - (i + 1));
      }
    }

    if (query) {
      time = line;
    }

    double seconds = stoi(time.substr(0, 2)) * 60 * 60 + stoi(time.substr(3, 2)) * 60 + stoi(time.substr(6, 2));

    if (lastTime != -1) {
      double elapsedTime = seconds - lastTime;
      travelled += elapsedTime * speed;
    }

    if (query) {
      cout << time << " " << fixed << setprecision(2) << (travelled / 1000.0f) << " km" << endl;
    }

    if (!change.empty()) {
      speed = stoi(change) * factor;
    }

    lastTime = seconds;
  }
  return 0;
}
