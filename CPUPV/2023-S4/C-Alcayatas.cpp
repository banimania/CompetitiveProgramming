#include <iostream>
#include <algorithm>

int main(int argc, char** argv) {
	int n;
	std::cin >> n;
	
	int a[n];
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	std::sort(a, a + n, [](int a, int b) {
		return a > b;
	});
	
	int minDistance = std::abs(a[1] - a[0]);
	
	for (int i = 1; i < n; i++) {
		minDistance = std::min(std::abs(a[i] - a[i - 1]), minDistance);
	}
	
	std::cout << minDistance << std::endl;
	
	return 0;
}
