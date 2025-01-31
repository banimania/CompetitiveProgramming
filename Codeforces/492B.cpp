#include <iostream>
#include <algorithm>
#include <iomanip>
int main() {
	long long int n, l;
	std::cin >> n >> l;
	
	long long int a[n + 2];
	a[0] = 0;
	a[n + 1] = l;
	long long int max = 0, min = 0;
	for (long long int i = 1; i < n + 1; i++) std::cin >> a[i];
	
	std::sort(a, a + n + 2, [](long long int a, long long int b) { return a < b; });
	
	double d = std::max(a[1] - a[0], a[n + 1] - a[n]);
	for (long long int i = 1; i < n + 2; i++) {
		double diff = a[i] - a[i - 1];
		d = std::max(d, diff / 2.0f);
	}
	
	std::cout << std::fixed << std::setprecision(10) << d << std::endl;
	
	return 0;
}
