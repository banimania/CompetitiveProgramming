#include <bits/stdc++.h>
using namespace std;

int main() {
  string line;
  getline(cin, line);
  
  line = line.substr(1, line.size() - 2);
  
  set<char> s;
  
  for (int i = 0; i < line.size(); i++) {
    if (isalpha(line[i])) s.insert(line[i]);
  }
  cout << s.size() << endl;
  return 0;
}
