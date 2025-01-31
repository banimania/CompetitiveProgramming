#include <iostream>
int main(int argc, char** argv) {
	int tt;
	std::cin >> tt;
	
	while (tt--) {
		int n;
		std::cin >> n;
		int a[n];
		
		int sum = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			sum += (i % 2 ? -a[i] : a[i]);
		}
		
		std::cout << sum << std::endl;
	}
	return 0;
}
