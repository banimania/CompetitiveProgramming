#include <iostream>

int main() {
	int n, m;
	std::cin >> n >> m;
	int clicks = 0;
	
	if (n > m) clicks = n - m;
	else if (n == m) clicks = 0;
	else while (m != n) {
		if (m % 2 != 0 || n > m) m++;
		else m /= 2;
		clicks++;
	}
	
	std::cout << clicks << std::endl;
	
	return 0;
}
