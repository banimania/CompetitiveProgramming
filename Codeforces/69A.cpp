#include <iostream>

int main() {
	int n;
	std::cin >> n;
	int sumX = 0, sumY = 0, sumZ = 0;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		std::cin >> x >> y >> z;
		sumX += x;
		sumY += y;
		sumZ += z;
	}
	
	std::cout << ((sumX == 0 && sumY == 0 && sumZ == 0) ? "YES" : "NO") << std::endl;
	return 0;
}
