#include <iostream>
#include <iomanip>

int main() {
	int n, d;
	char o;
	std::cin >> n >> o >> d;
	
	int res = 0;
	if (o == '+') res = n + d;
	else if (o == '-') res = n - d;
	else if (o == '*') res = n * d;
	else if (o == '/') {
		if (d == 0) {
			std::cout << "ERROR";
			return 0;
		}
		std::cout << std::fixed << std::setprecision(2) << ((float) n / d);
		return 0;
	}
	
	std::cout << res;
	
	return 0;
}
