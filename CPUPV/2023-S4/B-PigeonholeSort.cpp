#include <iostream>
#include <algorithm>

int main(int argc, char** argv) {
	int n;
	std::cin >> n;
	
	int a[n];
	int min = 2147483647;
	int max = -2147483647;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		
		min = std::min(a[i], min);
		max = std::max(a[i], max);
	}
	
	int aux[max - min + 1] = { 0 };
	for (int i = 0; i < n; i++) {
		aux[a[i] - min]++;
	}
	
	int index = 0;
	for (int i = 0; i < max - min + 1; i++) {
		for (int j = 0; j < aux[i]; j++) {
			a[index] = i + min;
			index++;
		}
	}
	
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}
