#include <iostream>

int main() {
	int n;
	std::cin >> n;
	
	for (int i = 0; i < (3 * n) + n + 1; i++) {
		std::string line = "";
		if (i % 4 == 0) {
			for (int j = 0; j < (3 * n) + n + 1; j++) {
				line += (j % 4 ? '-' : '+');
			}
		} else {
			for (int j = 0; j < (3 * n) + n + 1; j++) {
				line += (j % 4 ? ' ' : '|');
			}
		}
		
		std::cout << line << std::endl;
	}
	
	return 0;
}
