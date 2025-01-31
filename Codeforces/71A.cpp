//https://codeforces.com/problemset/problem/71/A

#include <iostream>
#include <string>
#include <vector>

int main() {

  int n;
  std::cin >> n;

  std::vector<std::string> results;

  for (int i = 0; i < n; i++) {
    std::string s;
    std::cin >> s;
    
    std::string result = s;

    if (s.length() > 10) {
      std::string substr = s.substr(1, s.length() - 2);
      result = s[0] + std::to_string(substr.length()) + s[s.length() - 1];
    }

    results.push_back(result);
  }

  for (std::string s : results) {
    std::cout << s << std::endl;
  }

  return 0;
}
