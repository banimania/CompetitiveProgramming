#include <bits/stdc++.h>
using namespace std;

bool vocal(char ch) {
  ch = tolower(ch);
  return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u');
}

int main() {
  string xpp;
  while (getline(cin, xpp)) {

    string xp(xpp.size(), ' ');

    int start = 0;
    int end = xp.size() - 1;

    for (int i = 0; i < xpp.size(); i++) {
      if (i % 2 == 0) {
        xp[start] = xpp[i];
        start++;
      } else {
        xp[end] = xpp[i];
        end--;
      }
    }

    for (int i = 0; i < xp.size() - 1; i++) {
      if (!vocal(xp[i])) {
        int j = i;
        while (j < xp.size() && !vocal(xp[j])) {
          j++;
        }

        reverse(xp.begin() + i, xp.begin() + j);

        i = j;
      }

    }
    cout << xpp << " => " << xp << endl;


  }
  return 0;
}
