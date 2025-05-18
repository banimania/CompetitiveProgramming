#include <bits/stdc++.h>
using namespace std;

struct TNode {
  map<string, TNode*> next;
  bool subseq = false;
};

struct Trie {
  TNode* root;

  Trie() {
    root = new TNode();
  }

  bool existsAtRoot(string word) {
    return root->next.count(word);
  }

  bool insertWord(string word) {
    if (root->next.count(word)) return false;

    TNode* node = new TNode();
    root->next[word] = node;
    root->next[word]->subseq = true;
    return true;
  }

  bool existsSubsequence(vector<string> &s, int l, int r) {
    int cnt = l;

    TNode* current = root;
    while (cnt <= r) {
      if (!current->next.count(s[cnt])) return false;

      current = current->next[s[cnt]];
      cnt++;
    }

    return true;
  }

  bool insert(const vector<string> &s, int l, int r) {
    TNode* node = root;
    bool isNew = false;
    for (int i = l; i <= r && i < s.size(); i++) {
      string word = s[i];
      if (!node->next.count(word)) {
        isNew = true;
        node->next[word] = new TNode();
      }
      node = node->next[word];
    }

    if (!node->subseq) {
      node->subseq = true;
      return true;
    }

    return false;
  }
};

void dfs(TNode* curr, int depth) {
  for (auto [palabra, nodo] : curr->next) {
    cout << palabra << "(" << depth << ")" << endl;
    dfs(nodo, depth + 1);
  } 
}

void learn(const int n, const vector<string> &seq, Trie &trie) {
  for (int len = 1; len <= n; len++) {
    for (int i = 0; i < (int) seq.size() - len + 1; i++) {
      int j = i + len - 1;

      trie.insert(seq, i, j);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  int tt = 1;
  while (cin >> n) {
    cout << "Learning case " << tt << endl;
    tt++;
    cin.ignore();
    vector<vector<string>> known, queries, queriesL;
    string currentWord;
    vector<string> currentSentence, currentSentenceL;
    string s;
    while (getline(cin, s) && s != "*") {
      for (int i = 0; i < s.size(); i++) s[i] = tolower(s[i]);
      stringstream ss(s);
      while (ss >> currentWord) {
        if (currentWord == "." || currentWord == "," || currentWord == ":" || currentWord == "?" || currentWord == "!") {
          known.push_back(currentSentence);
          currentSentence.clear();
        } else {
          currentSentence.push_back(currentWord);
        }
      }
    }
    if (!currentSentence.empty()) known.push_back(currentSentence), currentSentence.clear();

    while (getline(cin, s) && s != "#") {
      stringstream ss(s);
      while (ss >> currentWord) {
        if (currentWord == "." || currentWord == "," || currentWord == ":" || currentWord == "?" || currentWord == "!") {
          queries.push_back(currentSentence);
          queriesL.push_back(currentSentenceL);
          currentSentence.clear();
          currentSentenceL.clear();
        } else {
          string currentWordLowercase = currentWord;
          for (int i = 0; i < currentWordLowercase.size(); i++) currentWordLowercase[i] = tolower(currentWordLowercase[i]);
          currentSentence.push_back(currentWord);
          currentSentenceL.push_back(currentWordLowercase);
        }
      }
    }
    if (!currentSentence.empty()) {
      queries.push_back(currentSentence);
      currentSentence.clear();
    }
    if (!currentSentenceL.empty()) {
      queriesL.push_back(currentSentenceL);
      currentSentenceL.clear();
    }

    // cout << "Known: " << endl;
    // for (int i = 0; i < known.size(); i++) {
    //   for (int j = 0; j < known[i].size(); j++) {
    //     cout << known[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    // cout << "Queries: " << endl;
    // for (int i = 0; i < queriesL.size(); i++) {
    //   for (int j = 0; j < queriesL[i].size(); j++) {
    //     cout << queriesL[i][j] << " ";
    //   }
    //   cout << endl;
    // }


    Trie trie;
    trie.insertWord("joe");

    for (int o = 0; o < known.size(); o++) {
      // for (int len = 1; len <= n; len++) {
      //   for (int i = 0; i < known[o].size() - len + 1; i++) {
      //     int j = i + len - 1;

      //     trie.insert(known[o], i, j);
      //   }
      // }
      learn(n, known[o], trie);
    }

    for (int o = 0; o < queries.size(); o++) {
      for (int i = 0; i < queries[o].size(); i++) {
        if (!trie.root->next.count(queriesL[o][i])) {
          cout << "What does the word \"" << queries[o][i] << "\" mean?" << endl;

          trie.insertWord(queriesL[o][i]);
        }
      }

      bool finished = false;

      for (int len = 2; len <= n && !finished; len++) {
        for (int i = 0; i < (int) queriesL[o].size() - len + 1 && !finished; i++) {
          int j = i + len - 1;

          // cout << "checking " << len << " " << i << " " << j << endl;
          if (!trie.existsSubsequence(queriesL[o], i, j)) {
            finished = true;
            string sentence;
            for (int x = 0; x < queries[o].size(); x++) sentence += queries[o][x] + (x == queries[o].size() - 1 ? "" : " ");
            cout << "What does the sentence \"" << sentence << "\" mean?" << endl;

            learn(n, queriesL[o], trie);

            break;
          }
        }
      }
    }

    cout << endl;
  }

  return 0;
}
