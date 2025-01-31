#include <iostream>

int main() {
	int n, c;
	std::cin >> n >> c;
	std::cout << ((n % c == 0) ? "YES" : "NO");
	
	return 0;
}
