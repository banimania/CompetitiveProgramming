#include <bits/stdc++.h>
using namespace std;

int main() {
  string line;
  while (getline(cin, line)) {
    if (line == "9999 ZZZ") break;

    int index = line.find(" ");

    int num = stoi(line.substr(0, index));
    string matr = line.substr(index + 1);

    num = (num + 1) % 10000;
    if (!num) {
      matr[2]++;
      if (matr[2] == 'A' || matr[2] == 'E' || matr[2] == 'I' || matr[2] == 'O' || matr[2] == 'U') matr[2]++;
      if (matr[2] > 'Z') {
        matr[2] = 'B';
        matr[1]++;
        if (matr[1] == 'A' || matr[1] == 'E' || matr[1] == 'I' || matr[1] == 'O' || matr[1] == 'U') matr[1]++;
        if (matr[1] > 'Z') {
          matr[1] = 'B';
          matr[0]++;
          if (matr[0] == 'A' || matr[0] == 'E' || matr[0] == 'I' || matr[0] == 'O' || matr[0] == 'U') matr[0]++;
        }
      }
    }

    cout << fixed << setw(4) << setfill('0') << num << " " << matr << endl;
  }
  return 0;
}
