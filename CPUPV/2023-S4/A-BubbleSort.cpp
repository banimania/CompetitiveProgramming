#include <iostream>

int main(int argc, char** argv) {
	int n;
	std::cin >> n;
	
	int a[n];
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j] > a[i]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}
