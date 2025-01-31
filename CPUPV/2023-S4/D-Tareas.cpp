#include <iostream>
#include <algorithm>

int main(int argc, char** argv) {
	int n, k;
	std::cin >> n >> k;
	
	int t[n];
	for (int i = 0; i < n; i++) {
		std::cin >> t[i];
	}
	
	std::sort(t, t + n, [](int a, int b) {
		return a < b;
	});
	
	std::cout << t[k - 1] << " " << t[k] << std::endl;
	
	return 0;
}
