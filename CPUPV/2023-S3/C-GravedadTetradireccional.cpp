#include <iostream>

int main() {
	int n, m;
	std::cin >> n >> m;
	
	char a[n][m];
	
	for (int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;
		
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		std::string line = "";
		for (int j = 0; j < m; j++) {
			bool gota = false;
			
			for (int k = 0; k < m && !gota; k++) {
				if (a[i][k] == '#') gota = true;
			}
			
			for (int k = 0; k < n && !gota; k++) {
				if (a[k][j] == '#') gota = true;
			}
			
			line += (gota ? '#' : '.');
		}
		
		std::cout << line << std::endl;
	}
	
	return 0;
}
