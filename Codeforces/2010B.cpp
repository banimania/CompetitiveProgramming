#include <iostream>
int main(int argc, char** argv) {
	int a, b;
	std::cin >> a >> b;
	
	int missing = 3;
	if (a != 1 && b != 1) missing = 1;
	else if (a != 2 && b != 2) missing = 2;
	
	std::cout << missing << std::endl;
	return 0;
}
