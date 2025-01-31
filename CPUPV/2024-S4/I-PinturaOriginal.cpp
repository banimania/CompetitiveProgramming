#include <iostream>

int main() {
	int n, m;
	std::cin >> n >> m;
	
	char a[n][m];
	
	bool original = true;
	for (int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;
		
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
		}
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (a[i][j] == a[i - 1][j] && a[i][j] == a[i][j - 1] && a[i][j] == a[i - 1][j - 1]) original = false;
			if (!original) break;
		}
		if (!original) break;
	}
	
	std::cout << (original ? "ORIGINAL" : "NO ORIGINAL");
	
	return 0;
}
