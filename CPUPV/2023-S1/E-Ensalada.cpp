#include <iostream>

int main() {
	long long a, t, n, precio;
	std::cin >> a >> t >> n;
	precio = (a * 5 + t * 7 + n * 13) - (n >= 1 ? 13 : 0) - (n == 0 && t >= 1 ? 7 : 0) - (n == 0 && t == 0 & n >= 1 ? 5 : 0);
	std::cout << precio;
	
	return 0;
}
