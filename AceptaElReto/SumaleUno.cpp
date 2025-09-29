#include <bits/stdc++.h>
using namespace std;

void addDigit(int i, string &str) {
  if (i == -1) str = "1" + str;
  else {
    if (str[i] == 'F') {
      str[i] = '0';
      addDigit(i - 1, str);
    } else if (str[i] == 'E') {
      str[i] = 'F';
    } else if (str[i] == 'D') {
      str[i] = 'E';
    } else if (str[i] == 'C') {
      str[i] = 'D';
    } else if (str[i] == 'B') {
      str[i] = 'C';
    } else if (str[i] == 'A') {
      str[i] = 'B';
    } else if (str[i] == '9') {
      str[i] = 'A';
    } else if (str[i] == '8') {
      str[i] = '9';
    } else if (str[i] == '7') {
      str[i] = '8';
    } else if (str[i] == '6') {
      str[i] = '7';
    } else if (str[i] == '5') {
      str[i] = '6';
    } else if (str[i] == '4') {
      str[i] = '5';
    } else if (str[i] == '3') {
      str[i] = '4';
    } else if (str[i] == '2') {
      str[i] = '3';
    } else if (str[i] == '1') {
      str[i] = '2';
    } else if (str[i] == '0') {
      str[i] = '1';
    }
  }

}

int main() {
  string str;
  while (cin >> str && str != "FIN") {
    addDigit(str.size() - 1, str);
    cout << str << endl;
  }

  return 0;
}
