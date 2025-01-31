#include <iostream>
#include <iomanip>

int main() {
	int n;
	std::cin >> n;
	int h = (n / 60 + 12) % 24;
	int m = n % 60;
	std::cout << std::setw(2) << std::setfill('0') << h << ":" << std::setw(2) << std::setfill('0') << m;
	return 0;
}
