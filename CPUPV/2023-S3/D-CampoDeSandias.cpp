#include <iostream>
#include <algorithm>

int main() {
	int n, m;
	std::cin >> n >> m;
	
	int sandias[n][m];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> sandias[i][j];
		}
	}
	
	int maxFila = 0;
	int maxColumna = 0;
	
	for (int i = 0; i < n; i++) {
		int fila = 0;
		for (int j = 0; j < m; j++) {
			fila += sandias[i][j];
		}
		maxFila = std::max(fila, maxFila);
	}
	
	for (int j = 0; j < m; j++) {
		int columna = 0;
		for (int i = 0; i < n; i++) {
			columna += sandias[i][j];
		}
		maxColumna = std::max(columna, maxColumna);
	}
	
	std::cout << std::max(maxFila, maxColumna) << std::endl;
	
	return 0;
}
