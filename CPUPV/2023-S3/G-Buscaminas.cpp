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
	
	char v[n][m];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char r = ' ';
			
			if (a[i][j] == '*') r = 'F';
			else {
				int num = 0;
				
				if (i - 1 >= 0 && a[i - 1][j] == '*') num++;
				if (j - 1 >= 0 && a[i][j - 1] == '*') num++;
				
				if (i + 1 < n && a[i + 1][j] == '*') num++;
				if (j + 1 < m && a[i][j + 1] == '*') num++;
				
				if (i - 1 >= 0 && j - 1 >= 0 && a[i - 1][j - 1] == '*') num++;
				if (i - 1 >= 0 && j + 1 < m && a[i - 1][j + 1] == '*') num++;
				if (i + 1 < n && j + 1 < m && a[i + 1][j + 1] == '*') num++;
				if (i + 1 < n && j - 1 >= 0 && a[i + 1][j - 1] == '*') num++;

				
				if (num == 0) r = ' ';
				else r = num + '0';
			}
			
			v[i][j] = r;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << v[i][j];
		}
		std::cout << std::endl;
	}
	
	
	return 0;
}
