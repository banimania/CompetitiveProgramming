#include <iostream>

int main() {
	int n, m;
	std::cin >> n >> m;
	
	int a[n][m];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> a[i][j];
		}
	}
	
	int v[m][n];
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			v[i][n - j - 1] = a[j][i];
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << v[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	return 0;
}
