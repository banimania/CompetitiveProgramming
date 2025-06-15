#include <bits/stdc++.h>
using namespace std;

#define TESTCASES 1

void solve() {
  vector<map<char, int>> freqs;
  vector<string> words;
  string dicc, texto;
  getline(cin, dicc);
  getline(cin, texto);

  map<char, int> currFreq;
  string currWord = "";
  int cnt = 0;
  for (int i = 0; i < dicc.size(); i++) {
    if (dicc[i] == ' ') {
      freqs.push_back(currFreq);
      words.push_back(currWord);
      cnt++;
      currFreq.clear();

      currWord = "";
    } else {
      currFreq[dicc[i]]++;
      currWord += dicc[i];
    }
  }

  map<char, int> currFreqTex;
  currWord = "";
  for (int i = 0; i < texto.size(); i++) {
    if (texto[i] == ' ') {
      string actualWord = currWord;

      int matchings = 0;
      for (int j = 0; j < words.size(); j++) {
        bool eq = true;

        for (const pair<int, int> p : currFreqTex) {
          if (currFreqTex[p.first] != freqs[j][p.first]) {
            eq = false;
            break;
          }
        }
        for (const pair<int, int> p : freqs[j]) {
          if (currFreqTex[p.first] != freqs[j][p.first]) {
            eq = false;
            break;
          }
        }
        if (currWord[0] == words[j][0] && currWord[currWord.size() - 1] == words[j][words[j].size() - 1] && eq) {
          actualWord = words[j];
          matchings++;
        }
      }

      if (matchings > 1) actualWord = currWord;
      cout << actualWord << " ";
      currFreqTex.clear();
      currWord = "";
    } else {
      currFreqTex[texto[i]]++;
      currWord += texto[i];
    }
  }
  cout << "." << endl;

}

int main() {
  int t = 1;
  if (TESTCASES) cin >> t;
  cin.ignore();
  for (int i = 0; i < t; i++) solve();
  return 0;
}
