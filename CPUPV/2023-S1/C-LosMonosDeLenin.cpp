#include <iostream>

int main() {
	int n1;
	std::cin >> n1;
	int ints[n1];
	for (int i = 0; i < n1; i++) {
		std::cin >> ints[i];
		ints[i] *= 2;
	}
	int n2;
	std::cin >> n2;
	char chars[n2];
	for (int i = 0; i < n2; i++) {
		std::cin >> chars[i];
		chars[i] = toupper(chars[i]);
	}
	int n3;
	std::cin >> n3;
	std::string strings[n3];
	for (int i = 0; i < n3; i++) {
		std::cin >> strings[i];
		for (int j = 0; j < strings[i].length(); j++) {
			char ch  = toupper(strings[i][j]);
			if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') strings[i][j] = '0';
		}
	}
	
	for (int i = 0; i < n1; i++) {
		std::cout << ints[i] << " ";
	}
	
	std::cout << std::endl;
	
	for (int i = 0; i < n2; i++) {
		std::cout << chars[i] << " ";
	}
	
	std::cout << std::endl;
	
	for (int i = 0; i < n3; i++) {
		std::cout << strings[i] << " ";
	}
	
	return 0;
}
