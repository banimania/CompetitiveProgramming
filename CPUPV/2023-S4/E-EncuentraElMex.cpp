#include <iostream>
#include <algorithm>

int main(int argc, char** argv) {
	int n;
	std::cin >> n;
	
	int a[n];
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	std::sort(a, a + n, [](int a, int b) {
		return a < b;
	});
	
	int mex = 0;
	
	for (int i = 0; i < n; i++) {
		if (mex == a[i]) mex++;
		else break;
	}
	
	std::cout << mex << std::endl;
	
	return 0;
}
