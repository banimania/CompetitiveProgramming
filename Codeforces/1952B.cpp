#include <iostream>

int main() {
	int tt;
	std::cin >> tt;
	
	std::string sol[tt];
	for (int t = 0; t < tt; t++) {
		std::string input;
		std::cin >> input;
		
		bool found = false;
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == 'i' && input[i + 1] == 't') {
				sol[t] = "YES";
				found = true;
				break;
			} 
		}
		
		if (!found) sol[t] = "NO";
	}
	
	for (int i = 0; i < tt; i++) std::cout << sol[i] << std::endl;
	return 0;
}
