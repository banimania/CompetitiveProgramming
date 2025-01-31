#include <iostream>

int main() {
	std::string input;
	std::cin >> input;
	
	std::string hello = "hello";
	int correct = 0;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == hello[correct]) correct++;
	}
	
	std::cout << ((correct == hello.length()) ? "YES" : "NO") << std::endl;
	
	return 0;
}
