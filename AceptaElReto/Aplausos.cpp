#include <bits/stdc++.h>
using namespace std;

struct Persona {
  int segundos;
  int personas;
  int i;
};

bool works(vector<Persona> &personas, int t) {
  priority_queue<int> pq;
  for (int i = personas.size() - 1; i >= 0; i--) {
    if (personas[i].segundos < t) {
      break;
    }

    pq.push(personas[i].personas);
  }

  int curr = pq.size();

  while (!pq.empty() && pq.top() > curr) {
    pq.pop();
    curr--;
  }

  return curr > 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    int maxSeg = 0;
    vector<Persona> personas(n);
    for (int i = 0; i < n; i++) {
      cin >> personas[i].segundos >> personas[i].personas;
      personas[i].i = i;
      maxSeg = max(maxSeg, personas[i].segundos);
    }

    sort(personas.begin(), personas.end(), [](const Persona &a, const Persona &b) {
      if (a.segundos == b.segundos) {
        return a.personas < b.personas;
      }
      return a.segundos < b.segundos;
    });

    int low = 0, high = maxSeg + 1, ans = high;

    while (high >= low) {
      int mid = (high - low) / 2 + low;
      if (works(personas, mid)) {
        low = mid + 1;
        ans = mid;
      } else {
        high = mid - 1;
      }
    }
    cout << ans << "\n";

    // int curr = n;
    // int seg = 0;
    // for (int i = 0; i < n; i++) {
    //   if (curr >= personas[i].personas) {
    //     seg = max(seg, personas[i].segundos);
    //   }
    //   curr--;
    // }

    // cout << seg << "\n";
  }
  return 0;
}
