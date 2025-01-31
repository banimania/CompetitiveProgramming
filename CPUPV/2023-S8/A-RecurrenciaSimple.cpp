#include <iostream>

int main() {
	long long int n, a, b, c;
	std::cin >> n >> a >> b >> c;
	
	for (long long int i = 0; i < n; i++) {
		if (i == 0) std::cout << a << " ";
		else if (i == 1) std::cout << b << " ";
		else if (i == 2) std::cout << c << " ";
		else {
			long long int aux = c;
			c = c + b + a;
			a = b;
			b = aux;
			std::cout << c << " ";
		}
	}
	return 0;
}
