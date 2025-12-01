#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> instr;
unordered_map<string, unsigned short> cache;

unsigned short get_value(const string &wire) {
  if (isdigit(wire[0])) return stoi(wire);
  if (cache.count(wire)) return cache[wire];

  stringstream ss(instr[wire]);
  string token;
  ss >> token;

  unsigned short res;
  if (token == "NOT") {
    string a; ss >> a;
    res = ~get_value(a);
  } else {
    string a = token;
    if (!(ss >> token)) {
      res = get_value(a);
    } else {
      string op = token;
      string b; ss >> b;
      if (op == "AND") res = get_value(a) & get_value(b);
      else if (op == "OR") res = get_value(a) | get_value(b);
      else if (op == "LSHIFT") res = get_value(a) << stoi(b);
      else if (op == "RSHIFT") res = get_value(a) >> stoi(b);
    }
  }

  return cache[wire] = res;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  string line;
  while (getline(cin, line)) {
    auto pos = line.find(" -> ");
    string left = line.substr(0, pos);
    string right = line.substr(pos + 4);
    instr[right] = left;
  }

  cout << get_value("a") << endl;
}
